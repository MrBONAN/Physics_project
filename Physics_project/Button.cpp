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
	x1 = 17, y1 = 49;
	x2 = 1, y2 = 93;
	dx = 250, dy = 50;
	makeTexture(0, dx, dy, renderTex, defTexture, { float(x1), float(y1), 5, 5, 5 });
	texture = renderTex.getTexture();
	btn.setTexture(texture);
	btn.setTextureRect(sf::IntRect(0, 0, dx, dy));
	setScale(2);
}
