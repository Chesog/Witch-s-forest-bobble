#include "game.h"

Game::Game()
{
	screenWidht = 1280;
	screenHeight = 720;

	this->masterVolume = 0.1f;

	InitWindow(screenWidht, screenHeight, "Witch's forest bobble");
	InitAudioDevice();

	SetExitKey(NULL);

	this->mainMenuScene = new MainMenu;
	this->gameplayScene = new Gameplay;
	this->creditsScene = new Credits;
	this->rulesScene = new Rules;
	this->optionsScene = new Options;

	this->resetScene = false;

	currentScene = SceneType::MainMenu;
	lastSelectedScene = SceneType::MainMenu;

	std::cout << "Witch-s-forest-bobble was created" << std::endl;

}

Game::~Game()
{
	
	delete mainMenuScene;
	delete gameplayScene;
	delete creditsScene;
	delete rulesScene;
	delete optionsScene;

	CloseAudioDevice();

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
				mainMenuScene->SetVolumeMusic(masterVolume);
			}
			mainMenuScene->SetVolumeMusic(masterVolume);
			currentScene = mainMenuScene->ExecuteScene(masterVolume);
			masterVolume = mainMenuScene->GetVolumeMusic();
			break;
		case SceneType::Gameplay:
			if (ShouldResetScene())
			{
				gameplayScene->ResetScene();
				lastSelectedScene = currentScene;
				gameplayScene->SetVolumeMusic(masterVolume);
			}
			currentScene = gameplayScene->ExecuteScene(masterVolume);
			masterVolume = gameplayScene->GetVolumeMusic();
			break;
		case SceneType::Rules:
			if (ShouldResetScene())
			{
				rulesScene->ResetScene();
				lastSelectedScene = currentScene;
				rulesScene->SetVolumeMusic(masterVolume);
			}
			currentScene = rulesScene->ExecuteScene(masterVolume);
			masterVolume = rulesScene->GetVolumeMusic();
			break;
		case SceneType::Options:
			if (ShouldResetScene())
			{
				optionsScene->ResetScene();
				lastSelectedScene = currentScene;
				optionsScene->SetVolumeMusic(masterVolume);
			}
			currentScene = optionsScene->ExecuteScene(masterVolume);
			masterVolume = optionsScene->GetVolumeMusic();
			break;
		case SceneType::Credits:
			if (ShouldResetScene())
			{
				creditsScene->ResetScene();
				lastSelectedScene = currentScene;
				creditsScene->SetVolumeMusic(masterVolume);
			}
			currentScene = creditsScene->ExecuteScene(masterVolume);
			masterVolume = creditsScene->GetVolumeMusic();
			break;
		case SceneType::Exit:
			return;
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