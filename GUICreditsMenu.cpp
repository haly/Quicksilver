#include "GUICreditsMenu.h"

/****************************************************************
* Default constructor
****************************************************************/
GUICreditsMenu::GUICreditsMenu(void)
{
	init();
}


GUICreditsMenu::~GUICreditsMenu(void)
{

}

/****************************************************************
* Initializes menu components
****************************************************************/
void GUICreditsMenu::init(void)
{
	// Set state
	gameState = CREDITS;

	// Determine the center coordinates of the screen
	float halfWidth = GraphicsManager::Instance()->screenWidth/2;
	float halfHeight = GraphicsManager::Instance()->screenHeight/2;

	// Load textures
	bg = new Sprite("black.png", 0, 0, NORMAL);
	bg->translate(D3DXVECTOR2(halfWidth, halfHeight));
	bg->scale(D3DXVECTOR2(halfWidth * 2, halfHeight * 2));

	// Initialize buttons unique to the Credits Menu
	endmsg = new GUIButton(halfWidth - 50, halfHeight - 300, 100, 50, LARGE_ORATOR, "", DT_CENTER, NULL_FUNCTION);
	next = new GUIButton(halfWidth - 150, halfHeight - 200, 300, 30, MEDIUM_ORATOR, "Click to go to the Next Level", DT_CENTER, NEXT_LEVEL);

	credits = new GUIButton(halfWidth - 50, halfHeight - 150, 100, 50, LARGE_ORATOR, "Credits", DT_CENTER, NULL_FUNCTION);
	clark = new GUIButton(halfWidth - 50, halfHeight - 50, 100, 50, MEDIUM_ORATOR, "Lead Designer/Programmer - Daniel Clark", DT_CENTER, NULL_FUNCTION);
	mcshane = new GUIButton(halfWidth - 50, halfHeight - 0, 100, 50, MEDIUM_ORATOR, "Controls and Enemies Programmer - Michael McShane", DT_CENTER, NULL_FUNCTION);
	sadwin = new GUIButton(halfWidth - 50, halfHeight + 50, 100, 50, MEDIUM_ORATOR, "Player Programmer and Animation - Allyson Sadwin", DT_CENTER, NULL_FUNCTION);
	scott = new GUIButton(halfWidth - 50, halfHeight + 100, 100, 50, MEDIUM_ORATOR, "Level Designer/Programmer - Daniel Scott", DT_CENTER, NULL_FUNCTION);
	yuan = new GUIButton(halfWidth - 50, halfHeight + 150, 100, 50, MEDIUM_ORATOR, "GUI Designer/Programmer - Francis Yuan", DT_CENTER, NULL_FUNCTION);
	
	title = new GUIButton(halfWidth - 150, halfHeight + 250, 300, 30, MEDIUM_ORATOR, "Click to return to Title", DT_CENTER, TO_TITLE);

	// Add to storage
	labelList.push_back(endmsg);
	labelList.push_back(credits);
	labelList.push_back(clark);
	labelList.push_back(mcshane);
	labelList.push_back(sadwin);
	labelList.push_back(scott);
	labelList.push_back(yuan);

	buttonList.push_back(next);
	buttonList.push_back(title);
}

/****************************************************************
* Update cycle, handles mouse events and any animation
****************************************************************/
void GUICreditsMenu::update(float mouseX, float mouseY, bool clicked, float deltaTime)
{
	// Iterate through every button to check whether the mouse is hovering over it
	// Selected buttons are drawn with white text, unselected buttons are drawn with grey text
	checkSelected(mouseX, mouseY);
}

/****************************************************************
* Draws all menu components
****************************************************************/
void GUICreditsMenu::draw(void)
{
	// Draw the background
	bg->Draw();

	// Draw all labels and buttons
	for (int i = 0; i < (int)labelList.size(); i++)
		labelList[i]->draw();

	for (int i = 0; i < (int)buttonList.size(); i++)
		buttonList[i]->draw();
}
/****************************************************************
* Sets the header message for the credits screen
****************************************************************/
void GUICreditsMenu::setMessage(string text)
{
	endmsg->setText(text);
}