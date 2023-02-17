#pragma once
#include <vector>
#include "raylib.h"
#include "Button/button.h"

using namespace std;

class GameScene
{
private:
	vector <Button*> buttons;
public:
	GameScene();
	virtual ~GameScene();
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void Input() = 0;
	virtual void AddButton(Button* newButton) = 0;
};