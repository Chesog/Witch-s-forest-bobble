#include "RulesScene/rules.h"

Rules::Rules()
{
	float width = 200.0f;
	float height = 40.0f;
	Vector2 pos = { GetScreenWidth() - width * 1.5f,height };
	Color buttonColor = RED;
	Color buttonSelectionColor = GREEN;
	SceneType buttonType = SceneType::MainMenu;
	Texture2D returnButtonTexture = LoadTexture("Assets/Buttons/return.png");

	Button* returnButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType, returnButtonTexture);
	AddButton(returnButton);

	this->sceneFont = LoadFont("Assets/Fonts/HelloTwinsDEMO.otf");
	this->sceneTextFont = LoadFont("Assets/Fonts/Rock Slayers.otf");
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
	UnloadFont(sceneTextFont);
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


	float mult = 3.0f;
	const char* titleText = "Rules";
	int titleFontSize = 90.0f;
	float titleSpacing = 3.0f;
	Vector2 titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	Vector2 textPos;
	textPos.x = (GetScreenWidth() / 2) - (titleSize.x / 2);
	textPos.y = titleFontSize / 3;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult = 3.0f;
	titleText = "Rules";
	titleFontSize = 80.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos;
	textPos.x = (GetScreenWidth() / 2) - (titleSize.x / 2);
	textPos.y = titleFontSize / 3;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, WHITE);

	mult = 1.5f;
	titleText = "How To Play";
	titleFontSize = 65.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 5) - (titleSize.x / 2);
	textPos.y = titleFontSize * 1.5f;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult = 1.5f;
	titleText = "How To Play";
	titleFontSize = 60.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 5) - (titleSize.x / 2);
	textPos.y = titleFontSize * 1.5f;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, WHITE);

	mult = 4.5f;

	titleText = "~ Right Click To Shoot";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 5) - (titleSize.x / 2);
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult ++;
	titleText = "~ You Can Only Shoot";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 5) - (titleSize.x / 2);
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult ++;
	titleText = "When The Player And";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 5) - (titleSize.x / 2);
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult++;
	titleText = "The Balls Stop Moving";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 5) - (titleSize.x / 2);
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult ++;
	titleText = "~ Esc To Pause";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 5) - (titleSize.x / 2);
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult = 1.5f;
	titleText = "Objetive";
	titleFontSize = 65.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2 + (GetScreenWidth() / 4) - (titleSize.x / 2));
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	titleText = "Objetive";
	titleFontSize = 60.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2 + (GetScreenWidth() / 4) - (titleSize.x / 2));
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, WHITE);

	mult = 4.5f;

	titleText = "~ Save The Animals";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2 + (GetScreenWidth() / 4) - (titleSize.x / 2));
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult ++;

	titleText = "~ Don't Let The Balls";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2 + (GetScreenWidth() / 4) - (titleSize.x / 2));
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult++;

	titleText = "Touch The Bottom Line";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2 + (GetScreenWidth() / 4) - (titleSize.x / 2));
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);
	

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
			sceneButtons[i]->SetButtonPresed(false);
		}
	}
}