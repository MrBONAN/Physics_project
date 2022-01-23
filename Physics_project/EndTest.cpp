#include "EndTest.h"
string pad(std::string s, int len = 26);

EndTest::EndTest(sf::RenderWindow& window, Interface& intface, vector<Scene*>& allScene)
	: Scene(window), intface(intface), allScene(allScene),
	//info   (window, { 145, 1, 145, 17, 145, 20, 5, 5, 5 }),
	endTest(window, { 49, 1, 65, 1, 145, 20, 5, 5, 5 }),
	result (window, { 145, 1, 145, 17, 175, 20, 5, 5, 5 }),
	exit   (window, { 49, 1, 65, 1, 145, 20, 5, 5, 5 })
{
	//info.setPosition(380, 200);
	//info.setStr("");

	endTest.setPosition(380, 250);
	endTest.setStr(pad("��������� ����", 20));


	result.setPosition(350, 200);

	exit.setPosition(380, 250);
	exit.setStr(pad("����� � ������� ����", 20));
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
		for (int i = 0; i < allScene.size() - 1; i++)
			score += allScene[i]->checkAnswer();
		result.setStr(pad("��� ���������: " + to_string(score) + " ��: " + to_string(allScene.size() - 1)));
		return;
	}
	if (exit.Event(msCord)) {
		for (int i = 0; i < allScene.size() - 1; i++)
			delete allScene[i];
		allScene.clear();
		allScene.push_back(intface.menu);
		intface.id = 0;
		return;
	}

}
