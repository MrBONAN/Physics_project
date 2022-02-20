#include "ConfirmWindow.h"

string pad(std::string s, int len = 26);

ConfirmWindow::ConfirmWindow(string text) :
	window(sf::VideoMode(530, 155), L"Проект"),
	info(window, { INFOsize, 260, 50 }),
	yes(window, { BUTTONsize, 32, 20 }),
	no(window, { BUTTONsize, 32, 20 }) // 40 20
{
	window.setFramerateLimit(30);

	info.setScale(2);
	info.setPosition(5, 5);
	info.setStr(text);

	yes.setScale(2);
	yes.setPosition(101, 110);
	yes.setStr(pad("Да", 3));

	no.setScale(2);
	no.setPosition(365, 110);
	no.setStr(pad("Нет", 4));
}

string ConfirmWindow::loop()
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

void ConfirmWindow::checkAllInteractions(const sf::Event& event)
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

void ConfirmWindow::checkAllActive(const sf::Vector2i& msCord)
{
	yes.checkActive(msCord);
	no.checkActive(msCord);
}

void ConfirmWindow::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	yes.checkFocus(msCord);
	no.checkFocus(msCord);
}

void ConfirmWindow::checkAllEvents(const sf::Vector2i& msCord)
{
	if (yes.Event(msCord))
		result = "YES";
	else if (no.Event(msCord))
		result = "NO";
}

void ConfirmWindow::show()
{
	window.clear(sf::Color(200, 200, 200, 255));
	info.show();
	yes.show();
	no.show();
	window.display();
}
