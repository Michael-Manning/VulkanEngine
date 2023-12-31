#pragma once

#include <stdint.h>
#include <glm/glm.hpp>
#include <string>
#include <typeinfo>
#include <memory>
#include <iostream>

#include "typedefs.h"
#include "ECS.h"
#include "global.h"
#include "worldGen.h"
#include "TileWorld.h"
#include "Player.h"

using namespace glm;
using namespace std;


class Demon : public Entity {


public:
	std::string GetEditorName() override { // deprecate
		return "Demon";
	};

	uint32_t getBehaviorHash() override {
		return cHash("Demon");
	};


	// settings
	const float groundAccel = 10.0f;
	const float airAccel = 7.0f;
	const float topMoveSpeed = 3.0f; // max speed achieved through self movement
	const float terminalVelocity = 12.0f; // maximum speed achieved through gravity acceleration
	const float idleDecelleratiom = 45.0f;
	const float gravityAccel = 18;
	const float jumpVel = 6;
	const float skin = 0.01f;

	// variables
	vec2 velocity = vec2(0.0f);
	float grounded = true;


	std::shared_ptr<Player> playerRef;
	void setPlayerRef(std::shared_ptr<Player> playerRef) {
		this->playerRef = playerRef;
	}


	bool queryTile(vec2 pos) {
		int tileX = pos.x / tileWorldSize + mapW / 2;
		int tileY = pos.y / tileWorldSize + mapH / 2;

		if (tileX > 0 && tileX < mapW && tileY > 0 && tileY < mapH) {

			tileY = mapH - tileY - 1;

			blockID block = tileWolrdGlobalRef->getTile(tileX, tileY);

			return block != Tiles::Air;
		}
		return false;
	}

	bool queryTile(ivec2 coord) {
		return tileWolrdGlobalRef->getTile(coord.x, coord.y);
	}

	ivec2 getTileXY(vec2 pos) {
		int tileX = pos.x / tileWorldSize + mapW / 2;
		int tileY = pos.y / tileWorldSize + mapH / 2;

		if (tileX > 0 && tileX < mapW && tileY > 0 && tileY < mapH)
			return ivec2(tileX, mapH - tileY - 1);
		return ivec2(-1, -1);
	}

	//SpriteRenderer* renderer;

	vector<vec2> tpoints;
	float sx = 0;
	float sy = 0;
	void Start() override {

		//renderer = getComponent<SpriteRenderer>();
		//renderer->atlasIndex = 5;

		tpoints.resize(10);
		float sx = transform.scale.x / 2.0;
		float sy = transform.scale.y / 2.0;
		tpoints[0] = vec2(sx, sy);
		tpoints[1] = vec2(-sx, sy);
		tpoints[2] = vec2(sx, -sy);
		tpoints[3] = vec2(-sx, -sy);
		tpoints[4] = vec2(-sx, sy / 2.0f);
		tpoints[5] = vec2(sx, sy / 2.0f);
		tpoints[6] = vec2(0, -sy);
		tpoints[7] = vec2(0, sy);
		tpoints[8] = vec2(-sx, -sy / 2.0f);
		tpoints[9] = vec2(sx, -sy / 2.0f);
	};

	float animationTimer = 0;

	void Update() override {

		bool leftCast = false;
		bool rightCast = false;
		bool topCast = false;
		bool bottomCast = false;

		leftCast |= queryTile(transform.position + tpoints[1] + vec2(-skin * 2, 0));
		leftCast |= queryTile(transform.position + tpoints[3] + vec2(-skin * 2, 0));
		leftCast |= queryTile(transform.position + tpoints[4] + vec2(-skin * 2, 0));
		leftCast |= queryTile(transform.position + tpoints[8] + vec2(-skin * 2, 0));

		rightCast |= queryTile(transform.position + tpoints[0] + vec2(skin * 2, 0));
		rightCast |= queryTile(transform.position + tpoints[2] + vec2(skin * 2, 0));
		rightCast |= queryTile(transform.position + tpoints[5] + vec2(skin * 2, 0));
		rightCast |= queryTile(transform.position + tpoints[9] + vec2(skin * 2, 0));

		topCast |= queryTile(transform.position + tpoints[0] + vec2(0, skin * 2));
		topCast |= queryTile(transform.position + tpoints[1] + vec2(0, skin * 2));
		topCast |= queryTile(transform.position + tpoints[7] + vec2(0, skin * 2));

		bottomCast |= queryTile(transform.position + tpoints[2] + vec2(0, -skin * 2));
		bottomCast |= queryTile(transform.position + tpoints[3] + vec2(0, -skin * 2));
		bottomCast |= queryTile(transform.position + tpoints[6] + vec2(0, -skin * 2));

		animationTimer += DeltaTime;
		if (animationTimer > 0.1f)
			animationTimer = 0.0f;

		//left and right movement
		bool left, right;
		if (transform.position.x < playerRef->transform.position.x) {
			right = true;
			left = false;
		}
		else {
			right = false;
			left = true;
		}



		if (left && !right && !leftCast) {
			velocity += vec2(grounded ? -groundAccel : -airAccel, 0.0f) * DeltaTime;
		}
		else if (!left && right && !rightCast) {
			velocity += vec2(grounded ? groundAccel : airAccel, 0.0f) * DeltaTime;
		}
		else if (!left && !right) {
			if (grounded) {
				if (velocity.x)
					velocity = decellerate(velocity, vec2(idleDecelleratiom * DeltaTime, 0.0f));
			}
		}

		if ((leftCast || rightCast) && grounded) {
			velocity.y = jumpVel;
			grounded = false;

		}
		else if (!bottomCast) {
			velocity.y -= gravityAccel * DeltaTime;
		}

		//if (!bottomCast) {
		//	velocity.y -= gravityAccel * DeltaTime;
		//}

		//if (grounded) {

		//	if (left && !right && !leftCast) {
		//		renderer->atlasIndex = animationTimer > 0.05 ? 1 : 2;
		//	}
		//	else if (!left && right && !rightCast) {
		//		renderer->atlasIndex = animationTimer > 0.05 ? 3 : 4;
		//	}
		//	else {
		//		renderer->atlasIndex = 5;
		//	}
		//}
		//else {
		//	renderer->atlasIndex = 0;
		//}


		velocity.x = glm::clamp(velocity.x, -topMoveSpeed, topMoveSpeed);
		velocity.y = glm::clamp(velocity.y, -terminalVelocity, terminalVelocity);


		vec2 npos = transform.position + velocity * DeltaTime;

		float resolvedXAvg = 0.0f;
		int avgSamplesX = 0;

		float resolvedYAvg = 0.0f;
		int avgSamplesY = 0;


		float slope = 0;

		float x1 = transform.position.x;
		float y1 = transform.position.y;
		float x2 = npos.x;
		float y2 = npos.y;

		if (x2 != x1) {
			slope = (y2 - y1) / (x2 - x1);
		}

		for (size_t i = 0; i < tpoints.size(); i++) {

			if (queryTile(npos + tpoints[i]) == false)
				continue;


			bool resolveLeft = false;
			bool resolveRight = false;
			bool resolveUp = false;
			bool resolveDown = false;

			volatile ivec2 prevTile = getTileXY(transform.position + tpoints[i]);
			volatile ivec2 curTile = getTileXY(npos + tpoints[i]);

			int dx = curTile.x - prevTile.x;
			int dy = -(curTile.y - prevTile.y);


			// test points on edge should be able to skip corner calculations if moving < 1 tile/fram

			if (i > 3) {
				if (i == 4 || i == 8)
					resolveRight = true;
				else if (i == 5 || i == 9)
					resolveLeft = true;
				else if (i == 6)
					resolveUp = true;
				else if (i == 7)
					resolveDown = true;
			}
			else if (dx != 0 && dy == 0) {

				if (dx > 0)
					resolveLeft = true;
				else
					resolveRight = true;
			}
			else if (dy != 0 && dx == 0) {
				if (dy > 0)
					resolveDown = true;
				else
					resolveUp = true;
			}
			else {
				if (dy == 0 && dx == 0) {
					continue;
				}
				assert(dy != 0 || dx != 0);
				assert(slope != 0);

				float left_x = (curTile.x - mapW / 2) * tileWorldSize - sx;
				float right_x = left_x + tileWorldSize;
				float bottom_y = (mapH / 2 - curTile.y - 1) * tileWorldSize - sy;
				float top_y = bottom_y + tileWorldSize;

				float left_y = slope * (left_x - x1) + y1;
				float right_y = slope * (right_x - x1) + y1;
				float bottom_x = (bottom_y - y1) / slope + x1;
				float top_x = (top_y - y1) / slope + x1;

				bool left_edge = dx == 1 && (bottom_y <= left_y && left_y <= top_y);
				bool right_edge = dx == -1 && (bottom_y <= right_y && right_y <= top_y);
				bool bottom_edge = dy == 1 && (left_x <= bottom_x && bottom_x <= right_x);
				bool top_edge = dy == -1 && (left_x <= top_x && top_x <= right_x);

				if (right_edge) {
					if (queryTile(ivec2(curTile.x + 1, curTile.y))) {
						if (dy < 0)
							resolveUp = true;
						else
							resolveDown = true;
					}
					else
						resolveRight = true;
				}
				else if (left_edge) {
					if (queryTile(ivec2(curTile.x - 1, curTile.y))) {
						if (dy < 0)
							resolveUp = true;
						else
							resolveDown = true;
					}
					else
						resolveLeft = true;
				}
				else if (bottom_edge) {
					if (queryTile(ivec2(curTile.x, curTile.y + 1))) {
						if (dx < 0)
							resolveRight = true;
						else
							resolveLeft = true;
					}
					else
						resolveDown = true;
				}
				else if (top_edge) {
					if (queryTile(ivec2(curTile.x, curTile.y - 1))) {
						if (dx < 0)
							resolveRight = true;
						else
							resolveLeft = true;
					}
					else
						resolveUp = true;
				}
			}

			if (resolveUp) {
				resolvedYAvg += (mapH / 2 - curTile.y) * tileWorldSize - tpoints[i].y + skin;
				avgSamplesY++;
				velocity.y = 0;
				grounded = true;
			}
			else if (resolveLeft) {
				resolvedXAvg += (curTile.x - mapW / 2) * tileWorldSize - tpoints[i].x - skin;
				avgSamplesX++;
				velocity.x = 0;
			}
			else if (resolveRight) {
				resolvedXAvg += (curTile.x - mapW / 2 + 1) * tileWorldSize - tpoints[i].x + skin;
				avgSamplesX++;
				velocity.x = 0;
			}
			else if (resolveDown) {
				resolvedYAvg += (mapH / 2 - curTile.y - 1) * tileWorldSize - tpoints[i].y - skin;
				avgSamplesY++;
				velocity.y = 0;
			}
		}

		if (avgSamplesX > 0)
			npos.x = resolvedXAvg / (float)avgSamplesX;
		if (avgSamplesY > 0)
			npos.y = resolvedYAvg / (float)avgSamplesY;

		transform.position = npos;

		if (transform.position != GcameraPos) {
			vec2 npos = GcameraPos + (transform.position - GcameraPos) * 4.0f * DeltaTime;
			if (glm::distance(npos, transform.position) > glm::distance(GcameraPos, transform.position)) {
				GcameraPos = transform.position;
			}
			else {
				GcameraPos = npos;
			}
		}
	};
};


