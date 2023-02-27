#include "mainMenu.h"

MainMenu::MainMenu()
{
	float width = 200.0f;
	float height = 40.0f;
	Vector2 pos = { width / 2,height * 2 };
	Color buttonColor = RED;
	Color buttonSelectionColor = GREEN;
	SceneType buttonType = SceneType::Gameplay;

	this->sceneMusic = LoadMusicStream("Assets/Music/menu music.wav");

	this->cursorTexture = LoadTexture("Assets/Cursor/cursor.png");

	this->sceneBackground = LoadTexture("Assets/Background/MenuBackground.png");
	this->sceneBackgroundPos = { 0.0f,0.0f };
	this->sceneBackgroundRotation = 0.0f;
	this->sceneBackgroundScale = 1.0f;
	this->sceneBackgroundTint = WHITE;

	Texture2D buttonTexture = LoadTexture("Assets/Buttons/1.play1.png");

	Button* playButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType, buttonTexture);
	AddButton(playButton);

	buttonTexture = LoadTexture("Assets/Buttons/2.rules1.png");
	pos = { width / 2,height * 4 };
	buttonType = SceneType::Rules;
	Button* rulesButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType, buttonTexture);
	AddButton(rulesButton);

	buttonTexture = LoadTexture("Assets/Buttons/3.options1.png");
	pos = { width / 2,height * 6 };
	buttonType = SceneType::Options;
	Button* optionsButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType, buttonTexture);
	AddButton(optionsButton);

	buttonTexture = LoadTexture("Assets/Buttons/4.credits1.png");
	pos = { width / 2,height * 8 };
	buttonType = SceneType::Credits;
	Button* creditsButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType, buttonTexture);
	AddButton(creditsButton);

	buttonTexture = LoadTexture("Assets/Buttons/5.exi1t.png");
	pos = { width / 2,height * 10 };
	buttonType = SceneType::Exit;
	Button* exitButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType, buttonTexture);
	AddButton(exitButton);

	selectionScene = SceneType::MainMenu;

	std::cout << "A New Main Menu Was Created" << std::endl;
}

MainMenu::~MainMenu()
{
	UnloadTexture(sceneBackground);
	UnloadTexture(cursorTexture);
	UnloadMusicStream(sceneMusic);

	int sceneButtonsSize = sceneButtons.size();
	for (int i = 0; i < sceneButtonsSize; i++)
	{
		delete sceneButtons[i];
	}
	std::cout << "A New Main Menu Was Destroyed" << std::endl;
}

SceneType MainMenu::ExecuteScene(float& volume)
{
	SetVolumeMusic(volume);
	Update();
	if (selectionScene != SceneType::MainMenu)
	{
		StopMusicStream(sceneMusic);
	}
	return selectionScene;
}


void MainMenu::Update()
{

	if (!IsMusicStreamPlaying(sceneMusic))
	{
		PlayMusicStream(sceneMusic);
	}
	else
	{
		UpdateMusicStream(sceneMusic);
	}
	SetMusicVolume(sceneMusic, volume);

	Draw();
	Input();
	CheckButtonState();
}

void MainMenu::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	HideCursor();
	DrawTextureEx(cursorTexture,GetMousePosition(), sceneBackgroundRotation, sceneBackgroundScale, sceneBackgroundTint);

	DrawTextureEx(sceneBackground, sceneBackgroundPos, sceneBackgroundRotation, sceneBackgroundScale, sceneBackgroundTint);

	int size = sceneButtons.size();


	for (int i = 0; i < size; i++)
	{
		sceneButtons[i]->DrawButton();
	}

	HideCursor();
	DrawTextureEx(cursorTexture, GetMousePosition(), sceneBackgroundRotation, 0.1f, sceneBackgroundTint);

	EndDrawing();
}

void MainMenu::Input()
{
	int size = sceneButtons.size();

	for (int i = 0; i < size; i++)
	{
		if (CheckCollisionPointRec(GetMousePosition(), sceneButtons[i]->GetButtonRec()))
		{
			if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
			{
				sceneButtons[i]->SetButtonPresed(true);
			}
			else
			{
				sceneButtons[i]->SetButtonPresed(false);
			}
		}
	}
}

void MainMenu::ResetScene() 
{
	int sceneButtonsSice = sceneButtons.size();
	for (int i = 0; i < sceneButtonsSice; i++)
	{
		sceneButtons[i]->SetButtonPresed(false);
		sceneButtons[i]->SetMouseOver(false);
	}
	selectionScene = SceneType::MainMenu;
}

void MainMenu::AddButton(Button* newButton)
{
	sceneButtons.push_back(newButton);
}

void MainMenu::CheckButtonState()
{
	for (int i = 0; i < sceneButtons.size(); i++)
	{
		sceneButtons[i]->SetMouseOver(CheckCollisionPointRec(GetMousePosition(), sceneButtons[i]->GetButtonRec()));
	}

	for (int i = 0; i < sceneButtons.size(); i++)
	{
		if (sceneButtons[i]->IsButtonPressed())
		{
			selectionScene = sceneButtons[i]->GetButtonType();
		}
	}
}

float MainMenu::GetVolumeMusic()
{
	return volume;
}
void MainMenu::SetVolumeMusic(float newVolume)
{
	this->volume = newVolume;
}