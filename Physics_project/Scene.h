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

	virtual void checkALlInteraction(const sf::Event& event) = 0;
protected:
	virtual void checkAllActive(const sf::Vector2i& msCord) = 0;
	virtual void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  = 0;
	virtual void checkAllEvents(const sf::Vector2i& msCord) = 0;

	sf::RenderWindow& window;
	Button exerciseRect;

	bool teacherMode = true;
	int enCode = 67699721;
	int ruCode = 68748313;
	map<int, char> enKey;
	map<int, char> ruKey;
	map<int, char> enSymbKey;
	map<int, char> ruSymbKey;
};
#endif
