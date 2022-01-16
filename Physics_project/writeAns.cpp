#include "writeAns.h"

string writeAns::outInfo()
{
	string of = "1\n";
	for (auto& it : btns)
	{
		string str = it->getStr();
		for (auto& it : str)
		{
			if (it == '\n') it = '~';
		}
		of += str + '\n';
	}
	return of;
}

void writeAns::inpInfo(istream& is)
{
	for (auto& it : btns)
	{
		string str;
		getline(is, str);
		for (auto& it : str)
		{
			if (it == '~') it = '\n';
		}
		it->setStr(str);
	}
	answer = btns[0]->getStr();
	btns[0]->setStr("");
}

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
	}
	if (selNumber != -1) {
		setText(*btns[0], event);
	}
}

void writeAns::checkIndicator(const sf::Vector2i& msCord, vector<Button*>& btns, int i)
{
	if (btns[i]->Event(msCord)) {
		if (i == selNumber) { // ������ �� �� �� ������
			btns[i]->ind.off();
			selNumber = -1;
		}
		else { // ������ �� ����� ������
			if (selNumber == -1) { // ���� ��� �� ������ �� �����-���� ������
				btns[i]->ind.on();
				selNumber = i;
			}
			else { // ���� ���� ������� ������ ������
				btns[selNumber]->ind.off();
				btns[i]->ind.on();
				selNumber = i;
			}
		}
	}
}
