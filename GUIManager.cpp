#include "GUIManager.h"

// Global static pointer used to ensure a single instance of the class.
GUIManager* GUIManager::instance = NULL;
extern bool programQuitFlag;

/****************************************************************
* Default constructor
****************************************************************/
GUIManager::GUIManager()
{
	if (!GraphicsManager::Instance() != NULL)
	{
		// Get the screen dimensions from the GraphicsManager instance
		screenWidth = GraphicsManager::Instance()->screenWidth;
		screenHeight = GraphicsManager::Instance()->screenHeight;
	}
}

/****************************************************************
* Returns instance of GUIManager
****************************************************************/
GUIManager* GUIManager::Instance()
{
	// Iff an instance hasn't been created, create it now.
	if (!instance)
	{
		instance = new GUIManager;
	}

	return instance;
}


/****************************************************************
* Initializes all game menus and other UI elements
****************************************************************/
void GUIManager::InitGUI(Game * game)
{
	// Set the game instance
	gameInstance = game;

	// Load textures
	crosshair = new Sprite("crosshair.png", 0, 0, NORMAL);
	crosshair->scale(D3DXVECTOR2(32, 32));
	crosshair->rotate(0);

	// Preload all menus
	titleMenu = new GUITitleMenu();
	loadingMenu = new GUILoadingMenu();
	pauseMenu = new GUIPauseMenu();
	dialogMenu = new GUIDialogMenu();
	quitMenu = new GUIQuitMenu();
	creditsMenu = new GUICreditsMenu();
	helpMenu = new GUIHelpMenu();

	// Push the Title menu onto the menu stack
	doFunction(PUSH_TITLE);

	// Initiates misc flags just in case
	levelToLoad = "";
	showCursor = true;

	// Skips the title state and brings up the game immediately
	//debugMode();
}

/****************************************************************
* Recieves and responds to information from the InputManager and
* the Game engine
****************************************************************/
void GUIManager::Update(float deltaTime)
{
	// Check for end game flags
	if (LevelManager::Instance()->missionAccomplished())
	{
		creditsMenu->setMessage("You win!\nYour final score was" + LevelManager::Instance()->getScore());
		doFunction(PUSH_CREDITS);
	}
	else if (LevelManager::Instance()->missionFailed())
	{
		creditsMenu->setMessage("You lose!\nYour final score was" + LevelManager::Instance()->getScore());
		doFunction(PUSH_CREDITS);
	}

	// Get information about the mouse this frame
	b2Vec2 mousePos = InputManager::Instance()->getMouseScreenCoord();
	bool mouseRelease =  InputManager::Instance()->mouseRelease();

	switch(gameState)
	{
		case IN_GAME:
			// If the ESC key is pressed in the IN_GAME state
			if (InputManager::Instance()->OnRelease(KEY_ESC))	
				// Push the Pause menu onto the menu stack
				doFunction(PUSH_PAUSE);
			// If the Backspace key is pressed in the IN_GAME state
			if (InputManager::Instance()->OnRelease(KEY_BACK))	
			{
				creditsMenu->setMessage("You win!\nYour final score was: " + LevelManager::Instance()->getScore());
				// Push the Pause menu onto the menu stack
				doFunction(PUSH_CREDITS);
			}
			break;
		case DIALOG:
			// If the ESC key is pressed in the DIALOG state
			if (InputManager::Instance()->OnRelease(KEY_ESC))	
				// Push the Pause menu onto the menu stack
				doFunction(PUSH_PAUSE);
			break;
		case PAUSED:
			// If the ESC key is pressed in the PAUSED state: 
			if (InputManager::Instance()->OnRelease(KEY_ESC))
				// Pop the current menu
				doFunction(POP_MENU);
			break;
		case LOADING:
			// Load whichever level is to be loaded next
			LevelManager::Instance()->loadLevel(levelToLoad);
			// Check to see if a level is laoded
			if (LevelManager::Instance()->isLevelLoaded())
			{
				// Show the cursor again
				showCursor = true;
				// Pop the current menu (assumed to be the Loading menu)
				doFunction(POP_MENU);
			}
			else
			{
				showCursor = true;
				doFunction(TO_TITLE);
			}
			break;
	}

	// If the menu stack is not empty
	if (!menuStack.empty())
	{
		// Update the menu at the top of the stack
		menuStack.back()->update(mousePos.x, mousePos.y, mouseRelease, deltaTime);

		// If the mouse was clicked this frame getFunction() will return 
		// the corresponding function from the menu (if any) and respond to it
		doFunction(menuStack.back()->getFunction(mouseRelease));
	}
}

/****************************************************************
* Draws current UI elements
****************************************************************/
void GUIManager::Draw()
{
	// Draw the menu stack from back to front
	if (!menuStack.empty())
		menuStack.back()->draw();

	// Draw the cross hair
	if (showCursor)
	{
		crosshair->translate(D3DXVECTOR2(InputManager::Instance()->returnScreenX(), InputManager::Instance()->returnScreenY()));
		crosshair->Draw();
	}
}

/****************************************************************
* Responds to functions from the top menu on the menu stack
****************************************************************/
void GUIManager::doFunction(int function)
{
	switch(function)
	{
		case PUSH_TITLE:
			menuStack.push_back(titleMenu);
			break;

		case PUSH_LOADING:
			// Push the Loading menu onto the stack
			menuStack.push_back(loadingMenu);
			// Hide the cursor since nothing happens during level loading
			showCursor = false;
			break;

		case PUSH_PAUSE:
			// Push the Pause menu onto the menu stack
			menuStack.push_back(pauseMenu);
			break;

		case PUSH_HELP:
			// Push the Help menu onto the menu stack
			menuStack.push_back(helpMenu);
			break;

		case PUSH_DIALOG:
			if (gameState == DIALOG)
				// Pop any preexisting dialog to prevent multiples
				menuStack.pop_back();
			// Push the Dialog menu onto the menu stack
			menuStack.push_back(dialogMenu);
			break;

		case PUSH_QUIT:
			// Push the Quit menu onto the stack
			menuStack.push_back(quitMenu);
			break;

		case PUSH_CREDITS:
			// Unload the level
			LevelManager::Instance()->unloadLevel();
			// Push the Credits menu onto the menu stack
			menuStack.push_back(creditsMenu);
			break;

		case POP_MENU:
			// Pop the current menu
			menuStack.pop_back();
			break;

		case NEXT_LEVEL:
			// Pop the current menu (assumed to be the Credits menu)
			menuStack.pop_back();
			// Open the load screen and wait for level to load
			doFunction(PUSH_LOADING);
			if (LevelManager::Instance()->getNextLevel().compare("No such property!") != 0)
				levelToLoad = LevelManager::Instance()->getNextLevel();
			break;

		case START_GAME:
			// Pop the current menu (assumed to be the Title menu)
			menuStack.pop_back();
			// Open the load screen and wait for level to load
			doFunction(PUSH_LOADING);
			//Initialize Level
			levelToLoad = "../LevelData/level0.tmx";
			break;

		case TO_TITLE:
			// Unload the level
			LevelManager::Instance()->unloadLevel();
			// Clear the menu stack
			menuStack.clear();
			// Push the Title menu onto the menu stack
			menuStack.push_back(titleMenu);
			break;

		case TO_DESKTOP:
			gameInstance->ShutdownGame();
			break;
	}

	// Switches the game state depending on which menu is at the front of the stack, if any
	if (!menuStack.empty())
		gameState = menuStack.back()->getState();
	else
		gameState = IN_GAME;
}


/****************************************************************
* A shortcut that opens the dialog menu with the given source 
* and textual content
****************************************************************/
void GUIManager::say(string speaker, string content, int timeInSeconds)
{
	// Create a new dialog object
	GUIDialog newDialog = GUIDialog();
	newDialog.setSource(speaker);
	newDialog.addLine(content);
	dialogMenu->setDialog(newDialog);
	dialogMenu->setTimer(timeInSeconds);
	doFunction(PUSH_DIALOG);
}

/****************************************************************
* Utility function for testing purposes
****************************************************************/
void GUIManager::debugMode()
{
	doFunction(START_GAME);
}