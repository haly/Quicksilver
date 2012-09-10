#pragma once

// Local
#include "GUIMenu.h"

class GUITitleMenu : public GUIMenu
{
public:
	GUITitleMenu(void);
	~GUITitleMenu(void);

	void init();
	void update(float mouseX, float mouseY, bool clicked, float deltaTime);
	void draw();

private:
	// Graphics
	Sprite *logo;
	float logoX;
	float logoY;

	Sprite *symbol;
	float symbolX;
	float symbolY;

	// Buttons
	GUIButton *start;
	GUIButton *instruct;
	GUIButton *quit;
};

