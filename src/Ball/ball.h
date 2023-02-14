#pragma once
#include "Entity/entity.h"
#include "raylib.h"
#include <vector>

enum class BallColors { Red, Yellow, White, Blue };

using namespace std;

class Ball : public Entity
{
private:
	bool isFalling;
	bool canColide;
	float rad;
	Color ballColor;
	Directions currentDirection;
	Vector2 trajectory;
	BallColors color;
	vector <Ball*> collidedBalls;

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
	EntityType GetBallType();

	int GetColidedBallsSize();

	bool GetIsFalling();
	bool GetCanColide();

	BallColors GetColor();
	Color GetBallColor();

	vector <Ball*> GetCollidedBalls();
	Vector2 GetTrajectory();
	Vector2 GetPos();
	Directions GetDirection();
};

