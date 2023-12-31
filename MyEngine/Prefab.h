#pragma once

#include <optional>
#include <string>
#include <fstream>
#include <memory>

#include <glm/glm.hpp>
#include <nlohmann/json.hpp>

#include "ECS.h"
#include "serialization.h"
#include <box2d/box2d.h>

#include <assetPack/Prefab_generated.h>

const auto Prefab_extension = ".prefab";

class Prefab {
public:

	std::string name;

	uint32_t behaviorHash;
	Transform transform;

	// replace these with list of component base class?
	std::optional<ColorRenderer> colorRenderer;
	std::optional<SpriteRenderer> spriteRenderer;
	std::optional<TextRenderer> textRenderer;
	std::optional<Rigidbody> rigidbody;
	std::optional<Staticbody> staticbody;

	// use .prefab extension
	void serializeJson(std::string filepath) {
		nlohmann::json ja;
		nlohmann::json j;


		j["behaviorHash"] = behaviorHash;

		j["name"] = name;

		transform.position = glm::vec2(0.0f);
		j["transform"] = transform.serializeJson();

		if (colorRenderer.has_value())
			j["colorRenderer"] = colorRenderer.value().serializeJson(0);
		if (spriteRenderer.has_value())
			j["spriteRenderer"] = spriteRenderer.value().serializeJson(0);
		if (textRenderer.has_value())
			j["textRenderer"] = textRenderer.value().serializeJson(0);
		if (rigidbody.has_value())
			j["rigidbody"] = rigidbody.value().serializeJson(0);
		if (staticbody.has_value())
			j["staticbody"] = staticbody.value().serializeJson(0);

		std::ofstream output(filepath);
		output << j.dump(4) << std::endl;
		output.close();
	};

	static std::string peakJsonName(std::string filepath) {
		std::ifstream input(filepath);
		nlohmann::json j;
		input >> j;

		return static_cast<std::string>(j["name"]);
	}

	static Prefab deserializeJson(std::string filepath, std::shared_ptr<b2World> world ) {
		std::ifstream input(filepath);	
		nlohmann::json j;
		input >> j;

		Prefab p;

		p.behaviorHash = j["behaviorHash"];
		p.transform = Transform::deserializeJson(j["transform"]);
		p.name = j["name"];

		if (j.contains("colorRenderer"))
			p.colorRenderer = ColorRenderer::deserializeJson(j["colorRenderer"]);
		if (j.contains("spriteRenderer"))
			p.spriteRenderer = SpriteRenderer::deserializeJson(j["spriteRenderer"]);
		if (j.contains("textRenderer"))
			p.textRenderer = TextRenderer::deserializeJson(j["textRenderer"]);
		if (j.contains("rigidbody"))
			p.rigidbody = Rigidbody::deserializeJson(j["rigidbody"], world);
		if (j.contains("staticbody"))
			p.staticbody = Staticbody::deserializeJson(j["staticbody"], world);

		return p;
	}

	static Prefab deserializeFlatbuffer(const AssetPack::Prefab * p, std::shared_ptr<b2World> world) {
		Prefab prefab;
		prefab.name = p->name()->str();
		prefab.behaviorHash = p->behaviorHash();
		prefab.transform = Transform::deserializeFlatbuffers(p->transform());
		
		auto colorRenderer = p->colorRenderer();
		auto spriteRenderer = p->spriteRenderer();
		auto textRenderer = p->textRenderer();
		auto rigidbody = p->rigidbody();
		auto staticbody = p->staticbody();

		if (colorRenderer != nullptr)
			prefab.colorRenderer = ColorRenderer::deserializeFlatbuffers(colorRenderer);
		if (spriteRenderer != nullptr)
			prefab.spriteRenderer = SpriteRenderer::deserializeFlatbuffers(spriteRenderer);
		if (textRenderer != nullptr)
			prefab.textRenderer = TextRenderer::deserializeFlatbuffers(textRenderer);
		if (rigidbody != nullptr)
			prefab.rigidbody = Rigidbody::deserializeFlatbuffers(rigidbody, world);
		if (staticbody != nullptr)
			prefab.staticbody = Staticbody::deserializeFlatbuffers(staticbody, world);

		return prefab;
	}
};