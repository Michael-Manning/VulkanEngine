#pragma once

#include <vector>
#include <string>
#include <memory>
#include <stdint.h>
#include <unordered_map>
#include <string>
#include <utility>

#include <vulkan/vulkan.hpp>
#include <glm/glm.hpp>
#include <vk_mem_alloc.h>

#include "VKEngine.h"
#include "pipeline.h"
#include "typedefs.h"
#include "Constants.h"

constexpr int ColoredQuadPL_MAX_OBJECTS = 1000000;


class ColoredQuadPL :public  Pipeline {
public:

	struct InstanceBufferData {
		glm::vec4 color;
		alignas(8)glm::vec2 position;
		alignas(8)glm::vec2 scale;
		int circle;
		float rotation;

		int32_t padding[2];
	};
	static_assert(sizeof(InstanceBufferData) % 16 == 0);

	ColoredQuadPL(std::shared_ptr<VKEngine>& engine) : Pipeline(engine) {
	}

	//void CreateGraphicsPipeline(std::string vertexSrc, std::string fragmentSrc, MappedDoubleBuffer<void>& cameradb, bool flipFaces = false);
	void CreateGraphicsPipeline(const std::vector<uint8_t>& vertexSrc, const std::vector<uint8_t>& fragmentSrc, MappedDoubleBuffer<void>& cameradb, bool flipFaces = false);
	void CreateInstancingBuffer();
	void UploadInstanceData(std::vector<InstanceBufferData>& drawlist);
	void recordCommandBuffer(vk::CommandBuffer commandBuffer, int instanceCount);

private:
	MappedDoubleBuffer<void> ssboMappedDB;
};
