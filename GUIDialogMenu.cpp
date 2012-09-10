#include "GUIDialogMenu.h"

/****************************************************************
* Default constructor
****************************************************************/
GUIDialogMenu::GUIDialogMenu(void)
{
	init();
}


GUIDialogMenu::~GUIDialogMenu(void)
{

}

/****************************************************************
* Initializes menu components
****************************************************************/
void GUIDialogMenu::init(void)
{
	// Set state
	gameState = DIALOG;

	// Determine the center coordinates of the screen
	float halfWidth = GraphicsManager::Instance()->screenWidth/2;
	float halfHeight = GraphicsManager::Instance()->screenHeight/2;

	// Initialize textures
	dialogBG = new Sprite("black.png", 0, 0, NORMAL);
	dialogBG->translate(D3DXVECTOR2(halfWidth, (halfHeight * 2) - 90)); 
	dialogBG->scale(D3DXVECTOR2(halfWidth * 2, 90));

	// Initialize buttons unique to the Dialog Menu
	source = new GUIButton(15, (halfHeight * 2) - 130, halfWidth * 2 - 50, 20, MEDIUM_ORATOR, "", DT_LEFT | DT_WORDBREAK, NULL_FUNCTION);
	line1 = new GUIButton(25, (halfHeight * 2) - 100, halfWidth * 2 - 50, 20, MEDIUM_ORATOR, "", DT_LEFT | DT_WORDBREAK, NULL_FUNCTION);
	line2 = new GUIButton(25, (halfHeight * 2) - 70, halfWidth * 2 - 50, 20, MEDIUM_ORATOR, "", DT_LEFT | DT_WORDBREAK, NULL_FUNCTION);
	line3 = new GUIButton(25, (halfHeight * 2) - 40, halfWidth * 2 - 50, 20, MEDIUM_ORATOR, "", DT_LEFT | DT_WORDBREAK, NULL_FUNCTION);
	
	// Add to storage
	labelList.push_back(source);
	labelList.push_back(line1);
	labelList.push_back(line2);
	labelList.push_back(line3);

	// Initialize a default dialog object to prevent unintended crashes
	d = new GUIDialog();

	// Initialize time to -1
	timer = -1;
}

/****************************************************************
* Update cycle, handles mouse events and any animation
****************************************************************/
void GUIDialogMenu::update(float mouseX, float mouseY, bool clicked, float deltaTime)
{
	// Iterate through every button to check whether the mouse is hovering over it
	// Selected buttons are drawn with white text, unselected buttons are drawn with grey text
	checkSelected(mouseX, mouseY);
	 
	// Cycles through the dialog
	if (clicked)
	{
		if (!d->dialogEnd())
		{
			line1->setText(line2->getText());
			line2->setText(line3->getText());
			line3->setText(d->getLine());
		}
	}

	if (timer > 0.0f)
	{
		timer -= deltaTime;
		if (timer < 0.0f)
		{
			timer = 0.0f;
		}
	}
}

/****************************************************************
* Draws all menu components
****************************************************************/
void GUIDialogMenu::draw(void)
{
	// Draw background
	dialogBG->Draw();

	// Draw all labels and buttons
	for (int i = 0; i < (int)labelList.size(); i++)
		labelList[i]->draw();

	for (int i = 0; i < (int)buttonList.size(); i++)
		buttonList[i]->draw();
}

/****************************************************************
* Informs GUIManager when the dialog is done and should be closed
* Unlike other menus, the dialog box will not respond to clicks
****************************************************************/
int GUIDialogMenu::getFunction(bool clicked)
{
	if (timer == 0.0f)
	{
		timer = -1;
		return POP_MENU;
	}
	else
		return NULL_FUNCTION;
}

/****************************************************************
* Loads a dialog object
****************************************************************/
void GUIDialogMenu::setDialog(GUIDialog &newDialog)
{
	d = new GUIDialog(newDialog);
	source->setText(d->getSource());
	for (int i = 1; i < (int)labelList.size(); i++)
	{
		if (!d->dialogEnd())
		{
			labelList[i]->setText(d->getLine());
		}
	}
}