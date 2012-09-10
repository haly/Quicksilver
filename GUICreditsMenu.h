#pragma once

// Local
#include "GUIMenu.h"

class GUICreditsMenu : public GUIMenu
{
public:
	GUICreditsMenu(void);
	~GUICreditsMenu(void);

	void init();
	void update(float mouseX, float mouseY, bool clicked, float deltaTime);
	void draw();

	void setMessage(string text);
private:
	// Textures
	Sprite *bg;

	// Buttons
	GUIButton *next;

	// Labels
	GUIButton *endmsg;
	GUIButton *credits;
	GUIButton *clark;
	GUIButton *mcshane;
	GUIButton *sadwin;
	GUIButton *scott;
	GUIButton *yuan;

	// Buttons
	GUIButton *title;
};

