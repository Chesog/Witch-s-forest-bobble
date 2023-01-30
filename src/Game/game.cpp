#include <iostream>
#include "game.h"
#include "raylib.h"

Game::Game()
{
	float playerWidth = 20.0f;
	float playerHeight = 40.0f;
	float playerSpeed = 200.0f;
	float playerInitalScore = 0.0f;
	float playerInitalLives = 3.0f;

	Vector2 initialPos = Vector2{ static_cast<float>(GetScreenWidth() / 2) , static_cast<float>((GetScreenHeight() / 2) - playerHeight) };

	this->player = new Player(initialPos, EntityType::Player, playerSpeed, playerInitalScore, playerWidth, playerHeight, playerInitalLives);
	this->initGame = true;

	cout << "Witch-s-forest-bobble was created" << endl;
}

Game::~Game() 
{
	cout << "Witch-s-forest-bobble was destroyed" << endl;
}

void Game::GameInput() 
{

}

void Game::Draw() 
{

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