#pragma once

// Local
#include "GUIMenu.h"
#include "GUIDialog.h"

class GUIDialogMenu : public GUIMenu
{
public:
	GUIDialogMenu(void);
	~GUIDialogMenu(void);

	void init();
	void update(float mouseX, float mouseY, bool clicked, float deltaTime);
	void draw();
	int getFunction(bool clicked);

	void setDialog(GUIDialog &newDialog);
	void setTimer(int timeInSeconds)	{timer = (float)timeInSeconds;}

private:
	// Textures
	Sprite *dialogBG;

	// Labels
	GUIButton *source;
	GUIButton *line1;
	GUIButton *line2;
	GUIButton *line3;

	// Dialog object
	GUIDialog *d;

	// Self destruct timer
	float timer;
};