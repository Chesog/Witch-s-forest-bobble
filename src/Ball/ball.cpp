#include <iostream>
#include "raylib.h"
#include "ball.h"

Ball::Ball(Vector2 pos,Vector2 trajectory, EntityType type, float speed, float points,float rad, Color ballColor) : Entity (pos,type,speed,points)
{
	this->pos = pos;
	this->type = type;
	this->speed.x = speed;
	this->speed.y = speed;
	this->points = points;
	this->rad = rad;
	this->ballColor = ballColor;
	this->trajectory = trajectory;
	currentDirection = Directions::Stop;
	std::cout << "A New Ball Is Created" << std::endl;
}

Ball::~Ball()
{
	std::cout << "A Ball Was Destroyed" << std::endl;
}
void Ball::Draw() 
{
	DrawCircle(static_cast<int>(pos.x),static_cast<int>(pos.y),rad,ballColor);
}
void Ball::Movement() 
{
	pos.x = pos.x + trajectory.x * speed.x * GetFrameTime();
	pos.y = pos.y + trajectory.y * speed.y * GetFrameTime();
}

Vector2 Ball::GetTrajectory() 
{
	return trajectory;
}

void Ball::SetTrajectoy(Vector2 trajectory)
{
	this->trajectory = trajectory;
}

void Ball::SetDirection(Directions newDirection)
{
	currentDirection = newDirection;
}

float Ball::GetRad() 
{
	return rad;
}

Vector2 Ball::GetPos() 
{
	return pos;
}

Directions Ball::GetDirection() 
{
	return currentDirection;
}