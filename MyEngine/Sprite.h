#pragma once

#include <stdint.h>
#include <glm/glm.hpp>
#include <string>
#include <nlohmann/json.hpp>
#include <fstream>

#include <assetPack/Sprite_generated.h>

#include "typedefs.h"
#include "serialization.h"


const auto Sprite_extension = ".sprite";


struct AtlasEntry {
	std::string name;
	glm::vec2 uv_min;
	glm::vec2 uv_max;

	static AtlasEntry deserializeJson(nlohmann::json j) {
		AtlasEntry entry;
		entry.name = j["name"];
		entry.uv_min = fromJson<glm::vec2>(j["uv_min"]);
		entry.uv_max = fromJson<glm::vec2>(j["uv_max"]);

		return entry;
	}
	static AtlasEntry deserializeFlatbuffer(const AssetPack::AtlasEntry* e) {
		AtlasEntry entry;
		entry.name = e->name()->str();
		entry.uv_min = fromAP(e->uv_min());
		entry.uv_max = fromAP(e->uv_max());

		return entry;
	};
};

class Sprite {

public:

	std::string name;

	spriteID ID;

	texID textureID;
	glm::vec2 resolution;

	std::string imageFileName;

	std::vector<AtlasEntry> atlas;

	FilterMode filterMode;

	void serializeJson(std::string filepath) {
		nlohmann::json j;

		j["ID"] = ID;
		j["name"] = name;
		j["textureID"] = textureID;
		j["resolution"] = toJson(resolution);
		j["imageFileName"] = imageFileName;
		j["filterMode"] = static_cast<uint32_t>(filterMode);


		std::ofstream output(filepath);
		output << j.dump(4) << std::endl;
		output.close();
	}

	static std::shared_ptr<Sprite> deserializeJson(std::string filepath) {
		std::ifstream input(filepath);

		nlohmann::json j;
		input >> j;

		auto sprite = std::make_shared<Sprite>();

		sprite->ID = j["ID"];
		sprite->name = j["name"];
		sprite->textureID = j["textureID"];

		sprite->resolution = fromJson<glm::vec2>(j["resolution"]);
		sprite->imageFileName = j["imageFileName"];
		sprite->filterMode = static_cast<FilterMode>(j["filterMode"]);

		if (j.contains("atlas")) {
			for (auto& i : j["atlas"]) {
				sprite->atlas.push_back(AtlasEntry::deserializeJson(i));
			}
		}

		// gen atlas via grid definition
		else if (j.contains("atlasLayout")) {
			nlohmann::json jb = j["atlasLayout"];
			int xcount = jb["xCount"];
			int ycount = jb["yCount"];

			float uvw = 1.0f / xcount;
			float uvh = 1.0f / ycount;
			for (size_t i = 0; i < ycount; i++) {
				for (size_t j = 0; j < xcount; j++) {
					AtlasEntry entry;
					entry.name = std::to_string((int)(i + j * xcount));
					entry.uv_min = glm::vec2(j * uvw, i * uvh);
					entry.uv_max = entry.uv_min + glm::vec2(uvw, uvh);
					sprite->atlas.push_back(entry);
				}
			}
		}

		return sprite;
	}

	static std::shared_ptr<Sprite> deserializeFlatbuffer(const AssetPack::Sprite* s) {
		auto sprite = std::make_shared<Sprite>();
		sprite->ID = s->ID();
		sprite->name = s->name()->str();
		sprite->textureID = s->textureID();
		sprite->resolution = fromAP(s->resolution());
		sprite->imageFileName = s->imageFileName()->str();
		sprite->filterMode = static_cast<FilterMode>(s->filterMode());

		if (s->atlas() != nullptr) {
			sprite->atlas.resize(s->atlas()->size());
			for (size_t i = 0; i < s->atlas()->size(); i++)
				sprite->atlas[i] = AtlasEntry::deserializeFlatbuffer(s->atlas()->Get(i));
		}

		if (sprite->atlas.size() > 0)
			return sprite;

		auto gridLayout = s->atlasLayout();
		if (gridLayout != nullptr) {
			int xcount = gridLayout->xCount();
			int ycount = gridLayout->yCount();

			float uvw = 1.0f / xcount;
			float uvh = 1.0f / ycount;
			for (size_t i = 0; i < ycount; i++) {
				for (size_t j = 0; j < xcount; j++) {
					AtlasEntry entry;
					entry.name = std::to_string((int)(i + j * xcount));
					entry.uv_min = glm::vec2(j * uvw, i * uvh);
					entry.uv_max = entry.uv_min + glm::vec2(uvw, uvh);
					sprite->atlas.push_back(entry);
				}
			}
		}
		return sprite;
	}
};

