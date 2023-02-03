#include <iostream>
#include "raylib.h"
#include "hud.h"

Hud::Hud(Player* player, vector<Ball*> gameBalls)
{
	this->player = player;
	//this->gameBalls = gameBalls;

	float sideWallsWidht = 20;
	float sideWallsHeight = GetScreenHeight();

	float leftWallX = static_cast<float>(GetScreenWidth() / 3 - (sideWallsWidht / 2));
	float rightWallX = leftWallX * 2;
	float sideWallsY = 0.0f;

	float topWallWidht = rightWallX - leftWallX;
	float topWallHeight = 20;

	float topWallX = leftWallX;
	float topWallY = 0.0f;
	
	this->leftWall.width = sideWallsWidht;
	this->leftWall.height = sideWallsHeight;
	this->leftWall.x = leftWallX;
	this->leftWall.y = sideWallsY;

	this->rightWall.width = sideWallsWidht;
	this->rightWall.height = sideWallsHeight;
	this->rightWall.x = rightWallX;
	this->rightWall.y = sideWallsY;

	this->topWall.width = topWallWidht;
	this->topWall.height = topWallHeight;
	this->topWall.x = topWallX;
	this->topWall.y = topWallY;


	cout << "The HUD was Created" << endl;
}

Hud::~Hud() 
{
	cout << "The HUD was send to oblivion" << endl;
}

void Hud::Draw() 
{
	DrawRectangle(static_cast<int>(leftWall.x), static_cast<int>(leftWall.y), static_cast<int>(leftWall.width), leftWall.height,RAYWHITE);
	DrawRectangle(static_cast<int>(rightWall.x), static_cast<int>(rightWall.y), static_cast<int>(rightWall.width), rightWall.height, RAYWHITE);
	DrawRectangle(static_cast<int>(topWall.x), static_cast<int>(topWall.y), static_cast<int>(topWall.width), topWall.height, RAYWHITE);
}

void Hud::PlayerWin()
{
	
}

void Hud::PlayerLose()
{

}

void Hud::Pause()
{

}

bool Hud::isPlayerAlive() 
{
	return true;
}