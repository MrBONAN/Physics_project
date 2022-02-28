#include "InfoWindow.h"

string pad(std::string s, int len = 26);

InfoWindow::InfoWindow(string text) : MyWindows({ 530, 155 }, { 260, 50 }, text),
	ok(window, { BUTTONsize, 40, 20 }) // 40 20
{
	info.setScale(2);
	info.setPosition(5, 5);

	ok.setScale(2);
	ok.setPosition(225, 110);
	ok.setStr(pad("ок", 5));

	showBtns.push_back(&info);
	showBtns.push_back(&ok);

	btns.push_back(&ok);
}

void InfoWindow::checkAllEvents(const sf::Vector2i& msCord)
{
	if (ok.Event(msCord)) result = "OK";
}