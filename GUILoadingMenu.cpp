#include "GUILoadingMenu.h"


GUILoadingMenu::GUILoadingMenu(void)
{
	init();
}


GUILoadingMenu::~GUILoadingMenu(void)
{
}

/****************************************************************
* Initializes menu components
****************************************************************/
void GUILoadingMenu::init(void)
{
	// Set state
	gameState = LOADING;

	// Determine the center coordinates of the screen
	float halfWidth = GraphicsManager::Instance()->screenWidth/2;
	float halfHeight = GraphicsManager::Instance()->screenHeight/2;

	// Loading textures
	bg = new Sprite("black.png", 0, 0, NORMAL);
	bg->translate(D3DXVECTOR2(halfWidth, halfHeight));
	bg->scale(D3DXVECTOR2(halfWidth * 2, halfHeight * 2));

	// Initialize buttons unique to the Pause Menu
	loading = new GUIButton(halfWidth * 2 - 175, halfHeight*2 - 100, 0, 0, LARGE_ORATOR, "Loading...", DT_CENTER, NULL_FUNCTION);

	// Add to storage
	labelList.push_back(loading);
}

/****************************************************************
* Update cycle, handles mouse events and any animation
****************************************************************/
void GUILoadingMenu::update(float mouseX, float mouseY, bool clicked, float deltaTime)
{
	// Iterate through every button to check whether the mouse is hovering over it
	// Selected buttons are drawn with white text, unselected buttons are drawn with grey text
	checkSelected(mouseX, mouseY);
}

/****************************************************************
* Draws all menu components
****************************************************************/
void GUILoadingMenu::draw(void)
{
	// Draw the background
	bg->Draw();

	// Draw all labels and buttons
	for (int i = 0; i < (int)labelList.size(); i++)
		labelList[i]->draw();

	for (int i = 0; i < (int)buttonList.size(); i++)
		buttonList[i]->draw();
}

