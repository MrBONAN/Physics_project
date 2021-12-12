#include "Interface.h"
#include "AddScene.h"
#include "Menu.h"

Interface::Interface(sf::RenderWindow& window) : Scene(window),
left(window, { 81, 33, 113,33, 31, 31, 0, 31, 31 }),
right(window, { 81, 1, 113, 1, 31, 31, 0, 31, 31 }),
close(window, { 81, 1, 113, 1, 31, 31, 0, 31, 31 }),
id(0),
menu(window, scenes)
{
	left.setPosition(10, 630);
	right.setPosition(973, 630);
	btns.push_back(&left);
	btns.push_back(&right);
	btns.push_back(&close);

	scenes.push_back(&menu);
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

bool Interface::saveInfo(string pathSave) 
{
	fstream fout;
	fout.open(pathSave, fstream::out);
	if (fout.is_open())
		fout << *this;
	else {
		cout << "ERROR" << endl;
		fout.close();
		return false;
	}
	fout.close();
	return true;
}

bool Interface::readInfo(string pathRead)
{
	fstream fin;
	fin.open(pathRead, fstream::in);
	if (fin.is_open())
		fin >> *this;
	else {
		cout << "ERROR" << endl;
		fin.close();
		return false;
	}
	fin.close();
	return true;
	
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
