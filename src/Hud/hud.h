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

public:
	Hud(Player* player, vector<Ball*> gameBalls);
	~Hud();

	void Draw();
	void PlayerWin();
	void PlayerLose();
	void Pause();

	bool isPlayerAlive();
};