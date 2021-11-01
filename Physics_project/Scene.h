#ifndef _SCENE_H_
#define _SCENE_H_
#include "Button.h"
class Scene
{
public:
	Scene(sf::RenderWindow& window);
protected:
	
	sf::RenderWindow& window;
	Button exerciseRect;
};
#endif
