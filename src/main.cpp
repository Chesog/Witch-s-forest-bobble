#include "Game/game.h"

int main() 
{
	Game* game = new Game();
	game->ExecuteGame();

	delete game;

	return 0;
}