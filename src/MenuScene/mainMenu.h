#pragma once
#include "GameScene/gameScene.h"

class MainMenu: public GameScene
{
private:
public:
	MainMenu();
	~MainMenu();
	void ExecuteScene() override;
	void Draw() override;
	void Update() override;
	void Input() override;
	void AddButton(Button* newButton) override;
};