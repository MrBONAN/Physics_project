#include "Button.h"
Button::Button(sf::RenderWindow& window, vector<int> sizes) : OBJ(window)
{
	x1 = sizes[0], y1 = sizes[1];
	x2 = sizes[2], y2 = sizes[3];
	dx = sizes[4], dy = sizes[5];
	float xyCorner = sizes[6];
	float yLeftRight = sizes[7];
	float xTopButtom = sizes[8];
	makeTexture(0, dx, dy, renderTex, defTexture, { float(x1), float(y1), xyCorner, yLeftRight, xTopButtom });
	texture = renderTex.getTexture();
	btn.setTexture(texture);
	btn.setTextureRect(sf::IntRect(0, 0, dx, dy));
	setScale(2);
}

Button::Button(sf::RenderWindow& window) : OBJ(window)
{
	this->x1 = 17, this->y1 = 49;
	this->x2 = 17, this->y2 = 17;
	this->dx = 250, this->dy = 50;
	renderTex.clear(sf::Color(0, 0, 0, 0));
	makeTexture(0, dx, dy, renderTex, defTexture, { float(x1), float(y1), 5, 5, 5 });
	makeTexture(dy, dx, dy, renderTex, defTexture, { float(x2), float(y2), 4, 7, 7 });
	texture = renderTex.getTexture();
	btn.setTexture(texture);
	setSprite1();
	setScale(2);
}

void Button::checkFocus(const sf::Vector2i& msCord)
{
	if ((mouseJustPressed || active) && btn.getGlobalBounds().contains(msCord.x, msCord.y)) {
		if (isAlreadyUpdate) return;
		isAlreadyUpdate = true;
		active = true;
		cout << 2 << endl;
		setSprite2();
	}
	else if (active)
	{
		if (isAlreadyUpdate) {
			isAlreadyUpdate = false;
			cout << 1 << endl;
			setSprite1();
		}
	}
}

bool Button::Event(const sf::Vector2i& msCord)
{
	if (active && btn.getGlobalBounds().contains(msCord.x, msCord.y))
	{
		isAlreadyUpdate = false;
		setSprite1();
		active = false;
		// добавить useFunc
		return true;
	}
	return false;
}