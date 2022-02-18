#include "InputWindow.h"

string pad(std::string s, int len = 26);

InputWindow::InputWindow(string text) : 
	window(sf::VideoMode(530, 205), L"������"),
	info	(window, { INFOsize, 260, 50 }),
	input	(window, { BUTTONsize, 260, 20 }),
	ok		(window, { BUTTONsize, 40, 20})
{
	window.setFramerateLimit(30);

	info.setScale(2);
	info.setPosition(5, 5);
	info.setStr(text);

	input.setScale(2);
	input.setPosition(5, 115);
	input.showCursor = true;

	ok.setScale(2);
	ok.setPosition(225, 160);
	ok.setStr(pad("��", 5));
}

string InputWindow::loop()
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

void InputWindow::checkAllInteractions(const sf::Event& event)
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
	// ������� ����� ������
	setAllText(event);
}

void InputWindow::checkAllActive(const sf::Vector2i& msCord)
{
	input.checkActive(msCord);
	ok.checkActive(msCord);
}

void InputWindow::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	input.checkFocus(msCord);
	ok.checkFocus(msCord);
}

void InputWindow::checkAllEvents(const sf::Vector2i& msCord)
{
	if (input.Event(msCord)) {
		if (inputActive) {
			inputActive = false;
			input.ind.off();
		} else {
			inputActive = true;
			input.ind.on();
		}
	}
	if (ok.Event(msCord)) {
		inputActive = false;
		input.ind.off();
	}
}

void InputWindow::setAllText(const sf::Event& event)
{
	if (inputActive) input.setText(event);
}

void InputWindow::show()
{
	window.clear(sf::Color(200, 200, 200, 255));
	info.show();
	input.show();
	ok.show();
	window.display();
}