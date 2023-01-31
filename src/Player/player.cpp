#include <iostream>
#include "Player/player.h"
#include "raylib.h"

Player::Player(Vector2 pos, EntityType type, float speed, float points, float width, float height, int lifes) : Entity(pos, type, speed, points)
{
	this->pos = pos;
	this->type = type;
	this->speed = speed;
	this->points = points;
	rec.width = width;
	rec.height = height;
	this->lives = lifes;
	normalizedDirection = Vector2{0.0f,0.0f};
	rotation = 0.0f;



	std::cout << "A new Player was Created" << std::endl;
}
Player::~Player() 
{
	std::cout << "The Player was Destroyed" << std::endl;
}

void Player::SetRotation(float newRotation) 
{
	rotation = newRotation;
}

void Player::SetDirection(Vector2 newDirection)
{
	normalizedDirection = newDirection;
}

void Player::Draw() 
{
	DrawRectanglePro(rec,pos,rotation,GREEN);
}
void Player::Movement() 
{

}

float Player::GetRotation()
{
	return rotation;
}

float Player::GetXPosition()
{
	return pos.x;
}

float Player::GetYPosition()
{
	return pos.y;
}

Vector2 Player::GetDirection() 
{
	return normalizedDirection;
}

Vector2 Player::GetPosition() 
{
	return pos;
}

Rectangle Player::GetPlayerRect() 
{
	return rec;
}