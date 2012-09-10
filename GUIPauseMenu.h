#pragma once

// Local
#include "GUIMenu.h"

class GUIPauseMenu : public GUIMenu
{
public:
	GUIPauseMenu(void);
	~GUIPauseMenu(void);

	void init();
	void update(float mouseX, float mouseY, bool clicked, float deltaTime);
	void draw();

private:
	// Textures
	Sprite *bg;

	// Buttons
	GUIButton *paused;
	GUIButton *help;
	GUIButton *quit;
	GUIButton *back;
};

