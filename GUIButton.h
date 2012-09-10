#pragma once

// Libraries
#include <string>

// Local
#include "GUIEnum.h"
#include "GraphicsManager.h"
#include "Sprite.h"

class GUIButton
{
public:
	// Initializes all values to their default
	GUIButton();

	// Parameterized constructor, x coordinate, y coordinate, width of hitbox, height of hitbox, size of font, text on button
	GUIButton(float x, float y, float width, float height, int size, string text, int format, int function);
	~GUIButton(void);

	// Draws the button with different colors depending on whether it is selected
	void draw();

	// Checks whether the current position of the mouse is hovering over this button
	bool isHover(float mouseX, float mouseY);

	// Accessors
	float getX(void)							{return posX;}
	float getY(void)							{return posY;}
	float getWidth(void)						{return buttonWidth;}
	float getHeight(void)						{return buttonHeight;}
	bool getSelected(void)						{return selected;}
	string getText(void)						{return buttonText;}
	int getFunction(void)						{return buttonFunction;}
	
	// Mutators
	void setSelected(bool isSelected)		{selected = isSelected;}
	void setText(string text)				{buttonText = text;}
	void setFormat(UINT format)				{textFormat = format;}

private:
	float posX;
	float posY;
	float buttonWidth;
	float buttonHeight;
	int buttonSize;
	bool selected;
	string buttonText;
	int buttonFunction;
	UINT textFormat;
};

