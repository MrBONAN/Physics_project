#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "OBJ.h"
class Button : public OBJ
{
public:
	Button(sf::RenderWindow& window, vector<int> sizes);
	Button(sf::RenderWindow& window);

	void setPosition(float x, float y) override { btn.setPosition(sf::Vector2f(x, y));}
	void setScale(float d) override { btn.setScale(d, d); }

	void show() { window.draw(btn); }
private:


	// координаты текстуры на исходном изображении
	int x1 = 0, x2 = 0;
	int y1 = 0, y2 = 0;
	int dx = 70, dy = 15;



	//
	sf::Sprite btn;
};
#endif
