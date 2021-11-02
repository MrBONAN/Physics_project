#include "Indicator.h"

Indicator::Indicator(sf::RenderWindow& window, vector<float> sizes) : OBJ(window)
{
	x1 = sizes[0], y1 = sizes[1];
	x2 = sizes[2], y2 = sizes[3];
	dx = sizes[4], dy = sizes[5];
	renderTex.clear(sf::Color(0, 0, 0, 0));
	makeTexture(0, dx, dy, renderTex, defTexture, { x1, y1, sizes[6], sizes[7], sizes[8] });
	makeTexture(dy, dx, dy, renderTex, defTexture, { x2, y2, sizes[6], sizes[7], sizes[8] });
	texture = renderTex.getTexture();
	ind.setTexture(texture);
	off();
	setScale(2);
}

Indicator::Indicator(sf::RenderWindow& window) : OBJ(window)
{
	x1 = 17, y1 = 49;
	x2 = 17, y2 = 17;
	dx = 250, dy = 50;
	renderTex.clear(sf::Color(0, 0, 0, 0));
	makeTexture(0, dx, dy, renderTex, defTexture, { x1, y1, 5, 5, 5 });
	makeTexture(dy, dx, dy, renderTex, defTexture, { x2, y2, 4, 7, 7 });
	texture = renderTex.getTexture();
	ind.setTexture(texture);
	off();
	setScale(2);
}