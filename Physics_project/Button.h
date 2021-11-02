#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "OBJ.h"
class Button : public OBJ
{
public:
	Button(sf::RenderWindow& window, vector<float> sizes);
	Button(sf::RenderWindow& window);

	void setPosition(float x, float y) override { btn.setPosition(sf::Vector2f(x, y));}
	void setScale(float d) override { btn.setScale(d, d); }
	void setSprite1() override {btn.setTextureRect(sf::IntRect(0, 0, dx, dy));}
	void setSprite2() override {btn.setTextureRect(sf::IntRect(0, dy, dx, dy));}



	void checkActive(const sf::Vector2i& msCord) override;
	void checkFocus(const sf::Vector2i& msCord) override;
	bool Event(const sf::Vector2i& msCord) override;


	void show() { window.draw(btn); }
private:
	// визуальные эффекты нажатия
	bool active = false;
	bool isAlreadyUpdate = false; // чтобы постоянно не менять спрайт

	// координаты текстуры на исходном изображении
	float x1 = 0, x2 = 0;
	float y1 = 0, y2 = 0;
	int dx = 70, dy = 15;

	sf::Sprite btn;
};
#endif
