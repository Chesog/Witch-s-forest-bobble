#pragma once
#include <iostream>
#include <vector>
#include "GlobalUtilities/globalUtilities.h"
#include "MenuScene/mainMenu.h"
#include "Entity/entity.h"
#include "Player/player.h"
#include "Ball/ball.h"
#include "Hud/hud.h"
#include "raymath.h"
#include "raylib.h"


class Game
{
private:
	MainMenu* mainMenu;
	std::vector<Ball*> gameBalls;
	Player* player;
	Hud* hud;
	SceneType currentScene;
	Vector2 distanceDiff;

	bool initGame;
	bool ballsStopMoving;

	int screenWidht;
	int screenHeight;
public:
	Game();
	~Game();

	void GameLoop();
	void GameInput();
	void Update();
	void Draw();
	void CheckColition();
	void CheckConection();
	void CheckBallsMovement();
	void OutOfBounds();

	bool BallBallColition(Ball* ball1, Ball* ball2);
	bool ScreenResized(int& screenWidth, int& screenHeight);

	Ball* CreateBall();
};