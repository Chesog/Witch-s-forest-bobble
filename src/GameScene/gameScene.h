#pragma once
#include <iostream>
#include <vector>
#include "raylib.h"
#include "GlobalUtilities/globalUtilities.h"
#include "Button/button.h"

namespace WFB
{

	class GameScene
	{
	protected:
		std::vector<Button*> sceneButtons;

		SceneType selectionScene;

		Texture2D sceneBackground;
		Texture2D sceneBackground2;
		Texture2D cursorTexture;

		Music sceneMusic;

		Font sceneFont;
		Font sceneTextFont;

		Vector2 sceneBackgroundPos;

		Color sceneBackgroundTint;

		float volume;

		float sceneBackgroundRotation;
		float sceneBackgroundScale;

	public:
		GameScene();
		virtual ~GameScene();
		virtual void Draw() = 0;
		virtual void Update() = 0;
		virtual void Input() = 0;
		virtual void ResetScene() = 0;
		virtual void AddButton(Button* newButton) = 0;
		virtual void SetVolumeMusic(float newVolume) = 0;
		virtual float GetVolumeMusic() = 0;
		virtual SceneType ExecuteScene(float& volume) = 0;
	};
}