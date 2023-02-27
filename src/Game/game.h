#pragma once
#include <iostream>
#include "GlobalUtilities/globalUtilities.h"
#include "MenuScene/mainMenu.h"
#include "GameplayScene/gameplay.h"
#include "CreditsScene/credits.h"
#include "RulesScene/rules.h"
#include "Options/options.h"


class Game
{
private:
	MainMenu* mainMenuScene;
	Gameplay* gameplayScene;
	Credits* creditsScene;
	Rules* rulesScene;
	Options* optionsScene;

	SceneType currentScene;
	SceneType lastSelectedScene;

	bool resetScene;

	float masterVolume;

	int screenWidht;
	int screenHeight;
public:
	Game();
	~Game();

	void ExecuteGame();

	bool ShouldResetScene();
	bool ScreenResized(int& screenWidth, int& screenHeight);
};