#include "AddScene.h"

string pad(std::string s, int len = 26);
bool FileIsExist(std::string filePath);

void HideConsole();
void ShowConsole();

AddScene::AddScene(sf::RenderWindow& window, Interface& intface, vector<Scene*>& allScene)
	: Scene(window), intface(intface), allScene(allScene),
info(window, { INFOsize, 145, 20 })
{
	info.setPosition(380, 100);
	info.setStr("�������� ��� �������");
	for (int i = 0; i < 4; i++) {
		btns.push_back(new Button(window, { BUTTONsize, 190, 20 }));
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
	string fileName;
	ShowConsole();
	while (true) {
		cout << "������� �������� ������ ����� ��� ��� ����������." << endl;
		cout << "���� �� ������ ����� �� ����� ����, ������� \"-1\" (��� �������): ";
		cin >> fileName;
		if (fileName == "-1") {
			HideConsole();
			system("cls");
			return;
		}

		fileName += ".mfp";
		cout << "�������� ��� �����: " << fileName << endl;
		
		// �������� (� �� ���� ��������) �����
		string path = "tasks\\" + fileName;
		CreateDirectory(L"tasks", NULL);

		// �������� �� ������� �����
		if(FileIsExist(path)){ // ������ �� �����
			cout << "���� � ����� ������ ��� ����������. �� ������ ������������ ����? ���� ��, �� ������� \"��\" (��� �������), ���� ������ �������� ���, ������� \"-1\" (��� ���-���� ������): ";
			string temp;
			SetConsoleCP(1251);
			cin >> temp;
			SetConsoleCP(866);
			// ������������� ���� ("��" �������� ��������� �������)
			if (temp != "��\0") { cout << endl; continue; }
		} 
		
		// ���������� � ����
		if (!intface.saveInfo(path)) {
			cout << "���-�� ����� �� ���. �������� ���� �����, ���� �� ������, � ���������� �����." << endl;
		} else {
			HideConsole(); system("cls");
			for (int i = 0; i < allScene.size() - 1; i++)
				delete allScene[i];
			allScene.clear();
			allScene.push_back(intface.menu);
			intface.id = 0;
			return;
		}
	}
}

bool FileIsExist(std::string filePath)
{
	bool isExist = false;
	std::ifstream fin(filePath.c_str());

	if (fin.is_open())
		isExist = true;

	fin.close();
	return isExist;
}
