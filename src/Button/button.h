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
	
public:
	Button(Vector2 pos,float width,float height,Color buttonColor, Color buttonSelectionColor, SceneType buttonType);
	~Button();
	void DrawButton();
	void SetButtonPresed(bool buttonPresed);
	void SetMouseOver(bool mouseOver);
	bool IsButtonPressed();

	Rectangle GetButtonRec();
	SceneType GetButtonType();
	Vector2 GetButtonPos();
};