#include "Button.h"
Button::Button(sf::RenderWindow& window, vector<float> sizes) : OBJ(window)
{
	x1 = sizes[0], y1 = sizes[1];
	x2 = sizes[2], y2 = sizes[3];
	dx = sizes[4], dy = sizes[5];
	renderTex.clear(sf::Color(0, 0, 0, 0));
	makeTexture(0, dx, dy, renderTex, defTexture, { x1, y1, sizes[6], sizes[7], sizes[8] });
	makeTexture(dy, dx, dy, renderTex, defTexture, { x2, y2, sizes[6], sizes[7], sizes[8] });
	texture = renderTex.getTexture();
	btn.setTexture(texture);
	setSprite1();
	setScale(2);
}

Button::Button(sf::RenderWindow& window) : OBJ(window)
{
	x1 = 17,  y1 = 49;
	x2 = 17,  y2 = 17;
	dx = 250, dy = 50;
	renderTex.clear(sf::Color(0, 0, 0, 0));
	makeTexture(0, dx, dy, renderTex, defTexture, { x1, y1, 5, 5, 5 });
	makeTexture(dy, dx, dy, renderTex, defTexture, {x2, y2, 4, 7, 7 });
	texture = renderTex.getTexture();
	btn.setTexture(texture);
	setSprite1();
	setScale(2);
}

void Button::checkActive(const sf::Vector2i& msCord)
{
	if (btn.getGlobalBounds().contains(msCord.x, msCord.y))
		active = true;
}

void Button::checkFocus(const sf::Vector2i& msCord)
{
	if (/*mouseJustPressed || */active && btn.getGlobalBounds().contains(msCord.x, msCord.y)) {
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