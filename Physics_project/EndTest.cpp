#include "EndTest.h"
string pad(std::string s, int len = 26);

EndTest::EndTest(sf::RenderWindow& window, Interface& intface, vector<Scene*>& allScene)
	: Scene(window), intface(intface), allScene(allScene),
	//info   (window, { 145, 1, 145, 17, 145, 20, 5, 5, 5 }),
	endTest(window, { BUTTONsize, 155, 22}),
	result (window, { INFOsize,   230, 22}), // 175 20
	exit   (window, { BUTTONsize, 210, 22})
{
	//info.setPosition(380, 200);
	//info.setStr("");

	endTest.setPosition(370, 250);
	endTest.setCharacterSize(33);
	endTest.setIndentText(0);
	endTest.setStr(pad("Закончить тест", 16));

	result.setPosition(295, 250);
	result.setCharacterSize(33);
	result.setIndentText(0);

	exit.setPosition(315, 300);
	exit.setCharacterSize(33);
	exit.setIndentText(0);
	exit.setStr(pad("Выход в главное меню", 21));
}

void EndTest::show()
{
	exit.show();
	if (!testIsEnd) {
		//info.show();
		endTest.show();
		return;
	}
	result.show();
}

void EndTest::checkAllActive(const sf::Vector2i& msCord)
{
	if (!testIsEnd) endTest.checkActive(msCord);
	exit.checkActive(msCord);
}

void EndTest::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	if (!testIsEnd) endTest.checkFocus(msCord);
	exit.checkFocus(msCord);
}

void EndTest::checkAllEvents(const sf::Vector2i& msCord)
{
	if (!testIsEnd && endTest.Event(msCord)) {
		ConfirmWindow confirmwindow("Вы уверены, что хотите закончить тест?");
		if (confirmwindow.loop() != "YES") return;
		int score = 0;
		testIsEnd = true;
		intface.setEndTest(true);
		for (int i = 0; i < allScene.size() - 1; i++) {
			if (!allScene[i]->haveAnswer()) {
				intface.id = i;
				intface.levelNumber.setStr(pad("Задание: " + to_string(i + 1) + " из: " + to_string(intface.scenes.size() - 1), 21));;
				testIsEnd = false;
				intface.setEndTest(false);
				return;
			}
			score += allScene[i]->checkAnswer();
		}
		result.setStr(pad("Ваш результат: " + to_string(score) + " из: " + to_string(allScene.size() - 1), 25));
	}
	if (exit.Event(msCord)) {
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
		return;
	}

}
