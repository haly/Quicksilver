#pragma once

// Local
#include "GUIMenu.h"

class GUIHelpMenu : public GUIMenu
{
public:
	GUIHelpMenu(void);
	~GUIHelpMenu(void);

	void init();
	void update(float mouseX, float mouseY, bool clicked, float deltaTime);
	void draw();

private:
	// Graphics
	Sprite *help;
	Sprite *bg;

	int currentPage;

	// Buttons
	GUIButton *back;
};

