#pragma once
#include "raylib.h"
#include "GlobalUtilities/globalUtilities.h"

class Entity
{
private:
	Vector2 pos;
	EntityType type;
	float speed;
	float points;
public:
	Entity(Vector2 pos,EntityType type,float speed,float points);
	virtual ~Entity();
	virtual void Draw() = 0;
	virtual void Movement() = 0;
	bool CheckColition(Entity* entity);

};