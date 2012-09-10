#pragma once

// Libraries
#include <d3d10.h>
#include <d3dx10.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>    // for wstringstream
#include <istream>
#include <iostream>
#include <vector>
#include "Game.h"

// Local
#include "GraphicsManager.h"
#include "InputManager.h"
#include "GUIEnum.h"

// Menus
#include "GUIMenu.h"
#include "GUITitleMenu.h"
#include "GUILoadingMenu.h"
#include "GUIPauseMenu.h"
#include "GUIDialogMenu.h"
#include "GUIQuitMenu.h"
#include "GUICreditsMenu.h"
#include "GUIHelpMenu.h"

// Class declarations
class Game;

class GUIManager
{
public:
	GUIManager(void);
	~GUIManager(void);

	// Returns the singleton instance of the GUI Manager
	static GUIManager* Instance();
	
	// Initializes all game menus and other UI elements
	void InitGUI(Game *game);

	// Recieves and responds to information from the InputManager and the Game engine
	void Update(float deltaTime);

	// Draws current menu elements
	void Draw();

	// Responds to functions from the top menu on the menu stack
	void doFunction(int function);

	// A shortcut that opens the dialog menu with the given speaker and textual content
	void say(string speaker, string content, int timeInSeconds);

	// Accessors
	int getGameState()		{return gameState;}
	int isPaused()			{return gameState == PAUSED;}

private:
	// Singleton Instance
	static GUIManager* instance;

	// Current game state
	int gameState;
	Game *gameInstance;

	// Menus
	GUITitleMenu *titleMenu;
	GUIPauseMenu *pauseMenu;
	GUIDialogMenu *dialogMenu;
	GUILoadingMenu *loadingMenu;
	GUIQuitMenu *quitMenu;
	GUICreditsMenu *creditsMenu;
	GUIHelpMenu *helpMenu;
	vector<GUIMenu*> menuStack;

	// Screen dimentions
	float screenWidth;
	float screenHeight;

	// Other UI elements
	Sprite *crosshair;

	// Misc flags to manage UI function
	string levelToLoad;
	bool showCursor;

	// Skips title screen
	void debugMode();
};