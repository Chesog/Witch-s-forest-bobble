#include <iostream>
#include "entity.h"

Entity::Entity(Vector2 pos, EntityType type, float speed, float points) 
{
	this->pos = pos;
	this->type = type;
	this->speed = speed;
	this->points = points;

	std::cout << "New Entity Created" << std::endl;
}
Entity::~Entity() 
{
	std::cout << "Entity Destroyed" << std::endl;
}
//bool Entity::CheckColition(Entity* entity) 
//{
//	return true;
//}