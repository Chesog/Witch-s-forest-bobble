#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "Player/player.h"
#include "Ball/ball.h"

class Hud
{
private:
	Player* player;
	std::vector<Ball*> gameBalls;

	Rectangle leftWall;
	Rectangle rightWall;
	Rectangle topWall;

public:
	Hud(Player* player, std::vector<Ball*> gameBalls);
	~Hud();

	void Draw();
	void PlayerWin();
	void PlayerLose();
	void Pause();

	Rectangle GetLeftWall();
	Rectangle GetRightWall();
	Rectangle GetTopWall();

	bool isPlayerAlive();
};