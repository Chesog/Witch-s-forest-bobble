#include "Entity/entity.h"
#include "raylib.h"

class Ball : public Entity
{
private:
	float rad;
public:
	Ball(Vector2 pos, EntityType type, float speed, float points, float rad);
	~Ball();
};

