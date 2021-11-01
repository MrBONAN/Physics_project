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
}

void Test::show()
{
	for (auto& it : btns)
		it->show();
	exerciseRect.show();
}

Test::~Test()
{
	for (auto& it : btns)
		delete it;
}

void Test::checkAllFocus(const sf::Vector2i& msCord)
{
	if (OBJ::mouseJustPressed || msCord != pastMsCord)
	{
		//cout << "CHECKFOCUS" << endl;
		pastMsCord = msCord;
		for (auto it : btns)
		{
			it->checkFocus(msCord);
		}
		OBJ::mouseJustPressed = false;
	}
}

void Test::checkAllEvents(const sf::Vector2i& msCord)
{
	for (auto it : btns)
	{
		it->Event(msCord);
	}
	OBJ::mouseJustPressed = true;
}
