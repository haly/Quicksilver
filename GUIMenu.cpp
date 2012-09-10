#include "GUIMenu.h"


GUIMenu::GUIMenu(void)
{
}


GUIMenu::~GUIMenu(void)
{
}

/****************************************************************
* Iterate through every button to check whether the mouse is 
* hovering over it
****************************************************************/
void GUIMenu::checkSelected(float mouseX, float mouseY)
{
	// Iterate through every button to check whether the mouse is hovering over it
	// Selected buttons are drawn with green text
	for (int i = 0; i < (int)buttonList.size(); i++)
	{
		if (buttonList[i]->isHover(mouseX, mouseY))
			buttonList[i]->setSelected(true);
		else
			buttonList[i]->setSelected(false);
	}
}

/****************************************************************
* Returns an enum indicating which button was just 
* clicked/activated
****************************************************************/
int GUIMenu::getFunction(bool clicked)
{
	if (clicked)
	{
		for (int i = 0; i < (int)buttonList.size(); i++)
		{
			if (buttonList[i]->getSelected())
				return buttonList[i]->getFunction();
		}
	}

	return NULL_FUNCTION;
}