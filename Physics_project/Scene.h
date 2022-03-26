#pragma once
#include "Classes.h"
#include "Button.h"
#include "Indicator.h"
#include <windows.h>
#include <fstream>
class Scene
{
public:
	Scene(sf::RenderWindow& window);

	void setTeacherMod(bool tf) { teacherMode = tf;}
	virtual void showAnswer() { return; };
	virtual bool checkAnswer() { return false; }

	void checkAllInteraction(const sf::Event& event);
	
	virtual void show() = 0;

	// костыли для Interface
	/*virtual bool saveInfo(string path) { return false; }
	virtual bool readInfo(string path) { return false; }
	virtual void SwitchStartTest() {}*/
	virtual bool haveAnswer() { return true; }
	virtual bool haveTeacherAnswer() { return true; }
	Button exerciseRect;

	int selNumber = -1;

	virtual ~Scene() {}
protected:
	virtual void checkAllActive(const sf::Vector2i& msCord) = 0;
	virtual void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  = 0;
	virtual void checkAllEvents(const sf::Vector2i& msCord) = 0;
	virtual void setAllText(const sf::Event& event) {};
	
	virtual string outInfo() { return string(); }
	virtual void inpInfo(istream& is) {}
	string answer;

	sf::RenderWindow& window;

	static bool teacherMode;
	static bool menuIsActive;

	sf::Vector2i pastMsCord;
	vector<Button*> btns;

	friend ostream& operator<<(ostream& os, Scene& obj);
	friend istream& operator>>(istream& is, Scene& obj);
	friend EndTest;
	friend Interface;
};
