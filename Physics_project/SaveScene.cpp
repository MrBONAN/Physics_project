#include "SaveScene.h"

string pad(std::string s, int len = 26);
bool FileIsExist(std::string filePath);

SaveScene::SaveScene(sf::RenderWindow& window, Interface& intface, vector<Scene*>& allScene)
	: Scene(window), intface(intface), allScene(allScene),
	info(window, { INFOsize, 145, 20 })
{
	info.setPosition(380, 100);
	info.setStr(pad("Выберите действие", 19));
	for (int i = 0; i < 2; i++) {
		btns.push_back(new Button(window, { BUTTONsize, 190, 20 }));
		btns[i]->setPosition(335, 150 + i * 60);
	}
	btns[0]->setStr(pad("сохранить файл", 25));
	btns[1]->setStr(pad("выйти в меню", 25));
}

void SaveScene::show()
{
	info.show();
	for (auto& it : btns) it->show();
}

void SaveScene::checkAllActive(const sf::Vector2i& msCord)
{
	for (int i = 0; i < btns.size(); i++)
		btns[i]->checkActive(msCord);
}

void SaveScene::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	if (msCord != pastMsCord || first)
	{
		pastMsCord = msCord;
		for (auto& btn : btns)
			btn->checkFocus(msCord);
	}
}

void SaveScene::checkAllEvents(const sf::Vector2i& msCord)
{
	auto it = allScene.begin();
	advance(it, allScene.size() - 1);
	if (btns[0]->Event(msCord)) saveTest();
	if (btns[1]->Event(msCord)) menuExit();
}

void SaveScene::saveTest()
{
	for (int i = 0; i < allScene.size() - 1; i++) {
		if (!allScene[i]->haveTeacherAnswer()) {
			intface.id = i;
			intface.levelNumber.setStr(pad("Задание: " + to_string(i + 1) + " из: " + to_string(intface.scenes.size() - 1), 21));
			return;
		}
	}
	InputWindow inputwindow("Введите название нового файла без его\nрасширения.");
	string path = inputwindow.loop(CREATEfile);
	if (path != "CLOSE") {
		intface.saveInfo(path);
		for (int i = 0; i < allScene.size() - 1; i++)
			delete allScene[i];
		allScene.clear();
		allScene.push_back(intface.menu);
		intface.id = 0;
		intface.menuIsActive = true;
	}
}

void SaveScene::menuExit()
{
	ConfirmWindow confirmwindow("Вы уверены, что хотите выйти в меню?");
	if (confirmwindow.loop() == "YES") {
		for (int i = 0; i < allScene.size() - 1; i++)
			delete allScene[i];
		allScene.clear();
		allScene.push_back(intface.menu);
		intface.id = 0;
		intface.setEndTest(false);
		intface.menuIsActive = true;
	}
}
