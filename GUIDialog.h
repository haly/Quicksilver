#pragma once

// Libraries
#include <stdlib.h>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

class GUIDialog 
{
public:
	GUIDialog(void);
	~GUIDialog(void);

	void setSource(string source);
	void addLine(string line);
	string getSource(void);
	string getLine(void);
	bool dialogEnd(void);
private:
	// Source of the dialog
	string dialogSource;
	// A list of lines of the dialog
	queue<string> *dialogQueue;
};