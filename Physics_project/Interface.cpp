#include "Interface.h"
string pad(std::string s, int len = 26);

Interface::Interface(sf::RenderWindow& window) : Scene(window),
left(window, { 81, 33, 113, 33, 0, 31, 31, 31, 31 }),
right(window, { 81, 1, 113, 1, 0, 31, 31, 31, 31 }),
levelNumber(window, {INFOsize, 145, 20}),
close(window, { 81, 1, 113, 1, 0, 31, 31, 31, 31 }),
id(0),
startButton(window, { BUTTONsize, 145, 20 })/*,
menu(window, *this, scenes)*/
{
	startButton.setPosition(380, 300);
	startButton.setStr(pad("������ ����" , 20));

	left.setPosition(10, 630);
	//left.setPosition(72, 692);
	//left.setScale(-2);
	right.setPosition(973, 630);
	levelNumber.setPosition(390, 630);

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
		if (id != scenes.size() - 1) levelNumber.show();
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
	//} // �� ���� ��� ������ ��� ������, ������ ������ ������ �� �� ����� (��� �������� ������ ������)
	// ��� ����������� ��-�� ����, ��� �� ���-�� ������ ������ � ����� ���� ����� �������
	// �� �� �� ������ ����� � ���������� menu, � ��� ��������� �� ��� ��������� ������
	// � �������� ����� � ��������. ��� �����, ��-��������, ���� ���-�� � ����� ������ menu = nullptr, �� ���...
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
				levelNumber.setStr(pad("�������: 1 ��: " + to_string(scenes.size() - 1), 21));
			}
			return;
		}

		if (left.Event(msCord)) id = max(0, id - 1);
		else if (right.Event(msCord)) id = min(int(scenes.size()) - 1, id + 1);
		levelNumber.setStr(pad("�������: " + to_string(id + 1) + " ��: " + to_string(scenes.size() - 1), 21));
	}
}
