#include "Game/game.h"
using namespace WFB;

int main() 
{
	Game* game = new Game();
	game->ExecuteGame();

	delete game;

	return 0;
}