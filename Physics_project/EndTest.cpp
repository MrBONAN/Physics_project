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
	if (!testIsEnd) {
		//info.show();
		endTest.show();
		return;
	}
	result.show();
	exit.show();
}

void EndTest::checkAllActive(const sf::Vector2i& msCord)
{
	if (!testIsEnd) { endTest.checkActive(msCord); return; }
	exit.checkActive(msCord);
}

void EndTest::checkAllFocus(const sf::Vector2i& msCord, bool first)
{
	if (!testIsEnd) { endTest.checkFocus(msCord); return; }
	exit.checkFocus(msCord);
}

void EndTest::checkAllEvents(const sf::Vector2i& msCord)
{
	if (!testIsEnd && endTest.Event(msCord)) {
		int score = 0;
		testIsEnd = true;
		intface.setEndTest(true);
		for (int i = 0; i < allScene.size() - 1; i++)
			score += allScene[i]->checkAnswer();
		result.setStr(pad("Ваш результат: " + to_string(score) + " из: " + to_string(allScene.size() - 1)));
		return;
	}
	if (exit.Event(msCord)) {
		for (int i = 0; i < allScene.size() - 1; i++)
			delete allScene[i];
		allScene.clear();
		allScene.push_back(intface.menu);
		intface.id = 0;
		intface.setEndTest(false);
		return;
	}

}
