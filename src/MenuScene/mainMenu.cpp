#include "mainMenu.h"

MainMenu::MainMenu()
{
	float width = 200.0f;
	float height = 40.0f;
	Vector2 pos = { width / 2,height * 2};
	Color buttonColor = RED;
	Color buttonSelectionColor = GREEN;
	SceneType buttonType = SceneType::Gameplay;

	Button* playButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	sceneButtons.push_back(playButton);

	pos = { width / 2,height * 4};
	buttonType = SceneType::Rules;
	Button* rulesButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	sceneButtons.push_back(rulesButton);
	
	pos = { width / 2,height * 6};
	buttonType = SceneType::Options;
	Button* optionsButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	sceneButtons.push_back(optionsButton);
	
	pos = { width / 2,height * 8};
	buttonType = SceneType::Credits;
	Button* creditsButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	sceneButtons.push_back(creditsButton);
	
	pos = { width / 2,height * 6};
	buttonType = SceneType::Exit;
	Button* exitButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	sceneButtons.push_back(exitButton);

	this->gameplay = false;
	this->rules = false;
	this->options = false;
	this->credits = false;
	this->exit = false;

	std::cout << "A New Main Menu Was Created" << std::endl;
}

MainMenu::~MainMenu()
{
	std::cout << "A New Main Menu Was Destroyed" << std::endl;
}

SceneType MainMenu::ExecuteScene()
{
	Update();
	if (gameplay)
	{
		return SceneType::Gameplay;
	}
	else if (rules)
	{
		return SceneType::Gameplay;
	}
	else if (options)
	{
		return SceneType::Gameplay;
	}
	else if (exit)
	{
		return SceneType::Gameplay;
	}
	else
	{
		return SceneType::MainMenu;
	}
}


void MainMenu::Update()
{
	Draw();
	Input();
	
	for (int i = 0; i < sceneButtons.size(); i++)
	{
		sceneButtons[i]->SetMouseOver(CheckCollisionPointRec(GetMousePosition(),sceneButtons[i]->GetMouseRec()));
	}
}

void MainMenu::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	float size = sceneButtons.size();

	for (int i = 0; i < size; i++)
	{
		sceneButtons[i]->DrawButton();
	}

	DrawCircle(GetMouseX(),GetMouseY(),5,YELLOW);

	EndDrawing();
}

void MainMenu::Input()
{
	for (int i = 0; i < sceneButtons.size(); i++)
	{

	}
	for (int i = 0; i < sceneButtons.size(); i++)
	{
		sceneButtons[i]->GetButtonPos();
		if (sceneButtons[i]->GetButtonType() == SceneType::Gameplay && sceneButtons[i]->IsButtonPressed())
		{
			this->gameplay = true;
		}
		else if (sceneButtons[i]->GetButtonType() == SceneType::Rules && sceneButtons[i]->IsButtonPressed())
		{
			this->rules = true;
		}
		else if (sceneButtons[i]->GetButtonType() == SceneType::Options && sceneButtons[i]->IsButtonPressed())
		{
			this->options = true;
		}
		else if (sceneButtons[i]->GetButtonType() == SceneType::Credits && sceneButtons[i]->IsButtonPressed())
		{
			this->credits = true;
		}
		else if (sceneButtons[i]->GetButtonType() == SceneType::Exit && sceneButtons[i]->IsButtonPressed())
		{
			this->exit = true;
		}
	}
}

void MainMenu::AddButton(Button* newButton)
{

}