#include "Button.h"
Button::Button(sf::RenderWindow& window, vector<float> sizes) : OBJ(window),
ind(window, { 129, 65, sizes[2], sizes[3], sizes[4]+5, sizes[5]+5, 
	sizes[6], sizes[7], sizes[8], })
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

	setIndentText(sizes[6] / 2);
	setTextSettings();
}

Button::Button(sf::RenderWindow& window) : Button(window,
	{49, 1, 17, 1, 250, 50, 5, 5, 5}) // настройка кнопки по умолчанию
{
}

void Button::setPosition(float x, float y) {
	btn.setPosition(sf::Vector2f(x, y));
	ind.setPosition(x-5, y-5);
	text.setPosition(btn.getPosition() +
	sf::Vector2f(indent, indent / 1.3));
}

void Button::addChar(char c, int id)
{
	posCur++;
	auto it = str.begin();
	advance(it, id);
	str.insert(it, c);
	updateText();
}

void Button::deleteChar(int id)
{
	if (id < 1) return;
	str.erase(id - 1, 1);
	updateText();
	curLeft();
}

void Button::setIndentText(int ind)
{
	indent = ind * btn.getScale().x;
}

void Button::checkActive(const sf::Vector2i& msCord)
{
	if (btn.getGlobalBounds().contains(msCord.x, msCord.y))
		active = true;
}

void Button::checkFocus(const sf::Vector2i& msCord)
{
	if (active && btn.getGlobalBounds().contains(msCord.x, msCord.y)) {
		if (isAlreadyUpdate) return;
		isAlreadyUpdate = true;
		active = true;
		setSprite2();
	}
	else if (active)
	{
		if (isAlreadyUpdate) {
			isAlreadyUpdate = false;
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

void Button::show()
{
	ind.show();
	window.draw(btn);
	window.draw(text);
}

void Button::setTextSettings()
{
	font.loadFromFile("pragmatica.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
	text.setPosition(btn.getPosition() +
		sf::Vector2f(indent, indent));
	text.setString(str);
}
