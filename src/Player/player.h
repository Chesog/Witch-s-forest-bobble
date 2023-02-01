#pragma once
#include "Entity/entity.h"

class Player : public Entity
{
private:
	Rectangle rec;
	float rotation;

	int lives;

	Vector2 normalizedDirection;
public:
	Player(Vector2 pos, EntityType type, float speed, float points, float width, float height, int lives);
	~Player();

	void SetRotation(float newRotation);
	void SetDirection(Vector2 newDirection);
	void Draw() override;
	void Movement() override;

	float GetRotation();
	float GetXPosition();
	float GetYPosition();
	float GetWidth();
	float GetHeight();

	Vector2 GetDirection();
	Vector2 GetPosition();

	Rectangle GetPlayerRect();
};