#include "Player/player.h"

namespace WFB
{

	Player::Player(Vector2 pos, EntityType type, float speed, float points, float width, float height, int lifes) : Entity(pos, type, speed, points)
	{
		this->pos = pos;
		this->type = type;
		this->speed.x = speed;
		this->speed.y = speed;
		this->points = points;
		rec.width = width;
		rec.height = height;
		rec.x = pos.x;
		rec.y = pos.y;
		this->lives = lifes;
		normalizedDirection = Vector2{ 0.0f,0.0f };
		rotation = 0.0f;

		this->canShoot = false;


		std::cout << "A new Player was Created" << std::endl;
	}
	Player::~Player()
	{
		std::cout << "The Player was Destroyed" << std::endl;
	}

	void Player::SetRotation(float newRotation)
	{
		rotation = newRotation;
	}

	void Player::SetDirection(Vector2 newDirection)
	{
		normalizedDirection = newDirection;
	}

	void Player::SetActualBallTrajectory(Vector2 trajectory)
	{
		actualBall->SetTrajectoy(trajectory);
	}

	void Player::SetActualBallRad(float rad)
	{
		actualBall->SetRad(rad);
	}

	void Player::SetActualBallPos(Vector2 pos)
	{
		actualBall->SetPos(pos);
	}

	void Player::SetActualBall(Ball* ball)
	{
		this->actualBall = ball;
	}

	void Player::Draw()
	{
		Vector2 origin;
		origin.x = rec.width / 2;
		origin.y = rec.height / 2;

		DrawRectanglePro(rec, origin, rotation, GREEN);

	}
	void Player::Movement()
	{

	}



	float Player::GetRotation()
	{
		return rotation;
	}

	float Player::GetXPosition()
	{
		return pos.x;
	}

	float Player::GetYPosition()
	{
		return pos.y;
	}

	Vector2 Player::GetDirection()
	{
		return normalizedDirection;
	}

	Vector2 Player::GetPosition()
	{
		return pos;
	}

	Rectangle Player::GetPlayerRect()
	{
		return rec;
	}

	Ball* Player::GetActualBall()
	{
		return actualBall;
	}

	float Player::GetWidth()
	{
		return rec.width;
	}

	float Player::GetHeight()
	{
		return rec.height;
	}

	float Player::GetSpeed()
	{
		return speed.x;
	}

	void Player::SetSpeed(float newSpeed)
	{
		speed.x = newSpeed;
		speed.y = newSpeed;
	}

	bool Player::GetCanShoot()
	{
		return canShoot;
	}

	void Player::SetCanShoot(bool canShoot)
	{
		this->canShoot = canShoot;
	}
}