#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

#include <vulkan/vulkan.h>
#include <glm/glm.hpp>

#include <vk_mem_alloc.h>

#include "texture.h"
#include "VKEngine.h"


class Pipeline {
public:

	Pipeline(std::shared_ptr<VKEngine> engine) : engine(engine) {
	}

protected:

	// for each frame in flight
	std::array<VkDescriptorSet, FRAMES_IN_FLIGHT> generalDescriptorSets;


	std::shared_ptr<VKEngine> engine = nullptr;

	VkPipeline _pipeline;
	VkPipelineLayout pipelineLayout;

	

	// for builder
	struct descriptorSetInfo {
		int set;
		int binding;
		VkDescriptorType type;
		VkShaderStageFlags stageFlags;
		std::array<VkBuffer, FRAMES_IN_FLIGHT> * doubleBuffer = nullptr;
		VkDeviceSize bufferRange = 0;
		Texture * textures= nullptr;
		int textureCount = 0;


		descriptorSetInfo(int set, int binding, VkDescriptorType type, VkShaderStageFlags stageFlags, std::array<VkBuffer, FRAMES_IN_FLIGHT>* db, VkDeviceSize bufferRange)
			: set(set), binding(binding), type(type), stageFlags(stageFlags), doubleBuffer(db), bufferRange(bufferRange),  textures(nullptr) {
		};
		descriptorSetInfo(int set, int binding, VkDescriptorType type, VkShaderStageFlags stageFlags, Texture* texture, int textureCount)
			: set(set), binding(binding), type(type), stageFlags(stageFlags), doubleBuffer(nullptr), bufferRange(0), textures(texture), textureCount(textureCount) {
		};
	};
	
	// set number to layout
	std::unordered_map<int, VkDescriptorSetLayout> builderLayouts;
	std::unordered_map<int, std::array<VkDescriptorSet, FRAMES_IN_FLIGHT>> builderDescriptorSets;
	
	std::vector<descriptorSetInfo> builderDescriptorSetsDetails;

	void configureDescriptorSets(std::vector< descriptorSetInfo> layoutDetails) {
		builderDescriptorSetsDetails = layoutDetails;
	};

	void buildDescriptorLayouts();
	void buildDescriptorSets();
	void updateDescriptorSet(int frame, descriptorSetInfo& info);

	//std::vector<VkPipelineShaderStageCreateInfo> createShaderStages(std::string vertexSrc, std::string fragmentSrc);
	std::vector<VkPipelineShaderStageCreateInfo> createShaderStages(const std::vector<uint8_t>& vertexSrc, const std::vector<uint8_t>& fragmentSrc);
	VkPipelineShaderStageCreateInfo createComputeShaderStage(const std::vector<uint8_t>& computeSrc);
	//VkPipelineShaderStageCreateInfo createComputeShaderStage(std::string computeSrc);

	VkPipelineInputAssemblyStateCreateInfo defaultInputAssembly();
	VkPipelineViewportStateCreateInfo defaultViewportState();
	VkPipelineRasterizationStateCreateInfo defaultRasterizer();
	VkPipelineMultisampleStateCreateInfo defaultMultisampling();
	VkPipelineColorBlendAttachmentState defaultColorBlendAttachment(bool blendEnabled);
	VkPipelineColorBlendStateCreateInfo defaultColorBlending(VkPipelineColorBlendAttachmentState *attachment);
	VkPipelineDynamicStateCreateInfo defaultDynamicState();

	std::vector<VkDynamicState> defaultDynamicStates = {
		VK_DYNAMIC_STATE_VIEWPORT,
		VK_DYNAMIC_STATE_SCISSOR
	};

	inline VkViewport fullframeViewport() {
		VkViewport viewport{};
		viewport.x = 0.0f;
		viewport.y = 0.0f;
		viewport.width = (float)engine->swapChainExtent.width;
		viewport.height = (float)engine->swapChainExtent.height;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;
		return viewport;
	};

	VkDescriptorSetLayoutBinding buildSamplerBinding(int binding, int descriptorCount, VkShaderStageFlags stageFlags);
	VkDescriptorSetLayoutBinding buildUBOBinding(int binding, VkShaderStageFlags stageFlags);
	VkDescriptorSetLayoutBinding buildSSBOBinding(int binding, VkShaderStageFlags stageFlags);
	void buildSetLayout(std::vector<VkDescriptorSetLayoutBinding>& bindings, VkDescriptorSetLayout& layout);

	void buildPipelineLayout(std::vector<VkDescriptorSetLayout>& descriptorSetLayouts, uint32_t pushConstantSize = 0, VkShaderStageFlags pushConstantStages = 0);

	void buidDBDescriptorSet(VkDescriptorSetLayout& layout, std::array<VkDescriptorSet, FRAMES_IN_FLIGHT>& sets);
};
