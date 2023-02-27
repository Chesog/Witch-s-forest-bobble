#pragma once
#include <iostream>
#include "GameScene/gameScene.h"


class Options : public GameScene
{
private:
	SceneType selectionScene;
	Font sceneFont;
public:
	Options();
	~Options();
	SceneType ExecuteScene(float& volume) override;
	void Draw() override;
	void Update() override;
	void Input() override;
	void ResetScene() override;
	void AddButton(Button* newButton) override;
	void CheckButtonState();
	void SetVolumeMusic(float newVolume) override;
	float GetVolumeMusic() override;
};