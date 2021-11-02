#ifndef _SCENE_H_
#define _SCENE_H_
#include "Button.h"
#include "Indicator.h"
class Scene
{
public:
	Scene(sf::RenderWindow& window);
	virtual void checkALlInteraction(const sf::Event& event) = 0;
protected:
	virtual void checkAllActive(const sf::Vector2i& msCord) = 0;
	virtual void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  = 0;
	virtual void checkAllEvents(const sf::Vector2i& msCord) = 0;

	sf::RenderWindow& window;
	Button exerciseRect;
};
#endif
