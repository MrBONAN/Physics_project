#include "Test.h"

string Test::outInfo()
{
	string of = "0\n";
	for (auto& it : btns)
	{
		string str = it->getStr();
		for (auto& it : str)
		{
			if (it == '\n') it = '~';
		}
		of += str + '\n';
	}
	of += to_string(selAnsNumber) + '\n';
	return of;
}


void Test::inpInfo(istream& is)
{
	for (auto& it : btns)
	{
		it->showCursor = false;
		string str;
		getline(is, str);
		for (auto& it : str)
		{
			if (it == '~') it = '\n';
		}
		it->setStr(str);
	}
	getline(is, answer);
}

Test::Test(sf::RenderWindow& window) : Scene(window)
{
	for (int i = 0; i < 4; ++i) {
		btns.push_back(new Button(window));
		btns[i]->showCursor = true;
	}
	exerciseRect.showCursor = true;

	btns.push_back(&exerciseRect);
	exerciseRect.setPosition(10, 10);
	btns[0]->setPosition(10, 400);
	btns[1]->setPosition(535, 400);
	btns[2]->setPosition(10, 525);
	btns[3]->setPosition(535, 525);

	for (int i = 0; i < 4; ++i)
		btnAnswer.push_back(new Button(window, {49, 1, 49, 17, 5, 5, 5, 15, 15}));
	btnAnswer[0]->setPosition(480, 470);
	btnAnswer[1]->setPosition(1005, 470);
	btnAnswer[2]->setPosition(480, 595);
	btnAnswer[3]->setPosition(1005, 595);
}

void Test::showAnswer()
{
	selAnsNumber = atoi(answer.c_str());
	btnAnswer[selAnsNumber]->ind.on();
}

bool Test::checkAnswer()
{
	return to_string(selNumber) == answer;
}

void Test::show()
{
	for (auto& it : btns)
		it->show();
	
	if (teacherMode)
		for (auto& it : btnAnswer)
			it->show();
}

Test::~Test()
{
	for (int i = 0; i < btns.size()-1; i++)
		delete btns[i];
	for (auto& it : btnAnswer)
		delete it;
}

void Test::checkAllActive(const sf::Vector2i& msCord)
{
	for (int i = 0; i < btns.size() - 1; i++)
		btns[i]->checkActive(msCord);
	if (teacherMode) {
		for (auto& it : btnAnswer)
			it->checkActive(msCord);
		exerciseRect.checkActive(msCord);
	}
}

void Test::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	if (msCord != pastMsCord || first)
	{
		pastMsCord = msCord;
		for (int i = 0; i < btns.size() - 1; i++)
		{
			btns[i]->checkFocus(msCord);
		}
		if (teacherMode) {
			for (auto& it : btnAnswer)
				it->checkFocus(msCord);
			exerciseRect.checkFocus(msCord);
		}
	}
}

void Test::checkIndicator(const sf::Vector2i& msCord, vector<Button*>& btns,  int i, int& selNumber)
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

void Test::checkAllEvents(const sf::Vector2i& msCord)
{
	for (int i = 0; i < btns.size() - 1; ++i)
	{
		checkIndicator(msCord, btns, i, selNumber);
	}
	if (teacherMode)
	{
		for (int i = 0; i < btnAnswer.size(); ++i) {
			checkIndicator(msCord, btnAnswer, i, selAnsNumber);
		}
		checkIndicator(msCord, btns, 4, selNumber);
	}
}

void Test::setAllText(const sf::Event& event)
{
	if (teacherMode) {
		if (selNumber == 4) {
			setText(exerciseRect, event);
		}
		else if (selNumber != -1) {
			setText(*btns[selNumber], event);
		}
	}
}

