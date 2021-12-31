#pragma once
#include "OBJ.h"
class Indicator :
    public OBJ
{
public:
	Indicator(sf::RenderWindow& window, vector<float> sizes);
	//Indicator(sf::RenderWindow& window);

	void setPosition(float x, float y) override { ind.setPosition(sf::Vector2f(x, y)); }
	void setScale(float d) override { ind.setScale(d, d); }
	
	void off() { setSprite1(); active = false; }
	void on()  { setSprite2(); active = true;  }
	void switching() { active ? off() : on(); }
	bool getActive() { return active; }

	void setSprite1() override { ind.setTextureRect(sf::IntRect(0, 0, dx, dy)); }
	void setSprite2() override { ind.setTextureRect(sf::IntRect(0, dy, dx, dy)); }

	void show() { window.draw(ind); }

	void checkActive(const sf::Vector2i& msCord) override {}
	void checkFocus(const sf::Vector2i& msCord) override {}
	bool Event(const sf::Vector2i& msCord) override { return false; }

private:
	bool active = false;

	// координаты текстуры на исходном изображении
	float x1 = 1, x2 = 1;
	float y1 = 33, y2 = 1;
	int dx = 15, dy = 15;

	sf::Sprite ind;
};
