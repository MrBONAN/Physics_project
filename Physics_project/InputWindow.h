#pragma once
#include "Button.h"
class InputWindow
{
public:
	InputWindow(string text);

	string loop();

private:
	void checkAllInteractions(const sf::Event&);
	void checkAllActive(const sf::Vector2i& msCord);
	void checkAllFocus(const sf::Vector2i& msCord, bool first = false);
	void checkAllEvents(const sf::Vector2i& msCord);
	void setAllText(const sf::Event& event);

	void show();

	sf::RenderWindow window;
	Button info, input, ok;
	bool inputActive = false;

	string result = "NONE";
};

