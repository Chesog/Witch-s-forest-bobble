#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "game.h"

Game::Game()
{
	screenWidht = 1280;
	screenHeight = 720;

	InitWindow(screenWidht, screenHeight, "Witch's forest bobble");

	float playerWidth = 40.0f;
	float playerHeight = 20.0f;
	float playerSpeed = 200.0f;
	float playerInitalScore = 0.0f;

	int playerInitalLives = 3;

	Vector2 initialPos;
	initialPos.x = static_cast<float>(GetScreenWidth() / 2);
	initialPos.y = static_cast<float>(GetScreenHeight() -  playerHeight * 2);

	this->player = new Player(initialPos, EntityType::Player, playerSpeed, playerInitalScore, playerWidth, playerHeight, playerInitalLives);
	this->initGame = true;

	cout << "Witch-s-forest-bobble was created" << endl;




	
}

Game::~Game()
{
	cout << "Witch-s-forest-bobble was destroyed" << endl;
}

void Game::GameLoop()
{
	do
	{

		GameInput();
		Update();
		Draw();

	} while (!WindowShouldClose());
}

void Game::GameInput()
{
	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
	{
		Vector2 ballInitialPos;
		ballInitialPos.x = player->GetXPosition();
		ballInitialPos.y = player->GetYPosition() - (player->GetWidth() / 2);

		float ballSpeed = 200.0f;
		float ballPoints = 10.0f;
		float ballRad = 20.0f;

		Color ballColor;

		int colorSelection = GetRandomValue(1,4);

		switch (colorSelection)
		{
		case 1:
			ballColor = RED;
			break;
		case 2 :
			ballColor = YELLOW;
			break;
		case 3:
			ballColor = WHITE;
			break;
		case 4:
			ballColor = BLUE;
			break;
		default:
			break;
		}

		gameBalls.push_back(new Ball(ballInitialPos,player->GetDirection(),EntityType::Ball,ballSpeed,ballPoints,ballRad,ballColor));
		
	}


}

void Game::Update()
{
	player->Movement();

	Vector2 distanceDiff;


	distanceDiff.x = GetMouseX() - player->GetXPosition();
	distanceDiff.y = GetMouseY() - player->GetYPosition();
	float angle = atan(distanceDiff.y / distanceDiff.x);
	angle = angle * 180 / PI;

	if (GetMousePosition().x < player->GetXPosition() && GetMousePosition().y < player->GetYPosition())
	{
		angle += 180 * GetFrameTime();
	}
	if (GetMousePosition().x < player->GetXPosition() && GetMousePosition().y > player->GetYPosition())
	{
		angle += 180 * GetFrameTime();
	}
	if (GetMousePosition().x > player->GetXPosition() && GetMousePosition().y > player->GetYPosition())
	{
		angle += 360 * GetFrameTime();
	}

	player->SetRotation(angle);

	player->SetDirection(Vector2Normalize(distanceDiff));


	if (gameBalls.size() != 0)
	{
		for (int i = 0; i < gameBalls.size(); i++)
		{
			gameBalls[i]->Movement();
		}
	}
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	player->Draw();

	if (gameBalls.size() != 0)
	{
		for (int i = 0; i < gameBalls.size(); i++)
		{
			gameBalls[i]->Draw();
		}
	}

	EndDrawing();
}

void Game::DrawBoard()
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