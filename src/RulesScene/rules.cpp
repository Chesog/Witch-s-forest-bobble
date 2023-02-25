#include "RulesScene/rules.h"

Rules::Rules()
{
	float width = 200.0f;
	float height = 40.0f;
	Vector2 pos = { GetScreenWidth() - width * 1.5f,height };
	Color buttonColor = RED;
	Color buttonSelectionColor = GREEN;
	SceneType buttonType = SceneType::MainMenu;

	Button* returnButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	AddButton(returnButton);

	this->sceneFont = LoadFont("Assets/Fonts/Hero Fest.otf");
	this->sceneBackground = LoadTexture("Assets/Background/RulesBackground.png");

	this->sceneBackgroundPos = { 0.0f,0.0f };
	this->sceneBackgroundRotation = 0.0f;
	this->sceneBackgroundScale = 1.0f;
	this->sceneBackgroundTint = WHITE;

	selectionScene = SceneType::Rules;
	std::cout << "A Credits Scene Was Created" << std::endl;
}

Rules::~Rules()
{
	UnloadFont(sceneFont);
	UnloadTexture(sceneBackground);
	std::cout << "A Credits Scene Was Destroyed" << std::endl;
}

SceneType Rules::ExecuteScene()
{
	Update();
	return selectionScene;
}

void Rules::Update()
{
	Draw();
	Input();
	CheckButtonState();
}

void Rules::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawTextureEx(sceneBackground, sceneBackgroundPos, sceneBackgroundRotation, sceneBackgroundScale, sceneBackgroundTint);

	int sceneButtonsSice = sceneButtons.size();
	for (int i = 0; i < sceneButtonsSice; i++)
	{
		sceneButtons[i]->DrawButton();
	}

	const char* buttonText = "Return";
	int buttonFontSize = 30.0f;
	int textSize = MeasureText(buttonText, buttonFontSize);
	int textPosX = sceneButtons[0]->GetButtonPos().x + textSize / 2;
	int textPosY = sceneButtons[0]->GetButtonPos().y + buttonFontSize / 3;

	DrawText(buttonText, textPosX, textPosY, buttonFontSize, BLACK);

	const char* titleText = "Rules";
	int titleFontSize = 80.0f;
	float titleSpacing = 3.0f;
	Vector2 titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	Vector2 textPos;
	textPos.x = (GetScreenWidth() / 2) - (titleSize.x / 2);
	textPos.y = titleFontSize;

	//DrawLine(GetScreenWidth() / 2,0,GetScreenWidth() / 2,GetScreenHeight(),WHITE);
	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, GREEN);

	EndDrawing();
}


void Rules::Input()
{
	int sceneButtonsSice = sceneButtons.size();

	for (int i = 0; i < sceneButtonsSice; i++)
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

void Rules::ResetScene()
{
	int sceneButtonsSice = sceneButtons.size();
	for (int i = 0; i < sceneButtonsSice; i++)
	{
		sceneButtons[i]->SetButtonPresed(false);
		sceneButtons[i]->SetMouseOver(false);
	}
	selectionScene = SceneType::Rules;
}

void Rules::AddButton(Button* newButton)
{
	sceneButtons.push_back(newButton);
}

void Rules::CheckButtonState()
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