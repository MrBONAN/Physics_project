#include "Scene.h"

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

	enSymbKey.emplace(58, '\n');
	enSymbKey.emplace(60, '\t');
	//enNumKey.emplace(0, 'a');	// A �
	//enNumKey.emplace(1, 'b');		// B �
	//enNumKey.emplace(2, 'c');	// C �
	//enNumKey.emplace(3, 'd');	// D �
	//enNumKey.emplace(4, 'e');	// E �
	//enNumKey.emplace(5, 'f');		// F �
	//enNumKey.emplace(6, 'g');	// G �
	//enNumKey.emplace(7, 'h');	// H �
	//enNumKey.emplace(8, 'i');	// I �
	//enNumKey.emplace(9, 'j');	// J �
	//enNumKey.emplace(10, 'k');	// K �
	//enNumKey.emplace(11, 'l');	// L �
	//enNumKey.emplace(12, 'm');	// M �
	//enNumKey.emplace(13, 'n');	// N �
	//enNumKey.emplace(14, 'o');	// O �
	//enNumKey.emplace(15, 'p');	// P �
	//enNumKey.emplace(16, 'q');	// Q �
	//enNumKey.emplace(17, 'r');	// R �
	//enNumKey.emplace(18, 's');	// S �
	//enNumKey.emplace(19, 't');	// T �
	//enNumKey.emplace(20, 'u');	// U �
	//enNumKey.emplace(21, 'v');	// V �
	//enNumKey.emplace(22, 'w');	// W �
	//enNumKey.emplace(23, 'x');	// X �
	//enNumKey.emplace(24, 'y');	// Y �
	//enNumKey.emplace(25, 'z');	// Z �

	ruKey.emplace(0, '�');
	ruKey.emplace(1, '�');
	ruKey.emplace(2, '�');
	ruKey.emplace(3, '�');
	ruKey.emplace(4, '�');
	ruKey.emplace(5, '�');
	ruKey.emplace(6, '�');
	ruKey.emplace(7, '�');
	ruKey.emplace(8, '�');
	ruKey.emplace(9, '�');
	ruKey.emplace(10, '�');
	ruKey.emplace(11, '�');
	ruKey.emplace(12, '�');
	ruKey.emplace(13, '�');
	ruKey.emplace(14, '�');
	ruKey.emplace(15, '�');
	ruKey.emplace(16, '�');
	ruKey.emplace(17, '�');
	ruKey.emplace(18, '�');
	ruKey.emplace(19, '�');
	ruKey.emplace(20, '�');
	ruKey.emplace(21, '�');
	ruKey.emplace(22, '�');
	ruKey.emplace(23, '�');
	ruKey.emplace(24, '�');
	ruKey.emplace(25, '�');
	ruKey.emplace(46, '�');
	ruKey.emplace(47, '�');
	ruKey.emplace(48, '�');
	ruKey.emplace(51, '�');
	ruKey.emplace(49, '�');
	ruKey.emplace(50, '�');

	for (int i = 0; i < 10; i++)
	{
		ruSymbKey.emplace(26 + i, char('0' + i));
	}
	ruSymbKey.emplace(126, ')');
	ruSymbKey.emplace(127, '!');
	ruSymbKey.emplace(128, '"');
	ruSymbKey.emplace(129, '�');
	ruSymbKey.emplace(130, ';');
	ruSymbKey.emplace(131, '%');
	ruSymbKey.emplace(132, ':');
	ruSymbKey.emplace(133, '?');
	ruSymbKey.emplace(134, '*');
	ruSymbKey.emplace(135, '(');


	ruSymbKey.emplace(56, '-');
	ruSymbKey.emplace(55, '=');
	ruSymbKey.emplace(152,'.');

	ruSymbKey.emplace(156, '_');
	ruSymbKey.emplace(155, '+');
	ruSymbKey.emplace(152,',');

	ruSymbKey.emplace(58, '\n');
	ruSymbKey.emplace(60, '\t');
	
}
void Scene::setText(Button& btn, const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed) {
		cout << event.key.code << endl;
		int code = int(GetKeyboardLayout(GetWindowThreadProcessId(GetForegroundWindow(), NULL)));
		if (code == enCode)
		{
			int key = event.key.code;

		}
	}
}