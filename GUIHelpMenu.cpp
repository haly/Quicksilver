#include "GUIHelpMenu.h"

/****************************************************************
* Default constructor
****************************************************************/
GUIHelpMenu::GUIHelpMenu(void)
{
	init();
}


GUIHelpMenu::~GUIHelpMenu(void)
{

}

/****************************************************************
* Initializes menu components
****************************************************************/
void GUIHelpMenu::init(void)
{
	// Set state
	gameState = PAUSED;

	// Determine the center coordinates of the screen
	float halfWidth = GraphicsManager::Instance()->screenWidth/2;
	float halfHeight = GraphicsManager::Instance()->screenHeight/2;

	// Load textures
	bg = new Sprite("black.png", 0, 0, NORMAL);
	bg->translate(D3DXVECTOR2(halfWidth, halfHeight));
	bg->scale(D3DXVECTOR2(halfWidth * 2, halfHeight * 2));

	help = new Sprite("help.png", 0, 0, NORMAL);
	help->translate(D3DXVECTOR2(halfWidth, halfHeight));
	help->scale(D3DXVECTOR2(halfWidth * 2, halfHeight * 2));

	// Initialize buttons unique to the Help Menu
	back = new GUIButton(halfWidth + 425, halfHeight + 300, 100, 30, MEDIUM_ORATOR, "Back [ESC]", DT_CENTER, POP_MENU);

	// Add to storage
	buttonList.push_back(back);
}

/****************************************************************
* Update cycle, handles mouse events and any animation
****************************************************************/
void GUIHelpMenu::update(float mouseX, float mouseY, bool clicked, float deltaTime)
{
	// Iterate through every button to check whether the mouse is hovering over it
	// Selected buttons are drawn with white text, unselected buttons are drawn with grey text
	checkSelected(mouseX, mouseY);
}

/****************************************************************
* Draws all menu components
****************************************************************/
void GUIHelpMenu::draw(void)
{
	// Draw the background
	bg->Draw();
	help->Draw();
	// Draw all labels and buttons
	for (int i = 0; i < (int)labelList.size(); i++)
		labelList[i]->draw();

	for (int i = 0; i < (int)buttonList.size(); i++)
		buttonList[i]->draw();
}