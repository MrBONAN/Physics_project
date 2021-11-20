#include "writeAns.h"

writeAns::writeAns(sf::RenderWindow& window) :Scene(window),
answerBox(window, { 49, 1, 17, 1, 512, 50, 5, 5, 5 })
{
	exerciseRect.setPosition(10, 10);
	answerBox.setPosition(10, 400);
	btns.push_back(&answerBox);
	btns.push_back(&exerciseRect);
}

void writeAns::show()
{
	exerciseRect.show();
	answerBox.show();
}

void writeAns::checkAllActive(const sf::Vector2i& msCord)
{
	answerBox.checkActive(msCord);
	if (teacherMode)
		exerciseRect.checkActive(msCord);
}

void writeAns::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	if (msCord != pastMsCord || first)
	{
		//cout << "CHECKFOCUS" << endl;
		pastMsCord = msCord;
		answerBox.checkFocus(msCord);
		if (teacherMode)
			exerciseRect.checkFocus(msCord);
	}
}

void writeAns::checkAllEvents(const sf::Vector2i& msCord)
{
	checkIndicator(msCord, btns, 0);
	if (teacherMode)
	{
		checkIndicator(msCord, btns, 1);
	}
}

void writeAns::setAllText(const sf::Event& event)
{
	if (teacherMode) {
		if (selNumber == 1) {
			setText(exerciseRect, event);
		}
		else if (selNumber != -1) {
			setText(*btns[0], event);
		}
	}
}

void writeAns::checkIndicator(const sf::Vector2i& msCord, vector<Button*>& btns, int i)
{
	if (btns[i]->Event(msCord)) {
		if (i == selNumber) { // нажали на ту же кнопку
			btns[i]->ind.off();
			selNumber = -1;
		}
		else { // нажали на новую кнопку
			if (selNumber == -1) { // если ещё не нажали на какую-либо кнопку
				btns[i]->ind.on();
				selNumber = i;
			}
			else { // если была выбрана другая кнопка
				btns[selNumber]->ind.off();
				btns[i]->ind.on();
				selNumber = i;
			}
		}
	}
}

