#pragma once
#include "MyWindows.h"

class ConfirmWindow
	: public MyWindows
{
public:
	ConfirmWindow(string text);
private:
	void checkAllEvents(const sf::Vector2i& msCord);
	Button yes, no;
};

