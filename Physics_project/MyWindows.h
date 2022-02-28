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

	vector<Button*> btns; // ������, � �������� ����� �����������������
	vector<Button*> showBtns; // ��� ������, ������� ����� ����������
	Button info;

	string result = "NONE";
};

