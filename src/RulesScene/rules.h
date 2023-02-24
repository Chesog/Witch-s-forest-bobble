#pragma once
#include <iostream>
#include "GameScene/gameScene.h"


class Rules : public GameScene
{
private:
	SceneType selectionScene;
	Font sceneFont;
public:
	Rules();
	~Rules();
	SceneType ExecuteScene() override;
	void Draw() override;
	void Update() override;
	void Input() override;
	void ResetScene() override;
	void AddButton(Button* newButton) override;
	void CheckButtonState();
};