#include "GUITitleMenu.h"

/****************************************************************
* Default constructor
****************************************************************/
GUITitleMenu::GUITitleMenu(void)
{
	init();
}


GUITitleMenu::~GUITitleMenu(void)
{

}

/****************************************************************
* Initializes menu components
****************************************************************/
void GUITitleMenu::init(void)
{
	// Set state
	gameState = TITLE;

	// Determine the center coordinates of the screen
	float halfWidth = GraphicsManager::Instance()->screenWidth/2;
	float halfHeight = GraphicsManager::Instance()->screenHeight/2;

	// Load textures
	logo = new Sprite("logotransparent.png", 0, 0, NORMAL);
	logoX = halfWidth;
	logoY = halfHeight - 100;
	logo->translate(D3DXVECTOR2(logoX, logoY));
	logo->scale(D3DXVECTOR2(762 * 0.7f, 472 * 0.7f));
	logo->rotate(0);

	symbol = new Sprite("symbolDarkGray.png", 0, 0, NORMAL);
	symbolX = halfWidth + 250;
	symbolY = halfHeight - 175;
	symbol->translate(D3DXVECTOR2(symbolX, symbolY));
	symbol->scale(D3DXVECTOR2(140 * 0.5f, 290 * 0.5f));
	symbol->rotate(0);

	// Initialize buttons unique to the Title Menu
	start = new GUIButton(halfWidth - 50, halfHeight+125, 100, 30, MEDIUM_ORATOR, "New Game", DT_CENTER, START_GAME);
	instruct = new GUIButton(halfWidth - 50, halfHeight+175, 100, 30, MEDIUM_ORATOR, "How To Play", DT_CENTER, PUSH_HELP);
	quit = new GUIButton(halfWidth - 50, halfHeight+225, 100, 30, MEDIUM_ORATOR, "Quit", DT_CENTER, TO_DESKTOP);

	// Add to storage
	buttonList.push_back(start);
	buttonList.push_back(instruct);
	buttonList.push_back(quit);
}

/****************************************************************
* Update cycle, handles mouse events and any animation
****************************************************************/
void GUITitleMenu::update(float mouseX, float mouseY, bool clicked, float deltaTime)
{
	// Iterate through every button to check whether the mouse is hovering over it
	// Selected buttons are drawn with white text, unselected buttons are drawn with grey text
	checkSelected(mouseX, mouseY);
}

/****************************************************************
* Draws all menu components
****************************************************************/
void GUITitleMenu::draw(void)
{
	// Draw all labels and buttons
	for (int i = 0; i < (int)labelList.size(); i++)
		labelList[i]->draw();

	for (int i = 0; i < (int)buttonList.size(); i++)
		buttonList[i]->draw();

	// Draw the symbol (maybe create its own class/function)
	symbol->Draw();

	// Draw the logo (maybe create its own class/function)
	logo->Draw();
}
