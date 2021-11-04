#include "Scene.h"
bool Scene::teacherMode = true;

Scene::Scene(sf::RenderWindow& window):
	window(window),
	exerciseRect(window, { 17, 49, 17, 17, 512, 190, 5, 5, 5 })
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

	//enNumKey.emplace(0, 'a');	// A Ф
	//enNumKey.emplace(1, 'b');		// B И
	//enNumKey.emplace(2, 'c');	// C С
	//enNumKey.emplace(3, 'd');	// D В
	//enNumKey.emplace(4, 'e');	// E У
	//enNumKey.emplace(5, 'f');		// F А
	//enNumKey.emplace(6, 'g');	// G П
	//enNumKey.emplace(7, 'h');	// H Р
	//enNumKey.emplace(8, 'i');	// I Ш
	//enNumKey.emplace(9, 'j');	// J О
	//enNumKey.emplace(10, 'k');	// K Л
	//enNumKey.emplace(11, 'l');	// L Д
	//enNumKey.emplace(12, 'm');	// M Ь
	//enNumKey.emplace(13, 'n');	// N Т
	//enNumKey.emplace(14, 'o');	// O Щ
	//enNumKey.emplace(15, 'p');	// P З
	//enNumKey.emplace(16, 'q');	// Q Й
	//enNumKey.emplace(17, 'r');	// R К
	//enNumKey.emplace(18, 's');	// S Ы
	//enNumKey.emplace(19, 't');	// T Е
	//enNumKey.emplace(20, 'u');	// U Г
	//enNumKey.emplace(21, 'v');	// V М
	//enNumKey.emplace(22, 'w');	// W Ц
	//enNumKey.emplace(23, 'x');	// X Ч
	//enNumKey.emplace(24, 'y');	// Y Н
	//enNumKey.emplace(25, 'z');	// Z Я

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
		cout << event.key.code << endl;
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
		if (key == 25) cout << comand << endl;
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