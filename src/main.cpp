#include "Game/game.h"

int main() 
{
	Game* game = new Game();
	game->GameLoop();

	delete game;

	return 0;
}