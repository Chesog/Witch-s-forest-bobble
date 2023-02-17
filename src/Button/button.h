#pragma once
#include "raylib.h"

class Button
{
private:
	Rectangle rec;
	bool mouseOver;
	bool buttonPresed;
	Color buttonColor;
	Color buttonSelectionColor;
	
public:
	Button(Vector2 pos,float width,float height,Color buttonColor, Color buttonSelectionColor);
	~Button();
	void DrawButton();
	void SetButtonPresed(bool buttonPresed);
	void SetMouseOver(bool mouseOver);
	bool IsButtonPressed();
	Vector2 GetButtonPos();
};