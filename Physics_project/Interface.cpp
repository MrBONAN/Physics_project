#include "Interface.h"
string pad(std::string s, int len = 26);

Interface::Interface(sf::RenderWindow& window) : Scene(window),
left(window, { SWITCHsize, 31, 31 }),
right(window, { SWITCHsize, 31, 31 }),
levelNumber(window, {INFOsize, 145, 20}),
close(window, { 65, 33, 97, 33, 0, 31, 31, 31, 31 }),
id(0),
startButton(window, { BUTTONsize, 145, 20 })/*,
menu(window, *this, scenes)*/
{
	startButton.setPosition(380, 300);
	startButton.setStr(pad("Начать тест" , 20));

	left.setPosition(72, 630);
	left.setScale(-2, 2);
	right.setPosition(973, 630);
	levelNumber.setPosition(390, 630);

	close.setPosition(350, 635);
	close.setScale(1);

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
	if (start && !end) {
		startButton.show();
		return;
	}
	scenes[id]->show();
	if (!menuIsActive && !end) {
		left.show();
		right.show();
		if (teacherMode && id != scenes.size() - 1) close.show();
		if (id != scenes.size() - 1) levelNumber.show();
	}
	
}

bool Interface::saveInfo(string pathSave) 
{
	fstream fout;
	fs::create_directory(".\\tasks");
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
	fs::create_directory(".\\tasks");
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
	if (teacherMode) close.checkActive(msCord);
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
				levelNumber.setStr(pad("Задание: 1 из: " + to_string(scenes.size() - 1), 21));
			}
			return;
		}

		if (left.Event(msCord)) id = max(0, id - 1);
		else if (right.Event(msCord)) id = min(int(scenes.size()) - 1, id + 1);
		levelNumber.setStr(pad("Задание: " + to_string(id + 1) + " из: " + to_string(scenes.size() - 1), 21));
	}
	if (teacherMode && close.Event(msCord) && id != scenes.size() - 1) {
		ConfirmWindow confirmwindow("Вы уверены, что хотите удалить это\nзадание? (действие нельзя отменить)");
		if (confirmwindow.loop() == "YES") {
			auto it = scenes.begin();
			advance(it, id);
			delete* it;
			scenes.erase(it);
			levelNumber.setStr(pad("Задание: " + to_string(id + 1) + " из: " + to_string(scenes.size() - 1), 21));
		}
	}
}
