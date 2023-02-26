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
	Rectangle finishLine;

public:
	Hud(Player* player, std::vector<Ball*> gameBalls);
	~Hud();

	void Draw();
	void PlayerWin();
	void PlayerLose();
	void Pause();
	void UpdateGameBalls(std::vector<Ball*> gameBalls);

	Rectangle GetLeftWall();
	Rectangle GetRightWall();
	Rectangle GetTopWall();
	Rectangle GetFinishLine();

	bool isPlayerAlive();
};