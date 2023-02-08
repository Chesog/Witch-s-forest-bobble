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
	initialPos.y = static_cast<float>(GetScreenHeight() - playerHeight * 2);

	this->player = new Player(initialPos, EntityType::Player, playerSpeed, playerInitalScore, playerWidth, playerHeight, playerInitalLives);
	this->initGame = true;

	this->hud = new Hud(player, gameBalls);

	player->SetActualBall(CreateBall());

	cout << "Witch-s-forest-bobble was created" << endl;

}

Game::~Game()
{
	for (int i = 0; i < gameBalls.size(); i++)
	{
		delete gameBalls[i];
	}

	delete player;

	delete hud;

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
		if (player->GetCanShoot())
		{
			player->SetActualBallTrajectory(player->GetDirection());
			player->SetActualBall(CreateBall());
		}
		else
		{
			return;
		}
	}
}

Ball* Game::CreateBall()
{

	Vector2 trajectory = { 0.0f,0.0f };
	Vector2 ballInitialPos;
	ballInitialPos.x = player->GetXPosition();
	ballInitialPos.y = player->GetYPosition();

	float ballSpeed = 200.0f;
	float ballPoints = 10.0f;
	float ballRad = 20.0f;

	Color ballColor;
	BallColors color;

	int colorSelection = GetRandomValue(static_cast<int>(BallColors::Red), static_cast<int>(BallColors::Blue));

	switch (colorSelection)
	{
	case static_cast<int>(BallColors::Red):
		ballColor = RED;
		color = BallColors::Red;
		break;
	case static_cast<int>(BallColors::Yellow):
		ballColor = YELLOW;
		color = BallColors::Yellow;
		break;
	case static_cast<int>(BallColors::White):
		ballColor = WHITE;
		color = BallColors::White;
		break;
	case static_cast<int>(BallColors::Blue):
		ballColor = BLUE;
		color = BallColors::Blue;
		break;
	default:
		ballColor = BLACK;
		break;
	}

	Ball* ball = new Ball(ballInitialPos, trajectory, EntityType::Ball, ballSpeed, ballPoints, ballRad, ballColor, color);

	gameBalls.push_back(ball);

	return ball;
}

void Game::Update()
{
	player->Movement();

	CheckColition();
	CheckConection();
	OutOfBounds();

	Vector2 distanceDiff;


	distanceDiff.x = GetMouseX() - player->GetXPosition();
	distanceDiff.y = GetMouseY() - player->GetYPosition();

	float angle = atan(distanceDiff.y / distanceDiff.x);
	angle = angle * 180 / PI;

	if (angle < 0)
	{
		angle = (angle)+180;
	}


	//cout << angle << endl;

	if (player->GetRotation() < angle)
	{
		player->SetRotation(player->GetRotation() + player->GetSpeed() * GetFrameTime());

		if (player->GetRotation() > angle)
		{
			player->SetRotation(angle);
		}
	}
	else if (player->GetRotation() > angle)
	{
		player->SetRotation(player->GetRotation() - player->GetSpeed() * GetFrameTime());

		if (player->GetRotation() < angle)
		{
			player->SetRotation(angle);
		}
	}

	if (player->GetRotation() == angle)
	{
		player->SetCanShoot(true);
	}
	else
	{
		player->SetCanShoot(false);
	}

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
	int size = gameBalls.size();

	BeginDrawing();
	ClearBackground(BLACK);

	player->Draw();

	if (gameBalls.size() != 0)
	{
		for (int i = 0; i < size; i++)
		{
			gameBalls[i]->Draw();
		}
	}

	hud->Draw();


	EndDrawing();
}

void Game::DrawBoard()
{

}

void Game::CheckConection()
{
	int size = gameBalls.size();
	int concetionToFall = 3;

	for (int i = 0; i < size; i++)
	{
		if (gameBalls[i]->GetColidedBallsSize() >= concetionToFall && !gameBalls[i]->GetIsFalling())
		{
			Vector2 trajectory;
			trajectory.y = 2.0f;
			trajectory.x = 0.0f;
			gameBalls[i]->SetTrajectoy(trajectory);
			gameBalls[i]->SetIsFalling(true);
			gameBalls[i]->StartConcectionFall();
		}
	}
}

void Game::CheckColition()
{
	for (int i = 0; i < gameBalls.size(); i++)
	{
		Vector2 newTrajectory = gameBalls[i]->GetTrajectory();

		if (CheckCollisionCircleRec(gameBalls[i]->GetPos(), gameBalls[i]->GetRad(), hud->GetLeftWall()))
		{
			newTrajectory.x = newTrajectory.x * -1;

			gameBalls[i]->SetTrajectoy(newTrajectory);

		}
		else if (CheckCollisionCircleRec(gameBalls[i]->GetPos(), gameBalls[i]->GetRad(), hud->GetRightWall()))
		{

			newTrajectory.x = newTrajectory.x * -1;

			gameBalls[i]->SetTrajectoy(newTrajectory);
		}
		else if (CheckCollisionCircleRec(gameBalls[i]->GetPos(), gameBalls[i]->GetRad(), hud->GetTopWall()))
		{
			newTrajectory.x = 0.0f;
			newTrajectory.y = 0.0f;
			gameBalls[i]->SetTrajectoy(newTrajectory);
			gameBalls[i]->SetCanColide(true);
		}
	}
	for (int i = 0; i < gameBalls.size(); i++)
	{
		Vector2 newTrajectory;
		for (int j = 0; j < gameBalls.size(); j++)
		{
			if (gameBalls[i]->GetCanColide())
			{
				if (!gameBalls[i]->GetIsFalling() && !gameBalls[j]->GetIsFalling())
				{
					if (gameBalls[i] != gameBalls[j])
					{
						if (BallBallColition(gameBalls[i], gameBalls[j]))
						{
							newTrajectory.x = 0.0f;
							newTrajectory.y = 0.0f;
							gameBalls[i]->SetTrajectoy(newTrajectory);
							if (gameBalls[i]->GetColor() == gameBalls[j]->GetColor())
							{
								gameBalls[i]->AddCollidedBall(gameBalls[j]);
								gameBalls[j]->AddCollidedBall(gameBalls[i]);
							}
						}
					}
				}
			}
		}
	}
}

void Game::OutOfBounds()
{
	for (int i = 0; i < gameBalls.size(); i++)
	{
		if (gameBalls[i]->GetPosY() > screenHeight)
		{
			delete gameBalls[i];
			gameBalls.erase(gameBalls.begin() + i);
		}
	}
}

bool Game::BallBallColition(Ball* ball1, Ball* ball2)
{
	float distanceX = 0;
	float distanceY = 0;
	float distance = 0;

	distanceX = ball2->GetPosX() - ball1->GetPosX();
	distanceY = ball2->GetPosY() - ball1->GetPosY();

	distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));

	if (distance < ball1->GetRad() + ball2->GetRad())
	{
		return true;
	}
	else
	{
		return false;
	}
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