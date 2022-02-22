#pragma once
#include "Button.h"

class InfoWindow
{
public:
	InfoWindow(string text);

	string loop();

private:
	void checkAllInteractions(const sf::Event&);
	void checkAllActive(const sf::Vector2i& msCord);
	void checkAllFocus(const sf::Vector2i& msCord, bool first = false);
	void checkAllEvents(const sf::Vector2i& msCord);

	void show();

	sf::RenderWindow window;
	Button info, ok;

	string result = "NONE";
};

