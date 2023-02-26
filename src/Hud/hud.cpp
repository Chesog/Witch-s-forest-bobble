#include "hud.h"

Hud::Hud(Player* player, std::vector<Ball*> gameBalls)
{
	this->player = player;
	this->gameBalls = gameBalls;

	drawVictory = false;
	drawDefeat = false;

	float sideWallsWidht = 20.0f;
	float sideWallsHeight = GetScreenHeight();

	float leftWallX = static_cast<float>(GetScreenWidth() / 3 - (sideWallsWidht / 2));
	float rightWallX = leftWallX * 2;
	float sideWallsY = 0.0f;

	float topWallWidht = rightWallX - leftWallX;
	float topWallHeight = 20.0f;

	float topWallX = leftWallX;
	float topWallY = 0.0f;


	float finishLineWidht = rightWallX - leftWallX;
	float finishLineHeight = 10.0f;

	float finishLineX = leftWallX;
	float finishLineY = player->GetYPosition() - 100.0f;

	finishLine.width = finishLineWidht;
	finishLine.height = finishLineHeight;
	finishLine.x = finishLineX;
	finishLine.y = finishLineY;

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

	pauseMenu.width = finishLineWidht;
	pauseMenu.height = sideWallsHeight;
	pauseMenu.x = topWallX;
	pauseMenu.y = topWallY;


	std::cout << "The HUD was Created" << std::endl;
}

Hud::~Hud()
{
	std::cout << "The HUD was send to oblivion" << std::endl;
}

void Hud::Draw()
{
	DrawRectangle(static_cast<int>(leftWall.x), static_cast<int>(leftWall.y), static_cast<int>(leftWall.width), leftWall.height, RAYWHITE);
	DrawRectangle(static_cast<int>(rightWall.x), static_cast<int>(rightWall.y), static_cast<int>(rightWall.width), rightWall.height, RAYWHITE);
	DrawRectangle(static_cast<int>(topWall.x), static_cast<int>(topWall.y), static_cast<int>(topWall.width), topWall.height, RAYWHITE);
	DrawRectangle(static_cast<int>(finishLine.x), static_cast<int>(finishLine.y), static_cast<int>(finishLine.width), finishLine.height, RAYWHITE);
	int versionFontSize = 30;
	int versionTextSize = MeasureText("V 0.4", versionFontSize);
	DrawText("V 0.4", GetScreenWidth() - (versionTextSize * 2), GetScreenHeight() - versionTextSize, versionFontSize, RAYWHITE);

	if (drawPause)
	{
		DrawRectangle(static_cast<int>(pauseMenu.x), static_cast<int>(pauseMenu.y), static_cast<int>(pauseMenu.width), pauseMenu.height, RAYWHITE);
	}

	if (drawVictory)
	{
		int vFontSize = 80;
		int vTextSize = MeasureText("VICTORY", vFontSize);
		drawPause = true;
		DrawText("VICTORY", (GetScreenWidth() / 2) - (vTextSize / 2), vFontSize * 2, vFontSize, GREEN);
	}

	if (drawDefeat)
	{
		int dFontSize = 80;
		int dTextSize = MeasureText("DEFEAT", dFontSize);
		drawPause = true;
		DrawText("DEFEAT", (GetScreenWidth() / 2) - (dTextSize / 2), dFontSize * 2, dFontSize, RED);
	}
}

void Hud::UpdateGameBalls(std::vector<Ball*> gameBalls)
{
	this->gameBalls = gameBalls;
}

void Hud::PlayerWin()
{
	int specialBalls = 0;
	int gameBallsSize = gameBalls.size();
	for (int i = 0; i < gameBallsSize; i++)
	{
		if (gameBalls[i]->GetBallType() == EntityType::SpecialBall)
		{
			specialBalls++;
		}
	}
	if (specialBalls == 0)
	{
		drawVictory = true;
	}
	else
	{
		drawVictory = false;
	}
}

void Hud::PlayerLose(bool ballsStopMoving)
{
	int finishLineBalls = 0;
	int gameBallsSize = gameBalls.size();
	for (int i = 0; i < gameBallsSize; i++)
	{
		if (CheckCollisionCircleRec(gameBalls[i]->GetPos(), gameBalls[i]->GetRad(), finishLine) && ballsStopMoving)
		{
			finishLineBalls++;
		}
	}
	if (finishLineBalls != 0)
	{
		drawDefeat = true;
	}
	else
	{
		drawDefeat = false;
	}
}

void Hud::SetDrawPause(bool drawPause)
{
	this->drawPause = drawPause;
}

bool Hud::GetDrawPause()
{
	return drawPause;
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

Rectangle Hud::GetFinishLine()
{
	return finishLine;
}