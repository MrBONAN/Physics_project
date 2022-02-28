#include "ConfirmWindow.h"

string pad(std::string s, int len = 26);

ConfirmWindow::ConfirmWindow(string text) :
	MyWindows({ 530, 155 }, { 260, 50 }, text),
	yes(window, { BUTTONsize, 32, 20 }),
	no(window, { BUTTONsize, 32, 20 }) // 40 20
{
	info.setScale(2);
	info.setPosition(5, 5);

	yes.setScale(2);
	yes.setPosition(101, 110);
	yes.setStr(pad("Да", 3));

	no.setScale(2);
	no.setPosition(365, 110);
	no.setStr(pad("Нет", 4));

	showBtns.push_back(&info);
	showBtns.push_back(&yes);
	showBtns.push_back(&no);

	btns.push_back(&yes);
	btns.push_back(&no);
}

void ConfirmWindow::checkAllEvents(const sf::Vector2i& msCord)
{
	if (yes.Event(msCord))
		result = "YES";
	else if (no.Event(msCord))
		result = "NO";
}
