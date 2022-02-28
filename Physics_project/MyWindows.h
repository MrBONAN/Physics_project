#pragma once
#include "Button.h"
#include <vector>

using std::vector;

class MyWindows
{
public:
	MyWindows(sf::VideoMode sizes, sf::Vector2f infoSizes, string text);

	virtual string loop();

protected:
	void checkAllInteractions(const sf::Event&);
	virtual void checkAllActive(const sf::Vector2i& msCord);
	virtual void checkAllFocus(const sf::Vector2i& msCord, bool first = false);
	virtual void checkAllEvents(const sf::Vector2i& msCord) = 0;
	virtual void setAllText(const sf::Event& event) {}

	void show();

	sf::RenderWindow window;

	vector<Button*> btns; // кнопки, с которыми можно взаимодействовать
	vector<Button*> showBtns; // все кнопки, которые нужно отобразить
	Button info;

	string result = "NONE";
};

