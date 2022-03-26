#include "EndTest.h"
string pad(std::string s, int len = 26);

EndTest::EndTest(sf::RenderWindow& window, Interface& intface, vector<Scene*>& allScene)
	: Scene(window), intface(intface), allScene(allScene),
	//info   (window, { 145, 1, 145, 17, 145, 20, 5, 5, 5 }),
	endTest(window, { BUTTONsize, 145, 20}),
	result (window, { INFOsize,   175, 20}),
	exit   (window, { BUTTONsize, 145, 20})
{
	//info.setPosition(380, 200);
	//info.setStr("");

	endTest.setPosition(380, 250);
	endTest.setStr(pad("Закончить тест", 20));

	result.setPosition(350, 250);

	exit.setPosition(380, 300);
	exit.setStr(pad("Выход в главное меню", 20));
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
		result.setStr(pad("Ваш результат: " + to_string(score) + " из: " + to_string(allScene.size() - 1)));
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
