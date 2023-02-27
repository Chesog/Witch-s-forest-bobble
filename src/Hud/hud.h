#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "Player/player.h"
#include "Ball/ball.h"

namespace WFB
{

	class Hud
	{
	private:
		Player* player;
		std::vector<Ball*> gameBalls;

		Rectangle leftWall;
		Rectangle rightWall;
		Rectangle topWall;
		Rectangle finishLine;
		Rectangle pauseMenu;

		bool drawPause;
		bool drawVictory;
		bool drawDefeat;

	public:
		Hud(Player* player, std::vector<Ball*> gameBalls);
		~Hud();

		void Draw();
		void PlayerWin();
		void PlayerLose(bool ballsStopMoving);
		void UpdateGameBalls(std::vector<Ball*> gameBalls);
		void SetDrawPause(bool drawPause);

		Rectangle GetLeftWall();
		Rectangle GetRightWall();
		Rectangle GetTopWall();
		Rectangle GetFinishLine();

		bool GetDrawPause();
	};
}