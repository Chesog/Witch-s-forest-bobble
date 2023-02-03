#pragma once
#include "Entity/entity.h"
#include "raylib.h"

enum class BallColors { Red, Yellow, White, Blue };


class Ball : public Entity
{
private:
	float rad;
	Color ballColor;
	Directions currentDirection;
	Vector2 trajectory;
public:
	Ball(Vector2 pos,Vector2 trajectory, EntityType type, float speed, float points, float rad,Color ballColor);
	~Ball();

	void SetDirection(Directions newDirection);
	void SetTrajectoy(Vector2 trajectory);
	void Draw() override;
	void Movement() override;
	
	Directions GetDirection();
};

