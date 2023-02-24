#pragma once
#include <iostream>
#include "GameScene/gameScene.h"


class Credits : public GameScene
{
private:
	SceneType selectionScene;
	Font sceneFont;
public:
	Credits();
	~Credits();
	SceneType ExecuteScene() override;
	void Draw() override;
	void Update() override;
	void Input() override;
	void ResetScene() override;
	void AddButton(Button* newButton) override;
	void CheckButtonState();
};