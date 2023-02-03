#pragma once
#include <vector>
#include "Entity/entity.h"
#include "Hud/hud.h"
#include "Player/player.h"
#include "Ball/ball.h"

using namespace std;

class Game
{
private:
	vector<Ball*> gameBalls;
	Player* player;
	Hud* hud;

	bool initGame;

	int screenWidht;
	int screenHeight;
public:
	Game();
	~Game();

	void GameLoop();
	void GameInput();
	void Update();
	void Draw();
	void DrawBoard();

	bool ScreenResized(int& screenWidth, int& screenHeight);
};