#pragma once
#include "Button.h"

class ConfirmWindow
{
public:
	ConfirmWindow(string text);

	string loop();

private:
	void checkAllInteractions(const sf::Event&);
	void checkAllActive(const sf::Vector2i& msCord);
	void checkAllFocus(const sf::Vector2i& msCord, bool first = false);
	void checkAllEvents(const sf::Vector2i& msCord);

	void show();

	sf::RenderWindow window;
	Button info, yes, no;

	string result = "NONE";
};

