#include "game.h"

Game::Game()
{
	screenWidht = 1280;
	screenHeight = 720;

	InitWindow(screenWidht, screenHeight, "Witch's forest bobble");

	this->mainMenuScene = new MainMenu;
	this->gameplayScene = new Gameplay;

	currentScene = SceneType::MainMenu;

	std::cout << "Witch-s-forest-bobble was created" << std::endl;

}

Game::~Game()
{
	
	delete mainMenuScene;

	std::cout << "Witch-s-forest-bobble was destroyed" << std::endl;
}

void Game::GameLoop()
{

	do
	{
		switch (currentScene)
		{
		case SceneType::MainMenu:
			currentScene = mainMenuScene->ExecuteScene();
			break;
		case SceneType::Gameplay:
			currentScene = gameplayScene->ExecuteScene();
			break;
		case SceneType::Rules:
			break;
		case SceneType::Options:
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

void Game::GameInput()
{
	
}

void Game::Update()
{
	
}

void Game::Draw()
{
	
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