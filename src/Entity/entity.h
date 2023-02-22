#pragma once
#include <iostream>
#include "raylib.h"
#include "GlobalUtilities/globalUtilities.h"

class Entity
{
protected:
	float points;
	Vector2 pos;
	Vector2 speed;
	EntityType type;
public:
	Entity(Vector2 pos,EntityType type,float speed,float points);
	virtual ~Entity();
	virtual void Draw() = 0;
	virtual void Movement() = 0;
	bool CheckColition(Entity* entity);

};