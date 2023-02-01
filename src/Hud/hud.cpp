#include <iostream>
#include "raylib.h"
#include "hud.h"

Hud::Hud(Player* player, vector<Ball*> gameBalls)
{
	this->player = player;
	this->gameBalls = gameBalls;

	cout << "The HUD was Created" << endl;
}

Hud::~Hud() 
{
	cout << "The HUD was send to oblivion" << endl;
}

void Hud::Draw() 
{

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

}