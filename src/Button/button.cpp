#include <iostream>
#include "Button/button.h"

Button::Button(Vector2 pos, float width, float height, Color buttonColor, Color buttonSelectionColor, SceneType buttonType, Texture2D buttonTexture)
{
	rec.x = pos.x;
	rec.y = pos.y;
	rec.width = width;
	rec.height = height;
	this->buttonColor = buttonColor;
	this->buttonSelectionColor = buttonSelectionColor;
	this->buttonType = buttonType;
	mouseOver = false;
	buttonPresed = false;
	
	this->buttonTexture = buttonTexture;

	std::cout << "A New Button Was Created" << std::endl;
}

Button::~Button()
{
	UnloadTexture(buttonTexture);
	std::cout << "The Button Was Destroyed" << std::endl;
}
void Button::DrawButton()
{
	if (mouseOver)
	{
		DrawTextureEx(buttonTexture, {rec.x,rec.y},5.0f,1.0f,WHITE);
	}
	else
	{
		DrawTextureEx(buttonTexture, { rec.x,rec.y }, 0.0f, 1.0f, WHITE);
	}
}

void Button::DrawButtonWhitScale(float scale)
{
	if (mouseOver)
	{
		DrawTextureEx(buttonTexture, { rec.x,rec.y }, 5.0f, scale, WHITE);
	}
	else
	{
		DrawTextureEx(buttonTexture, { rec.x,rec.y }, 0.0f, scale, WHITE);
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

Rectangle Button::GetButtonRec()
{
	return rec;
}

SceneType Button::GetButtonType()
{
	return buttonType;
}

Vector2 Button::GetButtonPos()
{
	Vector2 buttonPos = {rec.x,rec.y};
	return buttonPos;
}