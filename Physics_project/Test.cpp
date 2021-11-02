#include "Test.h"

Test::Test(sf::RenderWindow& window) : Scene(window)
{
	for(int i = 0; i < 4; ++i)
		btns.push_back(new Button(window));
	exerciseRect.setPosition(10, 10);
	btns[0]->setPosition(10, 400);
	btns[1]->setPosition(535, 400);
	btns[2]->setPosition(10, 525);
	btns[3]->setPosition(535, 525);

	for (int i = 0; i < 4; ++i)
		indicators.push_back(new Indicator(window,
			/*{17, 49, 17, 17, 15, 15, 5, 5, 5}));*/
			{ 17, 49, 17, 17, 255, 55, 5, 5, 5 }));
	/*indicators[0]->setPosition(508, 412);
	indicators[1]->setPosition(508, 454);
	indicators[2]->setPosition(508, 537);
	indicators[3]->setPosition(508, 579);*/
	indicators[0]->setPosition(5, 395);
	indicators[1]->setPosition(529, 395);
	indicators[2]->setPosition(5, 520);
	indicators[3]->setPosition(529, 520);
}

void Test::show()
{
	for (auto& it : indicators)
		it->show();
	for (auto& it : btns)
		it->show();
	exerciseRect.show();
}

Test::~Test()
{
	for (auto& it : btns)
		delete it;
	for (auto& it : indicators)
		delete it;
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
}

void Test::checkAllActive(const sf::Vector2i& msCord)
{
	for (auto it : btns)
	{
		it->checkActive(msCord);
	}
	exerciseRect.checkActive(msCord);
}

void Test::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	if (msCord != pastMsCord || first)
	{
		//cout << "CHECKFOCUS" << endl;
		pastMsCord = msCord;
		for (auto& it : btns)
		{
			it->checkFocus(msCord);
		}
		exerciseRect.checkFocus(msCord);
	}
}

void Test::checkAllEvents(const sf::Vector2i& msCord)
{
	for (int i = 0; i < btns.size(); ++i)
	{
		if (btns[i]->Event(msCord)) {
			if (i == selNumber) // ������ �� �� �� ������
			{
				indicators[i]->off();
				selNumber = -1;
			}
			else { // ������ �� ����� ������
				if (selNumber == -1) // ���� ��� �� ������ �� �����-���� ������
				{
					indicators[i]->on();
					selNumber = i;
				}
				else { // ���� ���� ������� ������ ������
					indicators[selNumber]->off();
					indicators[i]->on();
					selNumber = i;
				}
			}
		}
	}
	exerciseRect.Event(msCord);
}
