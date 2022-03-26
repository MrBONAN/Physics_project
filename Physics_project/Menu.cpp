#include "Menu.h"

string pad(std::string s, int len = 26);

void HideConsole();
void ShowConsole();

Menu::Menu(sf::RenderWindow& window, Interface& intface, vector<Scene*>& allScene)
	: Scene(window), intface(intface), allScene(allScene),
	info(window, { INFOsize, 145, 20 })
{
	info.setPosition(380, 100);
	info.setStr("  Выберите действие");
	for (int i = 0; i < 3; i++) {
		btns.push_back(new Button(window, { BUTTONsize, 190, 20}));
		btns[i]->setPosition(335, 150 + i * 60);
	}
	btns[0]->setStr(pad("открыть тест"));
	btns[1]->setStr(pad("создать тест"));
	btns[2]->setStr(pad("редактировать тест"));
	savescene = new SaveScene(window, intface, allScene);
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
	if (btns[0]->Event(msCord)) solveTest();
	if (btns[1]->Event(msCord)) makeTest();
	if (btns[2]->Event(msCord)) editTest();
	
}

bool Menu::openTest()
{
	//InputWindow inputwindow("Введите название файла без его\nрасширения (он должен находиться в\nпапке tasks рядом с этой программой)");
	//string path = inputwindow.loop(typeInput::OPENfile);
	SelectWindow selectwindow;
	string path = selectwindow.loop();
	//cout << path << endl;
	if (path != "CLOSE") {
		intface.readInfo(path);
		return true;
	}
	return false;
}
void Menu::solveTest()
{
	if (openTest()) {
		menuIsActive = false;
		allScene.push_back(new EndTest(window, intface, allScene));
		intface.setStartTest(true);
	}
}
void Menu::makeTest()
{
	intface.setTeacherMod(true);
	allScene[0] = savescene;
	menuIsActive = false;
}

void Menu::editTest()
{
	if (openTest()) {
		setTeacherMod(true);
		intface.levelNumber.setStr(pad("Задание: 1 из: " + to_string(intface.scenes.size()), 21));
		intface.setTeacherMod(true);
		menuIsActive = false;
		allScene.push_back(savescene);
		for (auto it : allScene)
			it->showAnswer();
	}
}
