#include "Button.h"
sf::RenderTexture Button::renderTex;
sf::Texture Button::defTexture;

int Button::enCode = 67699721;
int Button::ruCode = 68748313;

map<int, int> Button::enKey;
map<int, int> Button::ruKey;
map<int, int> Button::enSymbKey;
map<int, int> Button::ruSymbKey;
map<int, int> Button::specChar;

Button::Button(sf::RenderWindow& window, vector<float> sizes) : window(window),
ind(window, { 129, 65, sizes[2], sizes[3], sizes[7]+5, sizes[8]+5, 
	sizes[4], sizes[5], sizes[6], })
{
	renderTex.create(1000, 1000);

	x1 = sizes[0], y1 = sizes[1];
	x2 = sizes[2], y2 = sizes[3];
	dx = sizes[7], dy = sizes[8];
	renderTex.clear(sf::Color(0, 0, 0, 0));
	makeTexture(0, dx, dy, renderTex, defTexture, { x1, y1, sizes[4], sizes[5], sizes[6] });
	makeTexture(dy, dx, dy, renderTex, defTexture, { x2, y2, sizes[4], sizes[5], sizes[6] });
	texture = renderTex.getTexture();
	btn.setTexture(texture);
	setSprite1();
	setScale(2);

	setIndentText(sizes[4] / 2);
	setTextSettings(text);
	setTextSettings(supportingChar);
	supportingChar.setString("|");
}

Button::Button(sf::RenderWindow& window) : Button(window,
	{BUTTONsize, 250, 50}) // настройка кнопки по умолчанию
{
}

void Button::setPosition(float x, float y) {
	btn.setPosition(sf::Vector2f(x, y));
	ind.setPosition(x-5, y-5);
	text.setPosition(btn.getPosition() +
	sf::Vector2f(indent, indent / 1.3));

	sf::Vector2f temp = text.getPosition();
	supportingChar.setPosition({temp.x - 5, temp.y});
}

void Button::setText(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed) {
		//cout << event.key.code << endl;
		int code = int(GetKeyboardLayout(GetWindowThreadProcessId(GetForegroundWindow(), NULL)));
		int key = event.key.code;
		int comand;
		if (code == enCode)
		{
			comand = selSymbol(key, enKey, enSymbKey);
		}
		else {
			comand = selSymbol(key, ruKey, ruSymbKey);
		}
		if (comand == char(0)) return;
		
		switch (comand)
		{
		case -1:
			deleteChar(getCurPos());
			break;
		case -2:
			curLeft();
			break;
		case -3:
			curRight();
			break;
		default:
			addChar(comand, getCurPos());
			break;
		}
	}
}

void Button::addChar(char c, int id)
{
	posCur++;
	auto it = str.begin();
	advance(it, id);
	str.insert(it, c);
	updateText();
	updateSupportingChar();
}

void Button::deleteChar(int id)
{
	if (id < 1) return;
	str.erase(id - 1, 1);
	updateText();
	curLeft();
}

void Button::setStr(string str)
{
	this->str = str;
	updateText();
	posCur = str.size();
	updateSupportingChar();
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
		//active = true;
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
	active = false;
	return false;
}

void Button::show()
{
	ind.show();
	window.draw(btn);
	if (ind.getActive() && showCursor) {
		SYSTEMTIME st;
		GetLocalTime(&st);
		if (st.wMilliseconds > 500)
			window.draw(supportingChar);
	}
	window.draw(text);
}

void Button::setTextSettings(sf::Text& text)
{
	font.loadFromFile("pragmatica.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(color);
	text.setPosition(btn.getPosition() +
		sf::Vector2f(indent, indent));
	text.setString(str);
}

void Button::updateSupportingChar()
{
	sf::Vector2f temp = text.findCharacterPos(posCur);
	supportingChar.setPosition({temp.x - 5,  temp.y});
}

void Button::init(string TexturePath)
{
	defTexture.loadFromFile(TexturePath);

	for (int i = 0; i < 26; i++)
	{
		enKey.emplace(i, char('a' + i));
	}
	for (int i = 0; i < 10; i++)
	{
		enSymbKey.emplace(26 + i, char('0' + i));
	}
	enSymbKey.emplace(126, ')');
	enSymbKey.emplace(127, '!');
	enSymbKey.emplace(128, '@');
	enSymbKey.emplace(129, '#');
	enSymbKey.emplace(130, '$');
	enSymbKey.emplace(131, '%');
	enSymbKey.emplace(132, '^');
	enSymbKey.emplace(133, '&');
	enSymbKey.emplace(134, '*');
	enSymbKey.emplace(135, '(');


	enSymbKey.emplace(56, '-');
	enSymbKey.emplace(55, '=');
	enSymbKey.emplace(46, '[');
	enSymbKey.emplace(47, ']');
	enSymbKey.emplace(53, '\\');
	enSymbKey.emplace(48, ';');
	enSymbKey.emplace(51, '\'');
	enSymbKey.emplace(49, ',');
	enSymbKey.emplace(50, '.');
	enSymbKey.emplace(52, '/');

	enSymbKey.emplace(156, '_');
	enSymbKey.emplace(155, '+');
	enSymbKey.emplace(146, '{');
	enSymbKey.emplace(147, '}');
	enSymbKey.emplace(153, '|');
	enSymbKey.emplace(148, ':');
	enSymbKey.emplace(151, '"');
	enSymbKey.emplace(149, '<');
	enSymbKey.emplace(150, '>');
	enSymbKey.emplace(152, '?');

	ruKey.emplace(0, 'ф' + 256);
	ruKey.emplace(1, 'и' + 256);
	ruKey.emplace(2, 'с' + 256);
	ruKey.emplace(3, 'в' + 256);
	ruKey.emplace(4, 'у' + 256);
	ruKey.emplace(5, 'а' + 256);
	ruKey.emplace(6, 'п' + 256);
	ruKey.emplace(7, 'р' + 256);
	ruKey.emplace(8, 'ш' + 256);
	ruKey.emplace(9, 'о' + 256);
	ruKey.emplace(10, 'л' + 256);
	ruKey.emplace(11, 'д' + 256);
	ruKey.emplace(12, 'ь' + 256);
	ruKey.emplace(13, 'т' + 256);
	ruKey.emplace(14, 'щ' + 256);
	ruKey.emplace(15, 'з' + 256);
	ruKey.emplace(16, 'й' + 256);
	ruKey.emplace(17, 'к' + 256);
	ruKey.emplace(18, 'ы' + 256);
	ruKey.emplace(19, 'е' + 256);
	ruKey.emplace(20, 'г' + 256);
	ruKey.emplace(21, 'м' + 256);
	ruKey.emplace(22, 'ц' + 256);
	ruKey.emplace(23, 'ч' + 256);
	ruKey.emplace(24, 'н' + 256);
	ruKey.emplace(25, 'я' + 256);
	ruKey.emplace(46, 'х' + 256);
	ruKey.emplace(47, 'ъ' + 256);
	ruKey.emplace(48, 'ж' + 256);
	ruKey.emplace(51, 'э' + 256);
	ruKey.emplace(49, 'б' + 256);
	ruKey.emplace(50, 'ю' + 256);

	for (int i = 0; i < 10; i++)
	{
		ruSymbKey.emplace(26 + i, char('0' + i));
	}
	ruSymbKey.emplace(126, ')');
	ruSymbKey.emplace(127, '!');
	ruSymbKey.emplace(128, '"');
	ruSymbKey.emplace(129, '№');
	ruSymbKey.emplace(130, ';');
	ruSymbKey.emplace(131, '%');
	ruSymbKey.emplace(132, ':');
	ruSymbKey.emplace(133, '?');
	ruSymbKey.emplace(134, '*');
	ruSymbKey.emplace(135, '(');


	ruSymbKey.emplace(56, '-');
	ruSymbKey.emplace(55, '=');
	ruSymbKey.emplace(53, '\\');
	ruSymbKey.emplace(52, '.');

	ruSymbKey.emplace(156, '_');
	ruSymbKey.emplace(155, '+');
	ruSymbKey.emplace(153, '/');
	ruSymbKey.emplace(152, ',');

	specChar.emplace(57, ' ');
	specChar.emplace(58, '\n');
	specChar.emplace(59, -1);
	specChar.emplace(60, '\t');
	specChar.emplace(71, -2);
	specChar.emplace(72, -3);

}

int Button::selSymbol(int key, const map<int, int>& langKey, const map<int, int>& langSymbKey)
{
	if (specChar.find(key) != specChar.end()) {
		return (*specChar.find(key)).second;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
	{ // не нажат shft
		if (langKey.find(key) != langKey.end()) {
			return (*langKey.find(key)).second;
		}
		else if (langSymbKey.find(key) != langSymbKey.end()) {
			return (*langSymbKey.find(key)).second;
		}
	}
	else {
		if (langKey.find(key) != langKey.end()) {
			return char((*langKey.find(key)).second - 32);
		}
		else if (langSymbKey.find(key + 100) != langSymbKey.end()) {
			return (*langSymbKey.find(key + 100)).second;
		}
	}
	return 0;
}
