#include "GameplayScene/gameplay.h"

Gameplay::Gameplay()
{
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

	this->sceneFont = LoadFont("Assets/Fonts/Hero Fest.otf");
	this->sceneBackground = LoadTexture("Assets/Background/GameplayBackground.png");
	this->sceneBackground2 = LoadTexture("Assets/Background/GameplayBackground2.png");
	this->cursorTexture = LoadTexture("Assets/Cursor/cursor.png");

	this->sceneBackgroundPos = { 0.0f,0.0f };
	this->sceneBackgroundRotation = 0.0f;
	this->sceneBackgroundScale = 1.0f;
	this->sceneBackgroundTint = WHITE;

	this->shootCount = 0;
	this->maxShootCount = 10;

	this->hud = new Hud(player, gameBalls);

	player->SetActualBall(CreateBall());

	CreateBallPatern();
}

Gameplay::~Gameplay()
{
	UnloadFont(sceneFont);
	UnloadTexture(sceneBackground);
	UnloadTexture(sceneBackground2);
	UnloadTexture(cursorTexture);

	for (int i = 0; i < gameBalls.size(); i++)
	{
		delete gameBalls[i];
	}

	delete player;
	delete hud;
}

void Gameplay::ResetScene()
{
	int size = gameBalls.size();
	for (int i = 0; i < size; i++)
	{
		delete gameBalls[i];
	}
	for (int i = 0; i < size; i++)
	{
		gameBalls.erase(gameBalls.begin());
	}

	CreateBallPatern();
	player->SetActualBall(CreateBall());
}

SceneType Gameplay::ExecuteScene()
{
	Input();
	Update();
	Draw();
	return SceneType::Gameplay;
}

void Gameplay::Draw()
{
	int size = gameBalls.size();

	BeginDrawing();
	ClearBackground(BLACK);

	DrawTextureEx(sceneBackground2, sceneBackgroundPos, sceneBackgroundRotation, sceneBackgroundScale, sceneBackgroundTint);
	DrawTextureEx(sceneBackground, sceneBackgroundPos, sceneBackgroundRotation, sceneBackgroundScale, sceneBackgroundTint);

	player->Draw();

	if (gameBalls.size() != 0)
	{
		for (int i = 0; i < size; i++)
		{
			gameBalls[i]->Draw();
		}
	}

	hud->Draw();

	HideCursor();
	DrawTextureEx(cursorTexture, GetMousePosition(), sceneBackgroundRotation, 0.1f, sceneBackgroundTint);

	EndDrawing();
}

void Gameplay::Update()
{
	player->Movement();

	CheckColition();
	CheckConection();
	CheckBallsMovement();
	OutOfBounds();
	checkShootCount();

	distanceDiff.x = GetMouseX() - player->GetXPosition();
	distanceDiff.y = GetMouseY() - player->GetYPosition();

	float angle = atan(distanceDiff.y / distanceDiff.x);
	angle = angle * 180 / PI;

	if (angle < 0)
	{
		angle = angle + 180;
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

	hud->UpdateGameBalls(gameBalls);
	hud->PlayerWin();
	hud->PlayerLose(ballsStopMoving);
}

void Gameplay::Input()
{
	if (!hud->GetDrawPause())
	{
		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
		{
			if (player->GetCanShoot() && ballsStopMoving)
			{
				float newRad = 20.0f;
				player->SetActualBallRad(newRad);
				player->SetActualBallPos(player->GetPosition());
				player->SetActualBallTrajectory(player->GetDirection());
				player->SetActualBall(CreateBall());
				shootCount++;
			}
			else
			{
				return;
			}
		}
	}
	if (IsKeyReleased(KEY_ESCAPE))
	{
		if (hud->GetDrawPause())
		{
			hud->SetDrawPause(false);
		}
		else
		{
			hud->SetDrawPause(true);
		}
	}
}

void Gameplay::AddButton(Button* newButton)
{
	sceneButtons.push_back(newButton);
}

void Gameplay::CheckButtonState()
{

}

void Gameplay::CheckColition()
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

void Gameplay::CheckConection()
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
				for (int h = 0; h < size; h++)
				{
					if (gameBalls[h]->GetPos().x <= gameBalls[i]->GetPos().x - gameBalls[i]->GetRad() && !gameBalls[i]->GetIsFalling() || gameBalls[h]->GetPos().x >= gameBalls[i]->GetPos().x + gameBalls[i]->GetRad() && !gameBalls[i]->GetIsFalling())
					{
						if (gameBalls[h]->GetPos().y > gameBalls[i]->GetPos().y && gameBalls[h] != player->GetActualBall())
						{
							Vector2 trajectory;
							trajectory.y = 2.0f;
							trajectory.x = 0.0f;
							gameBalls[h]->SetTrajectoy(trajectory);
							gameBalls[h]->SetIsFalling(true);
							gameBalls[h]->StartConcectionFall();
							return;
						}
					}
				}
			}
		}
	}
}

void Gameplay::CheckBallsMovement()
{
	Vector2 stopMovement = { 0.0f,0.0f };
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

void Gameplay::OutOfBounds()
{
	for (int i = 0; i < gameBalls.size(); i++)
	{
		if (gameBalls[i]->GetPosY() > GetScreenHeight())
		{
			delete gameBalls[i];
			gameBalls.erase(gameBalls.begin() + i);
		}
	}
}

bool Gameplay::BallBallColition(Ball* ball1, Ball* ball2)
{
	float distanceX = 0;
	float distanceY = 0;
	float distance = 0;

	distanceX = ball2->GetPosX() - ball1->GetPosX();
	distanceY = ball2->GetPosY() - ball1->GetPosY();

	distance = sqrt((distanceX * distanceX) + (distanceY * distanceY));

	if (distance <= ball1->GetRad() + ball2->GetRad())
	{
		return true;
	}
	else
	{
		return false;
	}
}

Ball* Gameplay::CreateBall()
{
	float ballSpeed = 500.0f;
	float ballPoints = 10.0f;
	float ballRad = 20.0f;

	Vector2 trajectory = { 0.0f,0.0f };
	Vector2 ballInitialPos;
	ballInitialPos.x = player->GetXPosition() - ballRad * 5;
	ballInitialPos.y = player->GetYPosition();



	Color ballColor;
	BallColors color;
	Texture2D ballTexture;

	int colorSelection = GetRandomValue(static_cast<int>(BallColors::Red), static_cast<int>(BallColors::Orange));

	switch (colorSelection)
	{
	case static_cast<int>(BallColors::Red):
		ballColor = RED;
		color = BallColors::Red;
		ballTexture = LoadTexture("Assets/Balls/RedBubble.png");
		break;
	case static_cast<int>(BallColors::Yellow):
		ballColor = YELLOW;
		color = BallColors::Yellow;
		ballTexture = LoadTexture("Assets/Balls/YellowBubble.png");
		break;
	case static_cast<int>(BallColors::Purple):
		ballColor = PURPLE;
		color = BallColors::Purple;
		ballTexture = LoadTexture("Assets/Balls/PurpleBubble.png");
		break;
	case static_cast<int>(BallColors::Blue):
		ballColor = BLUE;
		color = BallColors::Blue;
		ballTexture = LoadTexture("Assets/Balls/BlueBubble.png");
		break;
	case static_cast<int>(BallColors::Green):
		ballColor = GREEN;
		color = BallColors::Green;
		ballTexture = LoadTexture("Assets/Balls/GreenBubble.png");
		break;
	case static_cast<int>(BallColors::Orange):
		ballColor = ORANGE;
		color = BallColors::Orange;
		ballTexture = LoadTexture("Assets/Balls/OrangeBubble.png");
		break;
	default:
		ballColor = BLACK;
		break;
	}

	Ball* ball = new Ball(ballInitialPos, trajectory, EntityType::Ball, ballSpeed, ballPoints, ballRad, ballColor, color, ballTexture);

	gameBalls.push_back(ball);

	return ball;
}

void Gameplay::CreateBallPatern()
{

	std::vector<Ball*> PaternBalls;
	int paternRow = 9;
	int paternColum = 4;
	int paternCounter = paternRow * paternColum;
	int colorSelection;
	int ballTypeSelection;

	float ballSpeed = 500.0f;
	float ballPoints = 10.0f;
	float ballRad = 20.0f;

	Vector2 trajectory = { 0.0f,0.0f };
	Vector2 ballInitialPos;
	Vector2 ballAuxPos;

	Color ballColor;
	BallColors color;
	Texture2D ballTexture;
	EntityType ballType;

	int ballsCreated = 0;
	int currentRow = 1;
	int maxBallsPerRow = 9;
	int maxBallsPerColum = 4;

	do
	{
		if (ballsCreated == maxBallsPerRow)
		{
			ballsCreated = 0;
			currentRow++;
		}
		if (ballsCreated < maxBallsPerRow)
		{
			ballAuxPos.x = (hud->GetLeftWall().x + hud->GetLeftWall().width) + (ballRad * 2) * (ballsCreated + 1);
			if (currentRow == 1)
			{
				ballAuxPos.y = (hud->GetTopWall().y + hud->GetTopWall().height) + (ballRad * 2) * currentRow - 5;
			}
			else
			{
				ballAuxPos.y = (hud->GetTopWall().y + hud->GetTopWall().height) + (ballRad * 2) * currentRow - 5;
			}
			ballInitialPos = ballAuxPos;
			ballsCreated++;
		}

		colorSelection = GetRandomValue(static_cast<int>(BallColors::Red), static_cast<int>(BallColors::Orange));
		ballTypeSelection = GetRandomValue(static_cast<int>(EntityType::LevelBall), static_cast<int>(EntityType::SpecialBall));

		switch (colorSelection)
		{
		case static_cast<int>(BallColors::Red):
			ballColor = RED;
			color = BallColors::Red;
			if (ballTypeSelection == static_cast<int>(EntityType::LevelBall))
			{
				ballTexture = LoadTexture("Assets/Balls/RedBubble.png");
			}
			else if (ballTypeSelection == static_cast<int>(EntityType::SpecialBall))
			{
				ballTexture = LoadTexture("Assets/Animals/FoxBubble.png");
			}
			break;
		case static_cast<int>(BallColors::Yellow):
			ballColor = YELLOW;
			color = BallColors::Yellow;
			if (ballTypeSelection == static_cast<int>(EntityType::LevelBall))
			{
				ballTexture = LoadTexture("Assets/Balls/YellowBubble.png");
			}
			else if (ballTypeSelection == static_cast<int>(EntityType::SpecialBall))
			{
				ballTexture = LoadTexture("Assets/Animals/RabbitBubble.png");
			}
			break;
		case static_cast<int>(BallColors::Purple):
			ballColor = PURPLE;
			color = BallColors::Purple;
			ballTexture = LoadTexture("Assets/Balls/PurpleBubble.png");
			break;
		case static_cast<int>(BallColors::Blue):
			ballColor = BLUE;
			color = BallColors::Blue;
			if (ballTypeSelection == static_cast<int>(EntityType::LevelBall))
			{
				ballTexture = LoadTexture("Assets/Balls/BlueBubble.png");
			}
			else if (ballTypeSelection == static_cast<int>(EntityType::SpecialBall))
			{
				ballTexture = LoadTexture("Assets/Animals/FishBubble.png");
			}
			break;
		case static_cast<int>(BallColors::Green):
			ballColor = GREEN;
			color = BallColors::Green;
			if (ballTypeSelection == static_cast<int>(EntityType::LevelBall))
			{
				ballTexture = LoadTexture("Assets/Balls/GreenBubble.png");
			}
			else if (ballTypeSelection == static_cast<int>(EntityType::SpecialBall))
			{
				ballTexture = LoadTexture("Assets/Animals/OwlBubble.png");
			}
			break;
		case static_cast<int>(BallColors::Orange):
			ballColor = ORANGE;
			color = BallColors::Orange;
			ballTexture = LoadTexture("Assets/Balls/OrangeBubble.png");
			break;
		default:
			ballColor = BLACK;
			break;
		}

		if (ballTypeSelection == static_cast<int>(EntityType::LevelBall))
		{
			ballType = EntityType::LevelBall;
		}
		else
		{
			ballType = EntityType::SpecialBall;
		}


		Ball* ball = new Ball(ballInitialPos, trajectory, ballType, ballSpeed, ballPoints, ballRad, ballColor, color, ballTexture);


		ball->SetCanColide(true);
		ball->SetIsFalling(false);
		PaternBalls.push_back(ball);

		int size = PaternBalls.size();

		for (int i = 0; i < size; i++)
		{
			Vector2 newTrajectory;
			for (int j = 0; j < size; j++)
			{
				if (PaternBalls[i]->GetCanColide())
				{
					if (!PaternBalls[i]->GetIsFalling() && !PaternBalls[j]->GetIsFalling())
					{
						if (PaternBalls[i] != PaternBalls[j])
						{
							if (BallBallColition(PaternBalls[i], PaternBalls[j]))
							{
								newTrajectory.x = 0.0f;
								newTrajectory.y = 0.0f;
								PaternBalls[i]->SetTrajectoy(newTrajectory);
								if (PaternBalls[i]->GetColor() == PaternBalls[j]->GetColor())
								{
									std::vector<Ball*> collidedBalls = PaternBalls[j]->GetCollidedBalls();
									int collidedSize = PaternBalls[j]->GetColidedBallsSize();
									int count = 0;
									int playerBall = 0;
									for (int h = 0; h < collidedSize; h++)
									{
										if (PaternBalls[i] == collidedBalls[h])
										{
											count++;
										}
									}

									if (count == 0)
									{
										PaternBalls[i]->AddCollidedBall(PaternBalls[j]);
										PaternBalls[j]->AddCollidedBall(PaternBalls[i]);
									}

								}
							}
						}
					}
				}
			}
		}
		paternCounter--;

	} while (paternCounter > 0);

	for (int i = 0; i < PaternBalls.size(); i++)
	{
		gameBalls.push_back(PaternBalls[i]);
	}
}

void Gameplay::checkShootCount()
{
	if (shootCount == maxShootCount)
	{
		Vector2 newPos;

		for (int i = 0; i < gameBalls.size(); i++)
		{
			if (gameBalls[i] != player->GetActualBall())
			{
				newPos.x = gameBalls[i]->GetPos().x;
				newPos.y = gameBalls[i]->GetPos().y + gameBalls[i]->GetRad();
				gameBalls[i]->SetPos(newPos);
			}
		}
		shootCount = 0;
	}
}