#pragma once

// Local
#include "GUIButton.h"
#include "GUIEnum.h"
#include "GraphicsManager.h"

class GUIManager;

class GUIMenu
{
public:
	GUIMenu(void);
	~GUIMenu(void);

	// Initialize all menu components (to be overridden in the child class)
	virtual void init() {};
	// Update cycle, handles mouse events and any animation (to be overridden in the child class)
	virtual void update(float mouseX, float mouseY, bool clicked, float deltaTime) {};
	// Draws all menu components (to be overridden in the child class)
	virtual void draw() {};
	//Iterate through every button to check whether the mouse is hovering over it
	virtual int getFunction(bool clicked);
	//Returns an enum indicating which button was just clicked/activated
	void checkSelected(float mouseX, float mouseY);
	int getState()		{return gameState;}

protected:
	// Storage for menu components
	// Buttons are interactable and react to user input, labels are buttons that have no related functions
	vector<GUIButton*> labelList;
	vector<GUIButton*> buttonList;

	// The state this menu corresponds to
	int gameState;
};

