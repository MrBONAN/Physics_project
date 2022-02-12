#pragma once
#include "Button.h"

class DialogWindow
{
public:
	DialogWindow(string text);

	virtual string loop();
	
private:
	virtual void show() = 0; // сделать не чисто виртуальной

	Button infoRect;
	sf::RenderWindow dialogWindow;
};

