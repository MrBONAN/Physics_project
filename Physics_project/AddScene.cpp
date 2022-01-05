#include "AddScene.h"

string pad(std::string s, int len = 26);

void HideConsole();
void ShowConsole();

AddScene::AddScene(sf::RenderWindow& window, Scene& intface, vector<Scene*>& allScene)
	: Scene(window), intface(intface), allScene(allScene),
info(window, { 145, 1, 145, 17, 145, 20, 5, 5, 5 })
{
	info.setPosition(380, 100);
	info.setStr("Выберите тип задания");
	for (int i = 0; i < 4; i++) {
		btns.push_back(new Button(window, { 49, 1, 65, 1, 190, 20, 5, 5, 5 }));
		btns[i]->setPosition(335, 150 + i * 60);
	}
	btns[0]->setStr(pad("с вариантами ответа"));
	btns[1]->setStr(pad("с полем ввода"));
	btns[2]->setStr(pad("с сопоставлением вариантов"));
	btns[3]->setStr(pad("сохранить файл"));
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
		cout << "Введите название нового файла без его расширения." << endl;
		cout << "Если вы хотите выйти из этого окна, введите \"-1\" (без кавычек): ";
		cin >> fileName;
		if (fileName == "-1") {
			HideConsole();
			system("cls");
			return;
		}

		fileName += ".mfp";
		cout << "Введённое имя файла: " << fileName << endl;
		
		// создание (и по сути проверка) папки
		string path = "tasks\\" + fileName;
		CreateDirectory(L"tasks", NULL);

		// проверка на наличие файла
		WIN32_FIND_DATA file;
		HANDLE h = FindFirstFile(LPCWSTR(path.c_str()), &file);
		FindClose(h);
		
		// доделать нормальную проверку
		if ((WCHAR *)fileName.c_str() == file.cFileName) {
			cout << "Файл с таким именем уже существует. Вы хотете перезаписать файл? Если да, то введите \"ДА\" (без кавычек), если хотите изменить имя, введите \"-1\" (или что-либо другое): ";
			string temp;
			SetConsoleCP(1251);
			cin >> temp;
			SetConsoleCP(866);
			// нормализовать ввод ("ДА" вводится странными буквами)
			if (temp != "ДА\0") { cout << endl; continue; }
		} 
		
		// сохранение в файл
		if (!intface.saveInfo(path)) {
			cout << "Что-то пошло не так. Закройте файл теста, если он открыт, и попробуйте снова." << endl;
		} else {
			HideConsole(); system("cls");
			window.close();
			return;
		}
	}
}
