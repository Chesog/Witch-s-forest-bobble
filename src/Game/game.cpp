#include "game.h"

Game::Game()
{
	screenWidht = 1280;
	screenHeight = 720;

	InitWindow(screenWidht, screenHeight, "Witch's forest bobble");

	this->mainMenuScene = new MainMenu;
	this->gameplayScene = new Gameplay;
	this->creditsScene = new Credits;
	this->rulesScene = new Rules;

	this->resetScene = false;

	currentScene = SceneType::MainMenu;
	lastSelectedScene = SceneType::MainMenu;

	std::cout << "Witch-s-forest-bobble was created" << std::endl;

}

Game::~Game()
{
	
	delete mainMenuScene;
	delete gameplayScene;

	std::cout << "Witch-s-forest-bobble was destroyed" << std::endl;
}

void Game::ExecuteGame()
{

	do
	{
		switch (currentScene)
		{
		case SceneType::MainMenu:
			if (ShouldResetScene())
			{
				mainMenuScene->ResetScene();
				lastSelectedScene = currentScene;
			}
			currentScene = mainMenuScene->ExecuteScene();
			break;
		case SceneType::Gameplay:
			if (ShouldResetScene())
			{
				gameplayScene->ResetScene();
				lastSelectedScene = currentScene;
			}
			currentScene = gameplayScene->ExecuteScene();
			break;
		case SceneType::Rules:
			if (ShouldResetScene())
			{
				rulesScene->ResetScene();
				lastSelectedScene = currentScene;
			}
			currentScene = rulesScene->ExecuteScene();
			break;
		case SceneType::Options:
			break;
		case SceneType::Credits:
			if (ShouldResetScene())
			{
				creditsScene->ResetScene();
				lastSelectedScene = currentScene;
			}
			currentScene = creditsScene->ExecuteScene();
			break;
		case SceneType::Exit:
			return;
			break;
		default:
			currentScene = SceneType::MainMenu;
			break;
		}
	} while (!WindowShouldClose());
}

bool Game::ShouldResetScene()
{
	if (lastSelectedScene == currentScene)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Game::ScreenResized(int& screenWidth, int& screenHeight)
{
	int auxWidth = screenWidth;
	int auxHeight = screenHeight;
	screenWidth = GetScreenWidth();
	screenHeight = GetScreenHeight();
	if (screenHeight != auxHeight || screenWidth != auxWidth)
	{
		return true;
	}
	else
	{
		return false;
	}
}