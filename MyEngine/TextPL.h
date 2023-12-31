#pragma once

#include <vector>
#include <string>
#include <memory>
#include <stdint.h>
#include <unordered_map>
#include <set>
#include <string>
#include <utility>

#include <vulkan/vulkan.hpp>
#include <glm/glm.hpp>

#include <vk_mem_alloc.h>

#include "texture.h"
#include "VKEngine.h"
#include "pipeline.h"
#include "typedefs.h"
#include "Constants.h"
#include "Font.h"
#include "vulkan_util.h"
#include "BindingManager.h"
#include "globalBufferDefinitions.h"


constexpr int TEXTPL_maxFonts = 10;
constexpr int TEXTPL_maxTextObjects = 10;
constexpr int TEXTPL_maxTextLength = 128;

class TextPL :public  Pipeline {
public:

	struct textObject {
		charQuad quads[TEXTPL_maxTextLength];
	};
	static_assert(sizeof(textObject) % 16 == 0);

	struct textHeader {
		glm::vec4 color;
		alignas(8) glm::vec2 position;
		alignas(8) glm::vec2 scale;
		float rotation;
		int _textureIndex;
		int textLength;

		uint32_t padding[1];
	};
	static_assert(sizeof(textHeader) % 16 == 0);

	TextPL(std::shared_ptr<VKEngine>& engine, Texture defaultTexture) :
		bindingManager(TEXTPL_maxFonts), 
		defaultTexture(defaultTexture),
		Pipeline(engine) {
	}

	void CreateGraphicsPipeline(const std::vector<uint8_t>& vertexSrc, const std::vector<uint8_t>& fragmentSrc, MappedDoubleBuffer<>& cameradb, bool flipFaces = false);
	//void CreateGraphicsPipeline(std::string vertexSrc, std::string fragmentSrc, MappedDoubleBuffer<>& cameradb, bool flipFaces = false);
	void createSSBOBuffer();
	void recordCommandBuffer(vk::CommandBuffer commandBuffer);

	void updateDescriptorSets();

	void addFontBinding(fontID ID, Texture* texture) {
		bindingManager.AddBinding(ID, texture);
	};
	void removeTextureBinding(fontID ID) {
		bindingManager.RemoveBinding(ID);
	};
	void InvalidateTextureDescriptors() {
		bindingManager.InvalidateDescriptors();
	};

	void ClearTextData(int frame) {
		for (size_t i = 0; i < TEXTPL_maxTextObjects; i++)
			textDataDB.buffersMapped[frame]->headers[i].textLength = 0;
	}

	// TODO replace with function to get pointers to a given memory slot for direct memory access to avoid copy
	void UploadTextData(int frame, int memorySlot, textHeader& header, fontID font, textObject& text) {

		header._textureIndex = bindingManager.getIndexFromBinding(font);

		// transfers memory to GPU 
		textDataDB.buffersMapped[frame]->headers[memorySlot] = header;
		textDataDB.buffersMapped[frame]->textData[memorySlot] = text;
	};

private:

	struct textIndexes_ssbo {
		textHeader headers[TEXTPL_maxTextObjects];
		textObject textData[TEXTPL_maxTextObjects];
	};

	MappedDoubleBuffer<textIndexes_ssbo> textDataDB;

	BindingManager<fontID, Texture*> bindingManager;

	Texture defaultTexture;
};
