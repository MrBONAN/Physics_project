#include "InfoWindow.h"

string pad(std::string s, int len = 26);

ConfirmWindow::ConfirmWindow(string text) :
	window(sf::VideoMode(530, 155), L"������"),
	info(window, { INFOsize, 260, 50 }),
	ok(window, { BUTTONsize, 32, 20 }) // 40 20
{
	window.setFramerateLimit(30);

	info.setScale(2);
	info.setPosition(5, 5);
	info.setStr(text);

	ok.setScale(2);
	ok.setPosition(241, 110);
	ok.setStr(pad("��", 4));
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
	//������ ������ ��� ������
	if (event.type == sf::Event::MouseButtonPressed) {
		checkAllActive(sf::Mouse::getPosition(window));
		checkAllFocus(sf::Mouse::getPosition(window), true);
	}
	//����� ������ � ������ ������
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		checkAllFocus(sf::Mouse::getPosition(window));
	}
	//������ ���� ��������
	if (event.type == sf::Event::MouseButtonReleased) {
		checkAllEvents(sf::Mouse::getPosition(window));
	}
}

void ConfirmWindow::checkAllActive(const sf::Vector2i& msCord)
{
	ok.checkActive(msCord);
}

void ConfirmWindow::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	ok.checkFocus(msCord);
}

void ConfirmWindow::checkAllEvents(const sf::Vector2i& msCord)
{
	if (ok.Event(msCord)) result = "OK";
}

void ConfirmWindow::show()
{
	window.clear(sf::Color(200, 200, 200, 255));
	info.show();
	ok.show();
	window.display();
}
