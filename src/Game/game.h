#pragma once
#include <vector>
#include "Entity/entity.h"
#include "Player/player.h"

using namespace std;

class Game
{
private:
	vector<Entity*> entities;
	Player* player;
	bool initGame;

public:
	Game();
	~Game();

	void GameInput();
	void Draw();
	void DrawBoard();

	bool ScreenResized(int& screenWidth, int& screenHeight);
};