#include "GUIButton.h"

/****************************************************************
* Default constructor, initializes all values to their default
****************************************************************/
GUIButton::GUIButton()
{
	posX = 0;
	posY = 0;
	buttonWidth = 0;
	buttonHeight = 0;
	buttonSize = SMALL_FONT;
	buttonText = "";
	selected = false;
	textFormat = DT_CENTER;
	buttonFunction = NULL_FUNCTION;
}

/****************************************************************
* Parameterized constructor
* Input: x coordinate, y coordinate, width of hitbox, height of hitbox, size of font, text on button
****************************************************************/
GUIButton::GUIButton(float x, float y, float width, float height, int size, string text, int format, int function)
{
	posX = x;
	posY = y;
	buttonWidth = width;
	buttonHeight = height;
	buttonSize = size;
	buttonText = text;
	selected = false;
	textFormat = format;
	buttonFunction = function;
}


GUIButton::~GUIButton(void)
{
}

/****************************************************************
* Draws the button depending on whether it was selected
****************************************************************/
void GUIButton::draw(void)
{
	if (!selected)
		GraphicsManager::Instance()->DrawText(buttonText, buttonSize, posX, posY, posX + buttonWidth, posY + buttonHeight, 0.7f, 0.7f, 0.7f, 1.0f, textFormat);
	else
		GraphicsManager::Instance()->DrawText(buttonText, buttonSize, posX, posY, posX + buttonWidth, posY + buttonHeight, 1.0f, 1.0f, 1.0f, 1.0f, textFormat);
}

/****************************************************************
* Checks whether the current position of the mouse is hovering over this button
****************************************************************/
bool GUIButton::isHover(float mouseX, float mouseY)
{
	if (mouseX > posX &&
		mouseX < posX + buttonWidth &&
		mouseY > posY &&
		mouseY < posY + buttonHeight)
	{
		return true;
	}
	return false;
}