#include "EndTest.h"
string pad(std::string s, int len = 26);

EndTest::EndTest(sf::RenderWindow& window, Interface& intface, vector<Scene*>& allScene)
	: Scene(window), intface(intface), allScene(allScene),
	info(window, { 145, 1, 145, 17, 145, 20, 5, 5, 5 }),
	endTest(window, { 49, 1, 65, 1, 145, 20, 5, 5, 5 })
{
	info.setPosition(380, 100);
	info.setStr("Выберите тип задания");

	endTest.setPosition(380, 150);
	endTest.setStr(pad("Закончить тест", 20));
}

void EndTest::show()
{
	info.show();
	endTest.show();
}
