#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "game.h"

Game::Game()
{
	screenWidht = 1280;
	screenHeight = 720;

	InitWindow(screenWidht, screenHeight, "Witch's forest bobble");

	float playerWidth = 20.0f;
	float playerHeight = 40.0f;
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

	Vector2 pos = player->GetPosition();

	cout << "player pos x " << pos.x << endl;
	cout << "player pos y " << pos.y << endl;
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