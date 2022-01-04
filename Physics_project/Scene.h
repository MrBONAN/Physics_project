#pragma once
#include "Button.h"
#include "Indicator.h"
#include <windows.h>
#include <fstream>
class Scene
{
public:
	Scene(sf::RenderWindow& window);

	void setTeacherMod(bool tf) { teacherMode = tf;}

	void setText(Button& btn, const sf::Event& event);

	void checkAllInteraction(const sf::Event& event);
	
	virtual void show() = 0;

	// костыли
	virtual bool saveInfo(string path) = 0;
	virtual bool readInfo(string path) = 0;

protected:
	virtual void checkAllActive(const sf::Vector2i& msCord) = 0;
	virtual void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  = 0;
	virtual void checkAllEvents(const sf::Vector2i& msCord) = 0;
	virtual void setAllText(const sf::Event& event) = 0;
	
	virtual string outInfo() = 0;
	virtual void inpInfo(istream& is) = 0;
	string answer;

	sf::RenderWindow& window;
	Button exerciseRect;

	static bool teacherMode;
	static bool menuIsActive;

	sf::Vector2i pastMsCord;
	vector<Button*> btns;

	int enCode = 67699721;
	int ruCode = 68748313;
	map<int, int> enKey;
	map<int, int> ruKey;
	map<int, int> enSymbKey;
	map<int, int> ruSymbKey;
	map<int, int> specChar;
	int selSymbol( int key, const map<int, int>& langKey,
				   const map<int, int>& langSymbKey);

	friend ostream& operator<<(ostream& os, Scene& obj);
	friend istream& operator>>(istream& is, Scene& obj);
};
