#pragma once
#include <iostream>
#include "GameScene/gameScene.h"

namespace WFB
{
	class MainMenu : public GameScene
	{
	private:
		SceneType selectionScene;
	public:
		MainMenu();
		~MainMenu();
		SceneType ExecuteScene(float& volume) override;
		void Draw() override;
		void Update() override;
		void Input() override;
		void ResetScene() override;
		void AddButton(Button* newButton) override;
		float GetVolumeMusic() override;
		void SetVolumeMusic(float newVolume) override;
		void CheckButtonState();
	};
}