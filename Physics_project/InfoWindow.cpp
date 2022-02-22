#include "InfoWindow.h"

string pad(std::string s, int len = 26);

InfoWindow::InfoWindow(string text) :
	window(sf::VideoMode(530, 155), L"Проект"),
	info(window, { INFOsize, 260, 50 }),
	ok(window, { BUTTONsize, 32, 20 }) // 40 20
{
	window.setFramerateLimit(30);

	info.setScale(2);
	info.setPosition(5, 5);
	info.setStr(text);

	ok.setScale(2);
	ok.setPosition(241, 110);
	ok.setStr(pad("ОК", 4));
}

string InfoWindow::loop()
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

void InfoWindow::checkAllInteractions(const sf::Event& event)
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
}

void InfoWindow::checkAllActive(const sf::Vector2i& msCord)
{
	ok.checkActive(msCord);
}

void InfoWindow::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	ok.checkFocus(msCord);
}

void InfoWindow::checkAllEvents(const sf::Vector2i& msCord)
{
	if (ok.Event(msCord)) result = "OK";
}

void InfoWindow::show()
{
	window.clear(sf::Color(200, 200, 200, 255));
	info.show();
	ok.show();
	window.display();
}
