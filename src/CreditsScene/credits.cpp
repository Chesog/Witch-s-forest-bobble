#include "CreditsScene/credits.h"

Credits::Credits()
{
	float width = 200.0f;
	float height = 40.0f;
	Vector2 pos = {GetScreenWidth() - width * 1.5f,height};
	Color buttonColor = RED;
	Color buttonSelectionColor = GREEN;
	SceneType buttonType = SceneType::MainMenu;

	Button* returnButton = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	AddButton(returnButton);

	this->sceneFont = LoadFont("Assets/Fonts/HelloTwinsDEMO.otf");
	this->sceneTextFont = LoadFont("Assets/Fonts/Rock Slayers.otf");
	this->sceneBackground = LoadTexture("Assets/Background/CreditsBackground.png");

	this->sceneBackgroundPos = {0.0f,0.0f};
	this->sceneBackgroundRotation = 0.0f;
	this->sceneBackgroundScale = 1.0f;
	this->sceneBackgroundTint = WHITE;

	width = 40.0f;
	height = 40.0f;
	buttonColor = RED;
	buttonSelectionColor = GREEN;
	buttonType = SceneType::Credits;

	pos = {width,height * 4.5f};
	Button* InstagramJ = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	AddButton(InstagramJ);

	pos = { width,height * 6.5f };
	Button* InstagramM = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	AddButton(InstagramM);

	pos = { width,height * 8.5f };
	Button* InstagramP = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	AddButton(InstagramP);

	pos = {GetScreenWidth() - width * 2.5f,height * 4.5f };
	Button* GitE = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	AddButton(GitE);

	pos = { GetScreenWidth() - width * 2.5f,height * 7.5f };
	Button* ytC = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	AddButton(ytC);

	pos = { GetScreenWidth() - width * 10.0f,height * 11.5f };
	Button* GitD = new Button(pos, width, height, buttonColor, buttonSelectionColor, buttonType);
	AddButton(GitD);

	selectionScene = SceneType::Credits;
	std::cout << "A Credits Scene Was Created" << std::endl;
}

Credits::~Credits()
{
	UnloadFont(sceneFont);
	UnloadFont(sceneTextFont);
	UnloadTexture(sceneBackground);
	std::cout << "A Credits Scene Was Destroyed" << std::endl;
}

SceneType Credits::ExecuteScene()
{
	Update();
	return selectionScene;
}

void Credits::Update()
{
	Draw();
	Input();
	CheckButtonState();
}

void Credits::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawTextureEx(sceneBackground, sceneBackgroundPos, sceneBackgroundRotation, sceneBackgroundScale,sceneBackgroundTint);

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

	float mult = 3.0f;
	const char* titleText = "Credits";
	int titleFontSize = 90.0f;
	float titleSpacing = 3.0f;
	Vector2 titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	Vector2 textPos;
	textPos.x = (GetScreenWidth() / 2) - (titleSize.x / 2);
	textPos.y = titleFontSize / 3;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult = 3.0f;
	titleText = "Credits";
	titleFontSize = 80.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos;
	textPos.x = (GetScreenWidth() / 2) - (titleSize.x / 2);
	textPos.y = titleFontSize / 3;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, WHITE);

	mult = 1.5f;
	titleText = "Art Team";
	titleFontSize = 65.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 5) - (titleSize.x / 2);
	textPos.y = titleFontSize * 1.5f;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult = 1.5f;
	titleText = "Art Team";
	titleFontSize = 60.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 5) - (titleSize.x / 2);
	textPos.y = titleFontSize * 1.5f;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, WHITE);

	mult = 4.5f;

	titleText = "~ Jules Leech";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 5) - (titleSize.x / 2);
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult = 6.5f;
	titleText = "~ Martina Bonfiglio";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 5) - (titleSize.x / 2);
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult =  8.5f;
	titleText = "~ Pauli";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 5) - (titleSize.x / 2);
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult = 1.5f;
	titleText = "Music Team";
	titleFontSize = 65.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2 + (GetScreenWidth() / 4) - (titleSize.x / 2));
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	titleText = "Music Team";
	titleFontSize = 60.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2 + (GetScreenWidth() / 4) - (titleSize.x / 2));
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, WHITE);

	mult = 4.5f;

	titleText = "~ Enzo Coletta";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2 + (GetScreenWidth() / 4) - (titleSize.x / 2));
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult++;

	titleText = "Alias: BiscupidTea";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2 + (GetScreenWidth() / 4) - (titleSize.x / 2));
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult = 7.5f;

	titleText = "~ Canine Lotus";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2 + (GetScreenWidth() / 4) - (titleSize.x / 2));
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult = 6.0f;
	titleText = "Developer Team";
	titleFontSize = 63.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2) - (titleSize.x / 2);
	textPos.y = titleFontSize  * mult;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	titleText = "Developer Team";
	titleFontSize = 60.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2) - (titleSize.x / 2);
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneFont, titleText, textPos, titleFontSize, titleSpacing, WHITE);

	mult = 11.0f;
	titleText = "~ Dario Otranto";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2) - (titleSize.x / 2);
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	mult ++;
	titleText = "Alias: Cheso";
	titleFontSize = 40.0f;
	titleSpacing = 3.0f;
	titleSize = MeasureTextEx(sceneFont, titleText, titleFontSize, titleSpacing);
	textPos.x = (GetScreenWidth() / 2) - (titleSize.x / 2);
	textPos.y = titleFontSize * mult;

	DrawTextEx(sceneTextFont, titleText, textPos, titleFontSize, titleSpacing, BLACK);

	EndDrawing();
}


void Credits::Input()
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

void Credits::ResetScene() 
{
	int sceneButtonsSice = sceneButtons.size();
	for (int i = 0; i < sceneButtonsSice; i++)
	{
		sceneButtons[i]->SetButtonPresed(false);
		sceneButtons[i]->SetMouseOver(false);
	}
	selectionScene = SceneType::Credits;
}

void Credits::AddButton(Button* newButton)
{
	sceneButtons.push_back(newButton);
}

void Credits::CheckButtonState()
{
	for (int i = 0; i < sceneButtons.size(); i++)
	{
		sceneButtons[i]->SetMouseOver(CheckCollisionPointRec(GetMousePosition(), sceneButtons[i]->GetButtonRec()));
	}

	if (sceneButtons[0]->IsButtonPressed())
	{
		selectionScene = sceneButtons[0]->GetButtonType();
		sceneButtons[0]->SetButtonPresed(false);
	}

	if (sceneButtons[1]->IsButtonPressed())
	{
		//OpenURL("");
		sceneButtons[1]->SetButtonPresed(false);
	}

	if (sceneButtons[2]->IsButtonPressed())
	{
		//OpenURL("");
		sceneButtons[2]->SetButtonPresed(false);
	}

	if (sceneButtons[3]->IsButtonPressed())
	{
		//OpenURL("");
		sceneButtons[3]->SetButtonPresed(false);
	}

	if (sceneButtons[4]->IsButtonPressed())
	{
		OpenURL("https://github.com/BiscupidTea");
		sceneButtons[4]->SetButtonPresed(false);
	}

	if (sceneButtons[5]->IsButtonPressed())
	{
		OpenURL("https://www.youtube.com/channel/UCOUky79zg0Lc0HweQCkd59Q");
		sceneButtons[5]->SetButtonPresed(false);
	}

	if (sceneButtons[6]->IsButtonPressed())
	{
		OpenURL("https://github.com/Chesog");
		sceneButtons[6]->SetButtonPresed(false);
	}
}