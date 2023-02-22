#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "raymath.h"
#include "GlobalUtilities/globalUtilities.h"
#include "GameScene/gameScene.h"
#include "Entity/entity.h"
#include "Player/player.h"
#include "Ball/ball.h"
#include "Hud/hud.h"

class Gameplay : public GameScene
{
private:
	std::vector<Ball*> gameBalls;
	Player* player;
	Hud* hud;
	Vector2 distanceDiff;

	bool initGame;
	bool ballsStopMoving;
public:
	Gameplay();
	~Gameplay();

	SceneType ExecuteScene() override;
	void Draw() override;
	void Update() override;
	void Input() override;
	void AddButton(Button* newButton) override;
	void CheckButtonState();
	void CheckColition();
	void CheckConection();
	void CheckBallsMovement();
	void OutOfBounds();
	bool BallBallColition(Ball* ball1, Ball* ball2);

	Ball* CreateBall();
};