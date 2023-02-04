#include <iostream>
#include "raylib.h"
#include "hud.h"

Hud::Hud(Player* player, vector<Ball*> gameBalls)
{
	this->player = player;
	this->gameBalls = gameBalls;


	float sideWallsWidht = 20;
	float sideWallsHeight = GetScreenHeight();

	float leftWallX = static_cast<float>(GetScreenWidth() / 3 - (sideWallsWidht / 2));
	float rightWallX = leftWallX * 2;
	float sideWallsY = 0.0f;

	float topWallWidht = rightWallX - leftWallX;
	float topWallHeight = 20;

	float topWallX = leftWallX;
	float topWallY = 0.0f;
	
	leftWall.width = sideWallsWidht;
	leftWall.height = sideWallsHeight;
	leftWall.x = leftWallX;
	leftWall.y = sideWallsY;

	rightWall.width = sideWallsWidht;
	rightWall.height = sideWallsHeight;
	rightWall.x = rightWallX;
	rightWall.y = sideWallsY;

	topWall.width = topWallWidht;
	topWall.height = topWallHeight;
	topWall.x = topWallX;
	topWall.y = topWallY;


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

Rectangle Hud::GetLeftWall()
{
	return leftWall;
}

Rectangle Hud::GetRightWall()
{
	return rightWall;
}

Rectangle Hud::GetTopWall()
{
	return topWall;
}