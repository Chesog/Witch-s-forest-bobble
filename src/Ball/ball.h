#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "Entity/entity.h"

enum class BallColors { Red, Yellow, Purple, Blue ,Green,Orange};

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
	Texture ballTexture;

public:
	Ball(Vector2 pos,Vector2 trajectory, EntityType type, float speed, float points, float rad,Color ballColor,BallColors color, Texture2D ballTexture);
	~Ball();

	void SetDirection(Directions newDirection);
	void SetTrajectoy(Vector2 trajectory);
	void SetPos(Vector2 pos);
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

