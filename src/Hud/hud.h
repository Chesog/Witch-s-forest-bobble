#pragma once
#include <vector>
#include "Player/player.h"
#include "Ball/ball.h"

using namespace std;

class Hud
{
private:
	Player* player;
	vector<Ball*> gameBalls;

	Rectangle leftWall;
	Rectangle rightWall;
	Rectangle topWall;

public:
	Hud(Player* player, vector<Ball*> gameBalls);
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