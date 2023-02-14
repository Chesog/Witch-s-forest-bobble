#pragma once
#include "raylib.h"

class Button
{
private:
	Rectangle rec;
	bool mouseOver;
	Color buttonColor;
	Color buttonSelectionColor;
	
public:
	Button(Vector2 pos,float width,float height,Color buttonColor, Color buttonSelectionColor);
	~Button();
	void DrawButton();
	bool IsButtonPressed();
};