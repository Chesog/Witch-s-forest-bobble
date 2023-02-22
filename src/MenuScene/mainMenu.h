#pragma once
#include <iostream>
#include "GameScene/gameScene.h"

class MainMenu: public GameScene
{
private:
	bool gameplay;
	bool rules;
	bool options;
	bool credits;
	bool exit;

public:
	MainMenu();
	~MainMenu();
	SceneType ExecuteScene() override;
	void Draw() override;
	void Update() override;
	void Input() override;
	void AddButton(Button* newButton) override;
};