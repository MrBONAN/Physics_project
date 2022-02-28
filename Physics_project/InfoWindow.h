#pragma once
#include "MyWindows.h"

class InfoWindow
	: public MyWindows
{
public:
	InfoWindow(string text);

private:
	void checkAllEvents(const sf::Vector2i& msCord);

	Button ok;
};

