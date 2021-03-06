#include "OBJ.h"

void OBJ::Init(string TexPath)
{
	defTexture.loadFromFile(TexPath);

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

	ruKey.emplace(0, '?' + 256);
	ruKey.emplace(1, '?' + 256);
	ruKey.emplace(2, '?' + 256);
	ruKey.emplace(3, '?' + 256);
	ruKey.emplace(4, '?' + 256);
	ruKey.emplace(5, '?' + 256);
	ruKey.emplace(6, '?' + 256);
	ruKey.emplace(7, '?' + 256);
	ruKey.emplace(8, '?' + 256);
	ruKey.emplace(9, '?' + 256);
	ruKey.emplace(10, '?' + 256);
	ruKey.emplace(11, '?' + 256);
	ruKey.emplace(12, '?' + 256);
	ruKey.emplace(13, '?' + 256);
	ruKey.emplace(14, '?' + 256);
	ruKey.emplace(15, '?' + 256);
	ruKey.emplace(16, '?' + 256);
	ruKey.emplace(17, '?' + 256);
	ruKey.emplace(18, '?' + 256);
	ruKey.emplace(19, '?' + 256);
	ruKey.emplace(20, '?' + 256);
	ruKey.emplace(21, '?' + 256);
	ruKey.emplace(22, '?' + 256);
	ruKey.emplace(23, '?' + 256);
	ruKey.emplace(24, '?' + 256);
	ruKey.emplace(25, '?' + 256);
	ruKey.emplace(46, '?' + 256);
	ruKey.emplace(47, '?' + 256);
	ruKey.emplace(48, '?' + 256);
	ruKey.emplace(51, '?' + 256);
	ruKey.emplace(49, '?' + 256);
	ruKey.emplace(50, '?' + 256);

	for (int i = 0; i < 10; i++)
	{
		ruSymbKey.emplace(26 + i, char('0' + i));
	}
	ruSymbKey.emplace(126, ')');
	ruSymbKey.emplace(127, '!');
	ruSymbKey.emplace(128, '"');
	ruSymbKey.emplace(129, '?');
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

OBJ::OBJ(sf::RenderWindow& window) : window(window){ renderTex.create(1000, 1000); }
