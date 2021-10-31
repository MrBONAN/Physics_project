#include "Button.h"
Button::Button(sf::RenderWindow& window, vector<int> sizes) : OBJ(window)
{
	/*renderTex.clear(sf::Color(255, 0, 0, 255));
	makeTexture(15, 15, x1, y1, renderTex, defTexture, {4, 11, 11});
	renderTex.display();
	texture = renderTex.getTexture();
	btn.setTexture(texture);
	btn.setTextureRect(sf::IntRect(255, 0, 0, 255));*/
	x1 = sizes[0], x2 = sizes[2];
	y1 = sizes[1], y2 = sizes[3];
	dx = sizes[4], dy = sizes[5];
	makeTexture(0, 15, 15, renderTex, defTexture, { 17, 1, 4, 11, 11 });
	texture = renderTex.getTexture();
	btn.setTexture(texture);
	btn.setTextureRect(sf::IntRect(x1, y1, dx, dy));
	btn.setScale(3, 3);
}

Button::Button(sf::RenderWindow& window) : OBJ(window)
{
	/*renderTex.clear(sf::Color(255, 0, 0, 255));
	makeTexture(15, 15, x1, y1, renderTex, defTexture, {4, 11, 11});
	renderTex.display();
	texture = renderTex.getTexture();
	btn.setTexture(texture);
	btn.setTextureRect(sf::IntRect(255, 0, 0, 255));*/
	x1 = 1, x2 = 1;
	y1 = 62, y2 = 93;
	dx = 140, dy = 30;
	//texture = defTexture;
	makeTexture(0, 200, 100, renderTex, defTexture, { 17, 1, 4, 7, 7 });
	texture = renderTex.getTexture();
	btn.setTexture(texture);
	btn.setTextureRect(sf::IntRect(0, 0, 150, 150));
	btn.setScale(1, 1);
}
