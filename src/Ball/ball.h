#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "Entity/entity.h"

enum class BallColors { Red, Yellow, White, Blue };

class Ball : public Entity
{
private:
	bool isFalling;
	bool canColide;
	float rad;
	Color ballColor;
	Directions currentDirection;
	BallColors color;
	std::vector<Ball*> collidedBalls;
	Vector2 trajectory;

public:
	Ball(Vector2 pos,Vector2 trajectory, EntityType type, float speed, float points, float rad,Color ballColor,BallColors color);
	~Ball();

	void SetDirection(Directions newDirection);
	void SetTrajectoy(Vector2 trajectory);
	void SetIsFalling(bool isFalling);
	void SetCanColide(bool canColide);
	void SetRad(float rad);
	void AddCollidedBall(Ball* ball);
	void StartConcectionFall();
	void Draw() override;
	void Movement() override;

	float GetRad();
	float GetPosX();
	float GetPosY();

	int GetColidedBallsSize();

	bool GetIsFalling();
	bool GetCanColide();

	BallColors GetColor();

	Color GetBallColor();

	EntityType GetBallType();

	std::vector<Ball*> GetCollidedBalls();

	Vector2 GetTrajectory();
	Vector2 GetPos();

	Directions GetDirection();
};

