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
			{ 1, 1, 17, 17, 255, 55, 5, 5, 5 }));
	/*(508, 412)(508, 454)(508, 537)(508, 579);*/
	
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
	//кнопка только что нажата
	if (event.type == sf::Event::MouseButtonPressed) {
		checkAllActive(sf::Mouse::getPosition(window));
		checkAllFocus(sf::Mouse::getPosition(window), true);
	}
	//кнока нажата в данный момент
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		checkAllFocus(sf::Mouse::getPosition(window));
	}
	//кнопка была отпущена
	if (event.type == sf::Event::MouseButtonReleased) {
		checkAllEvents(sf::Mouse::getPosition(window));
	}
	// включен режим учител
	if (teacherMode && selNumber != -1){
		setText(*btns[selNumber], event);
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
			if (i == selNumber){ // нажали на ту же кнопку
				indicators[i]->off();
				selNumber = -1;
			}
			else { // нажали на новую кнопку
				if (selNumber == -1){ // если ещё не нажали на какую-либо кнопку
					indicators[i]->on();
					selNumber = i;
				}
				else { // если была выбрана другая кнопка
					indicators[selNumber]->off();
					indicators[i]->on();
					selNumber = i;
				}
			}
		}
	}
	exerciseRect.Event(msCord);
}
