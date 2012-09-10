#pragma once

// Local
#include "GUIMenu.h"

class GUIQuitMenu : public GUIMenu
{
public:
	GUIQuitMenu(void);
	~GUIQuitMenu(void);

	void init();
	void update(float mouseX, float mouseY, bool clicked, float deltaTime);
	void draw();
private:
	// Textures
	Sprite *bg;

	// Buttons
	GUIButton *quit;
	GUIButton *title;
	GUIButton *desktop;
	GUIButton *back;
};

