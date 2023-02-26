#pragma once
#include <iostream>
#include "GameScene/gameScene.h"


class Credits : public GameScene
{
private:

	Texture2D instaL;
	Texture2D instaM;
	Texture2D instaP;

	Texture2D gitE;
	Texture2D youtC;
	Texture2D gitD;
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