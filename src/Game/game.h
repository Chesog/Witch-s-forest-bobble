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