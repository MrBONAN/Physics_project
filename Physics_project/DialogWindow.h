#pragma once
#include "Button.h"

class DialogWindow
{
public:
	DialogWindow(string text);

	virtual string loop();
	
private:
	virtual void show() = 0; // ������� �� ����� �����������

	Button infoRect;
	sf::RenderWindow dialogWindow;
};

