#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "game.h"

Game::Game()
{
	float playerWidth = 20.0f;
	float playerHeight = 40.0f;
	float playerSpeed = 200.0f;
	float playerInitalScore = 0.0f;

	int playerInitalLives = 3;

	Vector2 initialPos = Vector2{ static_cast<float>(GetScreenWidth() / 2) , static_cast<float>((GetScreenHeight() / 2) - playerHeight) };

	this->player = new Player(initialPos, EntityType::Player, playerSpeed, playerInitalScore, playerWidth, playerHeight, playerInitalLives);
	this->initGame = true;

	cout << "Witch-s-forest-bobble was created" << endl;

	int screenWidht = 1280;
	int screenHeight = 720;


	InitWindow(screenWidht, screenHeight, "Witch's forest bobble");
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
	Vector2 distanceDiff;


	distanceDiff.x = GetMouseX() - player->GetXPosition();
	distanceDiff.y = GetMouseY() - player->GetYPosition();
	float angle = atan(distanceDiff.y / distanceDiff.x);
	angle = angle * 180 / PI;

	if (GetMousePosition().x < player->GetXPosition() && GetMousePosition().y < player->GetYPosition())
	{
		angle += 180;
	}
	if (GetMousePosition().x < player->GetXPosition() && GetMousePosition().y > player->GetYPosition())
	{
		angle += 180;
	}
	if (GetMousePosition().x > player->GetXPosition() && GetMousePosition().y > player->GetYPosition())
	{
		angle += 360;
	}

	player->SetRotation(angle);

	player->SetDirection(Vector2Normalize(distanceDiff));
}

void Game::Update()
{
	player->Movement();
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	player->Draw();

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