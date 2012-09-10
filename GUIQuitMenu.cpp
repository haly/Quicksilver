#include "GUIQuitMenu.h"


GUIQuitMenu::GUIQuitMenu(void)
{
	init();
}


GUIQuitMenu::~GUIQuitMenu(void)
{
}

/****************************************************************
* Initializes menu components
****************************************************************/
void GUIQuitMenu::init(void)
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

	// Initialize buttons unique to the Pause Menu
	quit = new GUIButton(halfWidth - 50, halfHeight - 125, 100, 30, LARGE_ORATOR, "Quit?", DT_CENTER, NULL_FUNCTION);
	title = new GUIButton(halfWidth - 50, halfHeight, 100, 30, MEDIUM_ORATOR, "Title Screen", DT_CENTER, TO_TITLE);
	desktop = new GUIButton(halfWidth - 50, halfHeight + 50, 100, 30, MEDIUM_ORATOR, "Desktop", DT_CENTER, TO_DESKTOP);
	back = new GUIButton(halfWidth - 50, halfHeight + 150, 100, 30, MEDIUM_ORATOR, "Back [ESC]", DT_CENTER, POP_MENU);

	// Add to storage
	labelList.push_back(quit);
	buttonList.push_back(title);
	buttonList.push_back(desktop);
	buttonList.push_back(back);
}

/****************************************************************
* Update cycle, handles mouse events and any animation
****************************************************************/
void GUIQuitMenu::update(float mouseX, float mouseY, bool clicked, float deltaTime)
{
	// Iterate through every button to check whether the mouse is hovering over it
	// Selected buttons are drawn with white text, unselected buttons are drawn with grey text
	checkSelected(mouseX, mouseY);
}

/****************************************************************
* Draws all menu components
****************************************************************/
void GUIQuitMenu::draw(void)
{
	// Draw the background
	bg->Draw();

	// Draw all labels and buttons
	for (int i = 0; i < (int)labelList.size(); i++)
		labelList[i]->draw();

	for (int i = 0; i < (int)buttonList.size(); i++)
		buttonList[i]->draw();
}

