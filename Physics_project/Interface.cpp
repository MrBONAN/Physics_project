#include "Interface.h"
#include "AddScene.h"

ostream& operator<<(ostream& os, Interface& obj)
{
	os << obj.scenes.size() - 1 << endl;
	for (int i = 0; i < obj.scenes.size()-1; i++)
		os << obj.scenes[i];
	return os;
}

Interface::Interface(sf::RenderWindow& window) : Scene(window),
left(window, { 81, 33, 113,33, 31, 31, 0, 31, 31 }),
right(window, { 81, 1, 113, 1, 31, 31, 0, 31, 31 }),
close(window, { 81, 1, 113, 1, 31, 31, 0, 31, 31 }),
id(0)
{
	left.setPosition(10, 630);
	right.setPosition(973, 630);
	btns.push_back(&left);
	btns.push_back(&right);
	btns.push_back(&close);

	scenes.push_back(new AddScene(window, scenes));
}

void Interface::checkAllInteractions(const sf::Event& event)
{
	checkAllInteraction(event); 
	scenes[id]->checkAllInteraction(event);
}

void Interface::show()
{
	scenes[id]->show();
	left.show();
	right.show();
	//if (teacherMode) close.show();
}


void Interface::checkAllActive(const sf::Vector2i& msCord)
{
	left.checkActive(msCord);
	right.checkActive(msCord);
	close.checkActive(msCord);
}

void Interface::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	if (msCord != pastMsCord || first)
	{
		pastMsCord = msCord;
		left.checkFocus(msCord);
		right.checkFocus(msCord);
		if (teacherMode) close.checkFocus(msCord);
	}
}

void Interface::checkAllEvents(const sf::Vector2i& msCord)
{
	if(left.Event(msCord)) id = max(0, id - 1);
	else if(right.Event(msCord)) id = min(int(scenes.size()) - 1, id + 1);
}
