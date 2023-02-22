#pragma once
#include <iostream>
#include "GlobalUtilities/globalUtilities.h"
#include "MenuScene/mainMenu.h"
#include "Gameplay/gameplay.h"


class Game
{
private:
	MainMenu* mainMenuScene;
	Gameplay* gameplayScene;
	SceneType currentScene;

	int screenWidht;
	int screenHeight;
public:
	Game();
	~Game();

	void GameLoop();
	void GameInput();
	void Update();
	void Draw();

	bool ScreenResized(int& screenWidth, int& screenHeight);
};