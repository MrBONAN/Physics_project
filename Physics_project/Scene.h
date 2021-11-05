#ifndef _SCENE_H_
#define _SCENE_H_
#include "Button.h"
#include "Indicator.h"
#include <windows.h>
class Scene
{
public:
	Scene(sf::RenderWindow& window);

	void setTeacherMod(bool tf) { teacherMode = tf;}

	void setText(Button& btn, const sf::Event& event);

	virtual void checkAllInteraction(const sf::Event& event) = 0;
	
	virtual void show() = 0;
protected:
	virtual void checkAllActive(const sf::Vector2i& msCord) = 0;
	virtual void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  = 0;
	virtual void checkAllEvents(const sf::Vector2i& msCord) = 0;
	

	sf::RenderWindow& window;
	Button exerciseRect;

	static bool teacherMode;

	int enCode = 67699721;
	int ruCode = 68748313;
	map<int, int> enKey;
	map<int, int> ruKey;
	map<int, int> enSymbKey;
	map<int, int> ruSymbKey;
	map<int, int> specChar;
	int selSymbol( int key, const map<int, int>& langKey,
				   const map<int, int>& langSymbKey);
};
#endif
