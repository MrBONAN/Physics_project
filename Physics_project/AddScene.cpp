#include "AddScene.h"

AddScene::AddScene(sf::RenderWindow& window, vector<Scene*>& allScene)
	: Scene(window), allScene(allScene),
info(window, { 145, 1, 145, 17, 145, 20, 5, 5, 5 })
{
	info.setPosition(380, 100);
	info.setStr("Выберите тип задания");
	for (int i = 0; i < 3; i++) {
		btns.push_back(new Button(window, { 49, 1, 65, 1, 190, 20, 5, 5, 5 }));
		btns[i]->setPosition(335, 150 + i * 60);
	}
	btns[0]->setStr("       с вариантами ответа");
	btns[1]->setStr("            с полем ввода ");
	btns[2]->setStr("с сопоставлением вариантов");
}

void AddScene::checkAllInteraction(const sf::Event& event)
{
	//кнопка только что нажата
	if (event.type == sf::Event::MouseButtonPressed) {
		checkAllActive(sf::Mouse::getPosition(window));
		checkAllFocus(sf::Mouse::getPosition(window), true);
	}
	//кнока нажата в данный момент
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		checkAllFocus(sf::Mouse::getPosition(window));
	}
	//кнопка была отпущена
	if (event.type == sf::Event::MouseButtonReleased) {
		checkAllEvents(sf::Mouse::getPosition(window));
	}
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
	if (btns[1]->Event(msCord));//allScene.insert(it, new Test(window));
	if (btns[2]->Event(msCord));//allScene.insert(it, new Test(window));

}
