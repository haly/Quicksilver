#include "GUIDialog.h"

/****************************************************************
* Default constructor
****************************************************************/
GUIDialog::GUIDialog(void)
{
	dialogSource = "";
	dialogQueue = new queue<string>();
}

GUIDialog::~GUIDialog(void)
{
}

/****************************************************************
* Sets the source of the dialog
****************************************************************/
void GUIDialog::setSource(string source)
{
	dialogSource = source;
}

/****************************************************************
* Adds a single line of dialog
****************************************************************/
void GUIDialog::addLine(string line)
{
	dialogQueue->push(line);
}

/****************************************************************
* Return the source of the dialog
****************************************************************/
string GUIDialog::getSource(void)
{
	return dialogSource;
}

/****************************************************************
* Returns a single line of dialog and removes it from the dialog queue
* If there is no more dialog it will returna blank line
****************************************************************/
string GUIDialog::getLine(void)
{
	if (!dialogQueue->empty())
	{
		string line = dialogQueue->front();
		dialogQueue->pop();
		return line;
	}
	return "";
}

/****************************************************************
* Returns whether or not the dialog queue is empty
****************************************************************/
bool GUIDialog::dialogEnd(void)
{
	return dialogQueue->empty();
}