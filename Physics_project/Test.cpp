#include "Test.h"

Test::Test(sf::RenderWindow& window) : Scene(window)
{
	for(int i = 0; i < 4; ++i)
		btns.push_back(new Button(window));
	btns.push_back(&exerciseRect);
	exerciseRect.setPosition(10, 10);
	btns[0]->setPosition(10, 400);
	btns[1]->setPosition(535, 400);
	btns[2]->setPosition(10, 525);
	btns[3]->setPosition(535, 525);
}

void Test::show()
{
	for (auto& it : btns)
		it->show();
	exerciseRect.show();
}

Test::~Test()
{
	for (int i = 0; i < btns.size()-1; i++)
		delete btns[i];
}

void Test::checkALlInteraction(const sf::Event& event)
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
	if (teacherMode){
		if (selNumber == 4) {
			setText(exerciseRect, event) ;
		} else if (selNumber != -1) {
			setText(*btns[selNumber], event);
		}
	}
}

void Test::checkAllActive(const sf::Vector2i& msCord)
{
	for (int i = 0; i < btns.size() - 1; i++)
	{
		btns[i]->checkActive(msCord);
	}
	if(teacherMode)
		exerciseRect.checkActive(msCord);
}

void Test::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	if (msCord != pastMsCord || first)
	{
		//cout << "CHECKFOCUS" << endl;
		pastMsCord = msCord;
		for (int i = 0; i < btns.size() - 1; i++)
		{
			btns[i]->checkFocus(msCord);
		}
		if(teacherMode)
			exerciseRect.checkFocus(msCord);
	}
}

void Test::checkIndicator(const sf::Vector2i& msCord, vector<Button*>& btns,  int i)
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

void Test::checkAllEvents(const sf::Vector2i& msCord)
{
	for (int i = 0; i < btns.size() - 1; ++i)
	{
		checkIndicator(msCord, btns, i);
	}
	if (teacherMode)
	{
		checkIndicator(msCord, btns, 4);
	}
}
