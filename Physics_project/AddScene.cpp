#include "AddScene.h"

string pad(std::string s, int len = 26);

void HideConsole();
void ShowConsole();

AddScene::AddScene(sf::RenderWindow& window, Scene& intface, vector<Scene*>& allScene)
	: Scene(window), intface(intface), allScene(allScene),
info(window, { 145, 1, 145, 17, 145, 20, 5, 5, 5 })
{
	info.setPosition(380, 100);
	info.setStr("�������� ��� �������");
	for (int i = 0; i < 4; i++) {
		btns.push_back(new Button(window, { 49, 1, 65, 1, 190, 20, 5, 5, 5 }));
		btns[i]->setPosition(335, 150 + i * 60);
	}
	btns[0]->setStr(pad("� ���������� ������"));
	btns[1]->setStr(pad("� ����� �����"));
	btns[2]->setStr(pad("� �������������� ���������"));
	btns[3]->setStr(pad("��������� ����"));
}

void AddScene::show()
{
	info.show();
	for (auto& it : btns)
		it->show();
	
}

void AddScene::checkAllActive(const sf::Vector2i& msCord)
{
	for (int i = 0; i < btns.size(); i++)
		btns[i]->checkActive(msCord);
}
void AddScene::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	if (msCord != pastMsCord || first)
	{
		pastMsCord = msCord;
		for (int i = 0; i < btns.size(); i++)
			btns[i]->checkFocus(msCord);
	}
}

void AddScene::checkAllEvents(const sf::Vector2i& msCord)
{
	auto it = allScene.begin();
	advance(it, allScene.size() - 1);
	if (btns[0]->Event(msCord)) allScene.insert(it, new Test(window));
	if (btns[1]->Event(msCord)) allScene.insert(it, new writeAns(window));
	if (btns[2]->Event(msCord));//allScene.insert(it, new Test(window));
	if (btns[3]->Event(msCord)) saveTest();
}

void AddScene::saveTest()
{
	string path;
	ShowConsole();
	while (1) {
		cout << "������� �������� ������ ����� ��� ��� ����������." << endl;
		cout << "���� �� ������ ����� �� ����� ����, ������� \"-1\" (��� �������): ";
		cin >> path;
		if (path == "-1") {
			HideConsole();
			system("cls");
			return;
		}
		path += ".mfp";
		cout << "�������� ��� �����: " << path << endl;
		if (std::experimental::filesystem::exists(path)) {
			cout << "���� � ����� ������ ��� ����������. �� ������ ������������ ����? ���� ��, �� ������� \"��\" (��� �������), ���� ������ �������� ���, ������� \"-1\" (��� ���-���� ������): ";
			string temp;
			cin >> temp;
			// ������������� ���� ("��" �������� ��������� �������)
			if (temp != "��\0") { cout << endl; continue; }
		} 

		if (!intface.saveInfo(path)) {
			cout << "���-�� ����� �� ���. �������� ���� �����, ���� �� ������, � ���������� �����." << endl;
		} else {
			HideConsole(); system("cls");
			window.close();
			return;
		}
	}
}
