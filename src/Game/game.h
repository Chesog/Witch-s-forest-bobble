#pragma once
#include <iostream>
#include "GlobalUtilities/globalUtilities.h"
#include "MenuScene/mainMenu.h"
#include "GameplayScene/gameplay.h"
#include "CreditsScene/credits.h"


class Game
{
private:
	MainMenu* mainMenuScene;
	Gameplay* gameplayScene;
	Credits* creditsScene;

	SceneType currentScene;
	SceneType lastSelectedScene;

	bool resetScene;

	int screenWidht;
	int screenHeight;
public:
	Game();
	~Game();

	void ExecuteGame();

	bool ShouldResetScene();
	bool ScreenResized(int& screenWidth, int& screenHeight);
};