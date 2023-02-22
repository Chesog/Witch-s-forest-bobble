#pragma once
#include <iostream>
#include "GameScene/gameScene.h"

class MainMenu: public GameScene
{
private:
	SceneType selectionScene;

public:
	MainMenu();
	~MainMenu();
	SceneType ExecuteScene() override;
	void Draw() override;
	void Update() override;
	void Input() override;
	void AddButton(Button* newButton) override;
	void CheckButtonState();
};