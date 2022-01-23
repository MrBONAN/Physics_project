#include "Scene.h"
bool Scene::teacherMode  = true;
bool Scene::menuIsActive = true;

string pad(std::string s, int len = 26)
{
	if (s.length() < len)
		s.insert(s.begin(), len - s.length(), ' ');
	return s;
}

Scene::Scene(sf::RenderWindow& window):
	window(window),
	exerciseRect(window, { INFOsize, 512, 190 })
{
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

void Scene::setText(Button& btn, const sf::Event& event)
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
		//if (key == 25) cout << comand << endl;
		switch (comand)
		{
		case -1:
			btn.deleteChar(btn.getCurPos());
			break;
		case -2:
			btn.curLeft();
			break;
		case -3:
			btn.curRight();
			break;
		default:
			btn.addChar(comand, btn.getCurPos());
			break;
		}
	}
		
}

void Scene::checkAllInteraction(const sf::Event& event)
{
	//кнопка только что нажата
	if (event.type == sf::Event::MouseButtonPressed) {
		checkAllActive(sf::Mouse::getPosition(window));
		checkAllFocus(sf::Mouse::getPosition(window), true);
	}
	//кнока нажата в данный момент
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		checkAllFocus(sf::Mouse::getPosition(window));
	}
	//кнопка была отпущена
	if (event.type == sf::Event::MouseButtonReleased) {
		checkAllEvents(sf::Mouse::getPosition(window));
	}
	// включен режим учител
	setAllText(event);
}

int Scene::selSymbol(int key, const map<int, int>& langKey,
	const map<int, int>& langSymbKey)
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