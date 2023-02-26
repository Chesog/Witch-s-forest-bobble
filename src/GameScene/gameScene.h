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
	SceneType selectionScene;
	Texture2D sceneBackground;
	Texture2D sceneBackground2;
	Texture2D cursorTexture;
	Font sceneFont;
	Font sceneTextFont;
	Vector2 sceneBackgroundPos;
	float sceneBackgroundRotation;
	float sceneBackgroundScale;
	Color sceneBackgroundTint;
public:
	GameScene();
	virtual ~GameScene();
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void Input() = 0;
	virtual void ResetScene() = 0;
	virtual void AddButton(Button* newButton) = 0;
	virtual SceneType ExecuteScene() = 0;
};