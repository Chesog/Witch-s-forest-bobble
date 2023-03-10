#include "Ball/ball.h"

namespace WFB
{

	Ball::Ball(Vector2 pos, Vector2 trajectory, EntityType type, float speed, float points, float rad, Color ballColor, BallColors color, Texture2D ballTexture) : Entity(pos, type, speed, points)
	{
		this->pos = pos;
		this->type = type;
		this->speed.x = speed;
		this->speed.y = speed;
		this->points = points;
		this->rad = rad;
		this->ballColor = ballColor;
		this->trajectory = trajectory;
		this->color = color;
		this->ballTexture = ballTexture;
		canColide = false;
		isFalling = false;
		currentDirection = Directions::Stop;
		std::cout << "A New Ball Is Created" << std::endl;
	}

	Ball::~Ball()
	{
		UnloadTexture(ballTexture);
		std::cout << "A Ball Was Destroyed" << std::endl;
	}
	void Ball::Draw()
	{
		Vector2 textureCenter;
		float textureScale;

		if (rad == 5.0f)
		{
			textureScale = 0.04f;
		}
		else
		{
			textureScale = 0.16f;
		}
		float textureRotation = 0.0f;
		textureCenter.x = static_cast<int>(pos.x - rad);
		textureCenter.y = static_cast<int>(pos.y - rad);
		DrawTextureEx(ballTexture, textureCenter, textureRotation, textureScale, ballColor);
	}
	void Ball::Movement()
	{
		pos.x = pos.x + trajectory.x * speed.x * GetFrameTime();
		pos.y = pos.y + trajectory.y * speed.y * GetFrameTime();
	}

	void Ball::AddCollidedBall(Ball* ball)
	{
		collidedBalls.push_back(ball);
	}

	void Ball::StartConcectionFall()
	{
		int size = collidedBalls.size();

		for (int i = 0; i < size; i++)
		{
			if (!collidedBalls[i]->GetIsFalling())
			{
				Vector2 trajectory;
				trajectory.y = 2.0f;
				trajectory.x = 0.0f;
				collidedBalls[i]->SetTrajectoy(trajectory);
				collidedBalls[i]->SetIsFalling(true);
				collidedBalls[i]->StartConcectionFall();
			}
		}
	}

	void Ball::SetRad(float rad)
	{
		this->rad = rad;
	}

	Vector2 Ball::GetTrajectory()
	{
		return trajectory;
	}

	BallColors Ball::GetColor()
	{
		return this->color;
	}

	EntityType Ball::GetBallType()
	{
		return this->type;
	}

	void Ball::SetTrajectoy(Vector2 trajectory)
	{
		this->trajectory = trajectory;
	}

	void Ball::SetPos(Vector2 pos)
	{
		this->pos = pos;
	}

	void Ball::SetIsFalling(bool isFalling)
	{
		this->isFalling = isFalling;
	}

	void Ball::SetCanColide(bool canColide)
	{
		this->canColide = canColide;
	}

	void Ball::SetDirection(Directions newDirection)
	{
		currentDirection = newDirection;
	}

	float Ball::GetRad()
	{
		return rad;
	}

	float Ball::GetPosX()
	{
		return pos.x;
	}

	float Ball::GetPosY()
	{
		return pos.y;
	}

	bool Ball::GetIsFalling()
	{
		return isFalling;
	}

	bool Ball::GetCanColide()
	{
		return canColide;
	}

	int Ball::GetColidedBallsSize()
	{
		return collidedBalls.size();
	}

	Color Ball::GetBallColor()
	{
		return ballColor;
	}

	std::vector<Ball*> Ball::GetCollidedBalls()
	{
		return collidedBalls;
	}

	Vector2 Ball::GetPos()
	{
		return pos;
	}

	Directions Ball::GetDirection()
	{
		return currentDirection;
	}
}