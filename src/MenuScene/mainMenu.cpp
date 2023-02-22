#include "mainMenu.h"

MainMenu::MainMenu()
{
	float width = 200.0f;
	float height = 40.0f;
	Vector2 pos = { width / 2,height * 2 };
	Color buttonColor = RED;
	Color buttonSelectionColor = GREEN;
	SceneType buttonType = SceneType::Gameplay;

	Button* playButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType); \
	AddButton(playButton);

	pos = { width / 2,height * 4 };
	buttonType = SceneType::Rules;
	Button* rulesButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	AddButton(rulesButton);

	pos = { width / 2,height * 6 };
	buttonType = SceneType::Options;
	Button* optionsButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	AddButton(optionsButton);

	pos = { width / 2,height * 8 };
	buttonType = SceneType::Credits;
	Button* creditsButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	AddButton(creditsButton);

	pos = { width / 2,height * 10 };
	buttonType = SceneType::Exit;
	Button* exitButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	AddButton(exitButton);

	selectionScene = SceneType::MainMenu;

	std::cout << "A New Main Menu Was Created" << std::endl;
}

MainMenu::~MainMenu()
{
	int sceneButtonsSize = sceneButtons.size();
	for (int i = 0; i < sceneButtonsSize; i++)
	{
		delete sceneButtons[i];
	}
	std::cout << "A New Main Menu Was Destroyed" << std::endl;
}

SceneType MainMenu::ExecuteScene()
{
	Update();
	return selectionScene;
}


void MainMenu::Update()
{
	Draw();
	Input();
	CheckButtonState();
}

void MainMenu::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	int size = sceneButtons.size();


	for (int i = 0; i < size; i++)
	{
		sceneButtons[i]->DrawButton();
	}

	const char* buttonText = "Play";
	int buttonFontSize = 30.0f;
	int textSize = MeasureText(buttonText, buttonFontSize);
	int textPosX = sceneButtons[0]->GetButtonPos().x + textSize / 2;
	int textPosY = sceneButtons[0]->GetButtonPos().y + buttonFontSize / 3;

	DrawText(buttonText,textPosX,textPosY,buttonFontSize, BLACK);

	buttonText = "Rules";
	textSize = MeasureText(buttonText, buttonFontSize);
	textPosX = sceneButtons[1]->GetButtonPos().x + textSize / 2;
	textPosY = sceneButtons[1]->GetButtonPos().y + buttonFontSize / 3;

	DrawText(buttonText, textPosX, textPosY, buttonFontSize, BLACK);

	buttonText = "Options";
	textSize = MeasureText(buttonText, buttonFontSize);
	textPosX = sceneButtons[2]->GetButtonPos().x + textSize / 2;
	textPosY = sceneButtons[2]->GetButtonPos().y + buttonFontSize / 3;

	DrawText(buttonText, textPosX, textPosY, buttonFontSize, BLACK);

	buttonText = "Credits";
	textSize = MeasureText(buttonText, buttonFontSize);
	textPosX = sceneButtons[3]->GetButtonPos().x + textSize / 2;
	textPosY = sceneButtons[3]->GetButtonPos().y + buttonFontSize / 3;

	DrawText(buttonText, textPosX, textPosY, buttonFontSize, BLACK);

	buttonText = "Exit";
	textSize = MeasureText(buttonText, buttonFontSize);
	textPosX = sceneButtons[4]->GetButtonPos().x + textSize / 2;
	textPosY = sceneButtons[4]->GetButtonPos().y + buttonFontSize / 3;

	DrawText(buttonText, textPosX, textPosY, buttonFontSize, BLACK);


	DrawCircle(GetMouseX(), GetMouseY(), 5, YELLOW);

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