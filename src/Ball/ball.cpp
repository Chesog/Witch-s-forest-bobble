#include <iostream>
#include "raylib.h"
#include "ball.h"

Ball::Ball(Vector2 pos, EntityType type, float speed, float points,float rad) : Entity (pos,type,speed,points)
{
	this->rad = rad;
	std::cout << "A New Ball Is Created" << std::endl;
}

Ball::~Ball()
{
	std::cout << "A Ball Was Destroyed" << std::endl;
}