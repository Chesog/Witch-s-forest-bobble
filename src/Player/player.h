#pragma once
#include <iostream>
#include "raylib.h"
#include "Entity/entity.h"
#include "Ball/ball.h"

class Player : public Entity
{
private:
	Rectangle rec;
	Ball* actualBall;
	float rotation;

	int lives;

	bool canShoot;

	Vector2 normalizedDirection;
public:
	Player(Vector2 pos, EntityType type, float speed, float points, float width, float height, int lives);
	~Player();

	void Draw() override;
	void Movement() override;
	void SetRotation(float newRotation);
	void SetDirection(Vector2 newDirection);
	void SetCanShoot(bool canShoot);
	void SetSpeed(float newSpeed);
	void SetActualBall(Ball* ball);
	void SetActualBallTrajectory(Vector2 trajectory);
	void SetActualBallRad(float rad);
	void SetActualBallPos(Vector2 pos);

	float GetRotation();
	float GetXPosition();
	float GetYPosition();
	float GetSpeed();
	float GetWidth();
	float GetHeight();

	bool GetCanShoot();

	Vector2 GetDirection();
	Vector2 GetPosition();

	Rectangle GetPlayerRect();
};