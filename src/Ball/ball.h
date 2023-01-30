#include "Entity/entity.h"
#include "raylib.h"

class Ball : public Entity
{
private:
	float rad;
	Directions currentDirection;
public:
	Ball(Vector2 pos, EntityType type, float speed, float points, float rad);
	~Ball();

	void SetDirection(Directions newDirection);
	void Draw() override;
	void Movement() override;
	
	Directions GetDirection();
};

