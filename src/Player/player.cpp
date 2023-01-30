#include <iostream>
#include "Player/player.h"
#include "raylib.h"

Player::Player(Vector2 pos, EntityType type, float speed, float points, float width, float height, float lifes) : Entity(pos, type, speed, points)
{
	this->pos = pos;
	this->type = type;
	this->speed = speed;
	this->points = points;
	this->width = width;
	this->height = height;
	this->lives = lifes;


	std::cout << "A new Player was Created" << std::endl;
}
Player::~Player() 
{
	std::cout << "The Player was Destroyed" << std::endl;
}
void Player::Draw() 
{

}
void Player::Movement() 
{

}