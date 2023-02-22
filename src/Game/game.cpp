#include "game.h"

Game::Game()
{
	screenWidht = 1280;
	screenHeight = 720;

	InitWindow(screenWidht, screenHeight, "Witch's forest bobble");

	this->mainMenu = new MainMenu;

	float playerWidth = 40.0f;
	float playerHeight = 20.0f;
	float playerSpeed = 80.0f;
	float playerInitalScore = 0.0f;

	int playerInitalLives = 3;

	Vector2 initialPos;
	initialPos.x = static_cast<float>(GetScreenWidth() / 2);
	initialPos.y = static_cast<float>(GetScreenHeight() - playerHeight * 2);

	this->player = new Player(initialPos, EntityType::Player, playerSpeed, playerInitalScore, playerWidth, playerHeight, playerInitalLives);
	this->initGame = true;
	this->ballsStopMoving = true;

	this->hud = new Hud(player, gameBalls);

	player->SetActualBall(CreateBall());

	currentScene = SceneType::MainMenu;

	std::cout << "Witch-s-forest-bobble was created" << std::endl;

}

Game::~Game()
{
	for (int i = 0; i < gameBalls.size(); i++)
	{
		delete gameBalls[i];
	}

	delete mainMenu;

	delete player;

	delete hud;

	std::cout << "Witch-s-forest-bobble was destroyed" << std::endl;
}

void Game::GameLoop()
{

	do
	{
		switch (currentScene)
		{
		case SceneType::MainMenu:
			currentScene = mainMenu->ExecuteScene();
			break;
		case SceneType::Gameplay:
			GameInput();
			Update();
			Draw();
			break;
		case SceneType::Rules:
			break;
		case SceneType::Options:
			break;
		case SceneType::Exit:
			return;
			break;
		default:
			currentScene = SceneType::MainMenu;
			break;
		}
	} while (!WindowShouldClose());
}

void Game::GameInput()
{
	if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
	{
		if (player->GetCanShoot() && ballsStopMoving)
		{
			float newRad = 20.0f;
			player->SetActualBallRad(newRad);
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

	float ballSpeed = 300.0f;
	float ballPoints = 10.0f;
	float ballRad = 5.0f;

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
	CheckBallsMovement();
	OutOfBounds();

	distanceDiff.x = GetMouseX() - player->GetXPosition();
	distanceDiff.y = GetMouseY() - player->GetYPosition();

	float angle = atan(distanceDiff.y / distanceDiff.x);
	angle = angle * 180 / PI;

	if (angle < 0)
	{
		angle =  angle + 180;
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

void Game::CheckBallsMovement()
{
	Vector2 stopMovement = {0.0f,0.0f};
	float size = gameBalls.size();
	float counter = 0.0f;
	for (int i = 0; i < size; i++)
	{
		if (gameBalls[i]->GetTrajectory().x == stopMovement.x && gameBalls[i]->GetTrajectory().y == stopMovement.y)
		{
			counter++;
		}
	}

	if (counter == size)
	{
		ballsStopMoving = true;
	}
	else
	{
		ballsStopMoving = false;
	}
}

void Game::CheckConection()
{
	int size = gameBalls.size();
	int concetionToFall = 2;

	for (int i = 0; i < size; i++)
	{
		if (gameBalls[i]->GetColidedBallsSize() >= concetionToFall && !gameBalls[i]->GetIsFalling())
		{
			std::vector<Ball*> collidedBalls = gameBalls[i]->GetCollidedBalls();
			int collidedSize = gameBalls[i]->GetColidedBallsSize();
			int playerBalls = 0;
			for (int j = 0; j < collidedSize; j++)
			{
				if (collidedBalls[j]->GetBallType() == EntityType::Ball)
				{
					playerBalls++;
				}
			}
			if (playerBalls >= 1)
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
}

void Game::CheckColition()
{
	float size = gameBalls.size();
	for (int i = 0; i < size; i++)
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
		}

		if (gameBalls[i]->GetPos().y < player->GetPosition().y - 100.0f)
		{
			gameBalls[i]->SetCanColide(true);
		}
	}
	for (int i = 0; i < size; i++)
	{
		Vector2 newTrajectory;
		for (int j = 0; j < size; j++)
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
								std::vector<Ball*> collidedBalls = gameBalls[j]->GetCollidedBalls();
								int collidedSize = gameBalls[j]->GetColidedBallsSize();
								int count = 0;
								int playerBall = 0;
								for (int h = 0; h < collidedSize; h++)
								{
									if (gameBalls[i] == collidedBalls[h])
									{
										count++;
									}
								}

								if (count == 0)
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