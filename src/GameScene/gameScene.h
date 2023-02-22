#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "GlobalUtilities/globalUtilities.h"
#include "Button/button.h"

class GameScene
{
protected:
	std::vector<Button*> sceneButtons;
public:
	GameScene();
	virtual ~GameScene();
	virtual SceneType ExecuteScene() = 0;
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void Input() = 0;
	virtual void AddButton(Button* newButton) = 0;
};