#include "Interface.h"
string pad(std::string s, int len = 26);

Interface::Interface(sf::RenderWindow& window) : Scene(window),
left(window, { 81, 33, 113,33, 31, 31, 0, 31, 31 }),
right(window, { 81, 1, 113, 1, 31, 31, 0, 31, 31 }),
close(window, { 81, 1, 113, 1, 31, 31, 0, 31, 31 }),
id(0),
startButton(window, { 49, 1, 65, 1, 145, 20, 5, 5, 5 })/*,
menu(window, *this, scenes)*/
{
	startButton.setPosition(380, 300);
	startButton.setStr(pad("Начать тест" , 20));

	left.setPosition(10, 630);
	right.setPosition(973, 630);
	btns.push_back(&left);
	btns.push_back(&right);
	btns.push_back(&close);

	menu = new Menu(window, *this, scenes);
	scenes.push_back(menu);

	//menu.intface = this;
}

void Interface::checkAllInteractions(const sf::Event& event)
{
	checkAllInteraction(event); 
	scenes[id]->checkAllInteraction(event);
}

void Interface::show()
{
	if (start) {
		startButton.show();
		return;
	}
	scenes[id]->show();
	if (!menuIsActive) {
		left.show();
		right.show();
	}//if (teacherMode) close.show();
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

void Interface::SwitchStartTest()
{
	start = !start;
}

Interface::~Interface()
{
	for (auto& it : scenes) {
		if (it != nullptr) {
			delete it;
			it = nullptr;
		}
	}
	//if (menu != nullptr)
	//{
	//	//delete menu;
	//	menu = nullptr;
	//} // Не знаю как решить эту ошибку, поэтму просто закрою на неё глаза (тут возможна утечка памяти)
	// это происоходит из-за того, что мы как-бы чистим память в цикле выше этого условия
	// но мы не меняем адрес в ПЕРЕМЕННОЙ menu, и она указывает на уже очищенную память
	// и пытается опять её очистить. Для этого, по-хорошему, надо как-то в цикле делать menu = nullptr, но как...
}


void Interface::checkAllActive(const sf::Vector2i& msCord)
{
	if (!menuIsActive) {
		if (start) {
			startButton.checkActive(msCord);
			return;
		}
		left.checkActive(msCord);
		right.checkActive(msCord);
	}
	close.checkActive(msCord);
}

void Interface::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	if (msCord != pastMsCord || first)
	{
		if (start) {
			startButton.checkFocus(msCord);
			return;
		}

		pastMsCord = msCord;
		if (!menuIsActive) {
			left.checkFocus(msCord);
			right.checkFocus(msCord);
		}
		if (teacherMode) close.checkFocus(msCord);
	}
}

void Interface::checkAllEvents(const sf::Vector2i& msCord)
{
	if (!menuIsActive) {
		if (start) {
			if (startButton.Event(msCord)) {
				start = false;
				setTeacherMod(false);
				scenes[0]->exerciseRect.setSprite1();
			}
			return;
		}

		if (left.Event(msCord)) id = max(0, id - 1);
		else if (right.Event(msCord)) id = min(int(scenes.size()) - 1, id + 1);
	}
}
