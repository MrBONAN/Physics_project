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
	//enNumKey.emplace(0, 'a');	// A Ô
	//enNumKey.emplace(1, 'b');		// B È
	//enNumKey.emplace(2, 'c');	// C Ñ
	//enNumKey.emplace(3, 'd');	// D Â
	//enNumKey.emplace(4, 'e');	// E Ó
	//enNumKey.emplace(5, 'f');		// F À
	//enNumKey.emplace(6, 'g');	// G Ï
	//enNumKey.emplace(7, 'h');	// H Ð
	//enNumKey.emplace(8, 'i');	// I Ø
	//enNumKey.emplace(9, 'j');	// J Î
	//enNumKey.emplace(10, 'k');	// K Ë
	//enNumKey.emplace(11, 'l');	// L Ä
	//enNumKey.emplace(12, 'm');	// M Ü
	//enNumKey.emplace(13, 'n');	// N Ò
	//enNumKey.emplace(14, 'o');	// O Ù
	//enNumKey.emplace(15, 'p');	// P Ç
	//enNumKey.emplace(16, 'q');	// Q É
	//enNumKey.emplace(17, 'r');	// R Ê
	//enNumKey.emplace(18, 's');	// S Û
	//enNumKey.emplace(19, 't');	// T Å
	//enNumKey.emplace(20, 'u');	// U Ã
	//enNumKey.emplace(21, 'v');	// V Ì
	//enNumKey.emplace(22, 'w');	// W Ö
	//enNumKey.emplace(23, 'x');	// X ×
	//enNumKey.emplace(24, 'y');	// Y Í
	//enNumKey.emplace(25, 'z');	// Z ß

	ruKey.emplace(0, 'ô');
	ruKey.emplace(1, 'è');
	ruKey.emplace(2, 'ñ');
	ruKey.emplace(3, 'â');
	ruKey.emplace(4, 'ó');
	ruKey.emplace(5, 'à');
	ruKey.emplace(6, 'ï');
	ruKey.emplace(7, 'ð');
	ruKey.emplace(8, 'ø');
	ruKey.emplace(9, 'î');
	ruKey.emplace(10, 'ë');
	ruKey.emplace(11, 'ä');
	ruKey.emplace(12, 'ü');
	ruKey.emplace(13, 'ò');
	ruKey.emplace(14, 'ù');
	ruKey.emplace(15, 'ç');
	ruKey.emplace(16, 'é');
	ruKey.emplace(17, 'ê');
	ruKey.emplace(18, 'û');
	ruKey.emplace(19, 'å');
	ruKey.emplace(20, 'ã');
	ruKey.emplace(21, 'ì');
	ruKey.emplace(22, 'ö');
	ruKey.emplace(23, '÷');
	ruKey.emplace(24, 'í');
	ruKey.emplace(25, 'ÿ');
	ruKey.emplace(46, 'õ');
	ruKey.emplace(47, 'ú');
	ruKey.emplace(48, 'æ');
	ruKey.emplace(51, 'ý');
	ruKey.emplace(49, 'á');
	ruKey.emplace(50, 'þ');

	for (int i = 0; i < 10; i++)
	{
		ruSymbKey.emplace(26 + i, char('0' + i));
	}
	ruSymbKey.emplace(126, ')');
	ruSymbKey.emplace(127, '!');
	ruSymbKey.emplace(128, '"');
	ruSymbKey.emplace(129, '¹');
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