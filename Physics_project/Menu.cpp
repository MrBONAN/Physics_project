#include "Menu.h"

string pad(std::string s, int len = 26);

void HideConsole();
void ShowConsole();

Menu::Menu(sf::RenderWindow& window, Scene& intface, vector<Scene*>& allScene)
	: Scene(window), intface(intface), allScene(allScene),
	info(window, { 145, 1, 145, 17, 145, 20, 5, 5, 5 })
{
	info.setPosition(380, 100);
	info.setStr("  �������� ��������");
	for (int i = 0; i < 3; i++) {
		btns.push_back(new Button(window, { 49, 1, 65, 1, 190, 20, 5, 5, 5 }));
		btns[i]->setPosition(335, 150 + i * 60);
	}
	btns[0]->setStr(pad("������� ����"));
	btns[1]->setStr(pad("������� ����"));
	btns[2]->setStr(pad("������������� ����"));
	addscene = new AddScene(window, intface, allScene);
}

void Menu::show()
{
	info.show();
	for (auto& it : btns)
		it->show();

}

void Menu::checkAllActive(const sf::Vector2i& msCord)
{
	for (int i = 0; i < btns.size(); i++)
		btns[i]->checkActive(msCord);
}

void Menu::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	if (msCord != pastMsCord || first)
	{
		pastMsCord = msCord;
		for (int i = 0; i < btns.size(); i++)
			btns[i]->checkFocus(msCord);
	}
}

void Menu::checkAllEvents(const sf::Vector2i& msCord)
{
	auto it = allScene.begin();
	advance(it, allScene.size() - 1);
	if (btns[0]->Event(msCord)) openTest();
	if (btns[1]->Event(msCord)) makeTest();
	if (btns[2]->Event(msCord)) editTest();
	
}

void Menu::openTest()
{
	string path;
	ShowConsole();
	cout << "������� �������� ����� ��� ��� ���������� (�� ������ ���������� � ����� � ������ ����������)" << endl;
	cout << "���� �� ������ ����� �� ����� ����, ������� \"-1\" (��� �������): ";
	while (1) {
		cin >> path;
		if (path == "-1") {
			HideConsole();
			system("cls");
			return;
		}
		path += ".mfp";
		cout << "�������� ����: " << path << endl;
		if (!intface.readInfo(path)) {
			cout << "��������� ���� �� ����������, ��� �� ����� ��� �������� �� ���. ���������� ����� ��� ������� \"-1\": ";
		}
		else {
			HideConsole(); system("cls");
			intface.menuIsActive = false;
			return;
		}
	}
}
void Menu::makeTest()
{
	allScene[0] = addscene;
	menuIsActive = false;
}

void Menu::editTest()
{

}
