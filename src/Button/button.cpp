#include <iostream>
#include "Button/button.h"

Button::Button(Vector2 pos, float width, float height, Color buttonColor, Color buttonSelectionColor)
{
	rec.x = pos.x;
	rec.y = pos.y;
	rec.width = width;
	rec.height = height;
	this->buttonColor = buttonColor;
	this->buttonSelectionColor = buttonSelectionColor;
	mouseOver = false;
	buttonPresed = false;

	std::cout << "A New Button Was Created" << std::endl;
}

Button::~Button()
{
	std::cout << "The Button Was Destroyed" << std::endl;
}
void Button::DrawButton()
{
	if (mouseOver)
	{
		DrawRectangle(rec.x, rec.y, rec.width, rec.height, buttonSelectionColor);
	}
	else
	{
		DrawRectangle(rec.x, rec.y, rec.width, rec.height, buttonColor);
	}
}

void Button::SetButtonPresed(bool buttonPresed)
{
	this->buttonPresed = buttonPresed;
}

void Button::SetMouseOver(bool mouseOver)
{
	this->mouseOver = mouseOver;
}

bool Button::IsButtonPressed()
{
	return buttonPresed;
}

Vector2 Button::GetButtonPos()
{
	Vector2 buttonPos = {rec.x,rec.y};
	return buttonPos;
}