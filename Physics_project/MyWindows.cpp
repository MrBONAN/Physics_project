#include "MyWindows.h"

string pad(std::string s, int len = 26);

MyWindows::MyWindows(sf::VideoMode sizes, sf::Vector2f infoSizes, string text) :
	window(sf::VideoMode(sizes), L"Проект"),
	info(window, { INFOsize, infoSizes.x, infoSizes.y })
{
	window.setFramerateLimit(30);
	info.setStr(text);
}

string MyWindows::loop()
{
	while (window.isOpen() && result == "NONE")
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				result = "CLOSE";
				window.close();
				continue;
			}
			checkAllInteractions(event);
		}
		show();
	}
	return result;
}


void MyWindows::checkAllInteractions(const sf::Event& event)
{
	//кнопка только что нажата
	if (event.type == sf::Event::MouseButtonPressed) {
		checkAllActive(sf::Mouse::getPosition(window));
		checkAllFocus(sf::Mouse::getPosition(window), true);
	}
	//кнока нажата в данный момент
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		checkAllFocus(sf::Mouse::getPosition(window));
	}
	//кнопка была отпущена
	if (event.type == sf::Event::MouseButtonReleased) {
		checkAllEvents(sf::Mouse::getPosition(window));
	}
	// включен режим учител
	setAllText(event);
}

void MyWindows::checkAllActive(const sf::Vector2i& msCord)
{
	for (auto it : btns) it->checkActive(msCord);
}

void MyWindows::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	for (auto it : btns) it->checkFocus(msCord);
}

void MyWindows::show()
{
	window.clear(sf::Color(200, 200, 200, 255));
	for (auto it : showBtns) it->show();
	window.display();
}
