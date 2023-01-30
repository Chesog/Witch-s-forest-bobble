#pragma once
#include "Entity/entity.h"

class Player : public Entity
{
private:
	float width;
	float height;
	float lifes;
public:
	Player(Vector2 pos, EntityType type, float speed, float points, float width,float height,float lifes) : Entity(pos, type, speed, points);
	~Player();
	void Draw() override;
	void Movement() override;
};