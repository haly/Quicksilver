#pragma once

// Local
#include "GUIMenu.h"

class GUILoadingMenu : public GUIMenu
{
public:
	GUILoadingMenu(void);
	~GUILoadingMenu(void);

	void init();
	void update(float mouseX, float mouseY, bool clicked, float deltaTime);
	void draw();
private:
	// Textures
	Sprite *bg;

	// Buttons
	GUIButton *loading;
};

