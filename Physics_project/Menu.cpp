#include "Menu.h"
string pad(std::string s, int len = 26);

Menu::Menu(sf::RenderWindow& window, vector<Scene*>& allScene)
	: Scene(window), allScene(allScene),
	info(window, { 145, 1, 145, 17, 145, 20, 5, 5, 5 })
{
	info.setPosition(380, 100);
	info.setStr("  Выберите действие");
	for (int i = 0; i < 3; i++) {
		btns.push_back(new Button(window, { 49, 1, 65, 1, 190, 20, 5, 5, 5 }));
		btns[i]->setPosition(335, 150 + i * 60);
	}
	btns[0]->setStr(pad("открыть тест"));
	btns[1]->setStr(pad("создать тест"));
	btns[2]->setStr(pad("редактировать тест"));
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
	if (btns[0]->Event(msCord)) allScene[0] = new AddScene(window, allScene);
	if (btns[1]->Event(msCord)) allScene.insert(it, new writeAns(window));
	if (btns[2]->Event(msCord));//allScene.insert(it, new Test(window));
}