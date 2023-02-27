#pragma once
#include "raylib.h"
#include "GlobalUtilities/globalUtilities.h"

class Button
{
private:
	Rectangle rec;
	bool mouseOver;
	bool buttonPresed;
	Color buttonColor;
	Color buttonSelectionColor;
	SceneType buttonType;
	Texture2D buttonTexture;
	
public:
	Button(Vector2 pos,float width,float height,Color buttonColor, Color buttonSelectionColor, SceneType buttonType, Texture2D buttonTexture);
	~Button();
	void DrawButton();
	void DrawButtonWhitScale(float scale);
	void SetButtonPresed(bool buttonPresed);
	void SetMouseOver(bool mouseOver);
	bool IsButtonPressed();

	Rectangle GetButtonRec();
	SceneType GetButtonType();
	Vector2 GetButtonPos();
};