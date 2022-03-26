#include "AddScene.h"

string pad(std::string s, int len = 26);

AddScene::AddScene()
	: MyWindows({ 390, 155 }, { 150, 20 }, // 260 50
		"Выберите тип задания")
{
    info.setScale(2);
    info.setPosition(45, 5);

	for (int i = 0; i < 2; i++) {
		btns.push_back(new Button(window, { BUTTONsize, 190, 20 }));
		btns[i]->setPosition(5, 60 + i * 50);
	}
	btns[0]->setStr(pad("с вариантами ответа"));
	btns[1]->setStr(pad("с полем ввода"));
	//btns[2]->setStr(pad("с сопоставлением вариантов"));

	showBtns.push_back(&info);
    showBtns.push_back(btns[0]);
    showBtns.push_back(btns[1]);
}

AddScene::~AddScene()
{
	for (auto it : btns) delete it;
}

void AddScene::checkAllEvents(const sf::Vector2i& msCord)
{
	if (btns[0]->Event(msCord)) result = to_string(typeTest::TEST);
	if (btns[1]->Event(msCord)) result = to_string(typeTest::WRITEANS);

}
