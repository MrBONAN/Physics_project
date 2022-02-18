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

	ruKey.emplace(0, 'ô' + 256);
	ruKey.emplace(1, 'è' + 256);
	ruKey.emplace(2, 'ñ' + 256);
	ruKey.emplace(3, 'â' + 256);
	ruKey.emplace(4, 'ó' + 256);
	ruKey.emplace(5, 'à' + 256);
	ruKey.emplace(6, 'ï' + 256);
	ruKey.emplace(7, 'ð' + 256);
	ruKey.emplace(8, 'ø' + 256);
	ruKey.emplace(9, 'î' + 256);
	ruKey.emplace(10, 'ë' + 256);
	ruKey.emplace(11, 'ä' + 256);
	ruKey.emplace(12, 'ü' + 256);
	ruKey.emplace(13, 'ò' + 256);
	ruKey.emplace(14, 'ù' + 256);
	ruKey.emplace(15, 'ç' + 256);
	ruKey.emplace(16, 'é' + 256);
	ruKey.emplace(17, 'ê' + 256);
	ruKey.emplace(18, 'û' + 256);
	ruKey.emplace(19, 'å' + 256);
	ruKey.emplace(20, 'ã' + 256);
	ruKey.emplace(21, 'ì' + 256);
	ruKey.emplace(22, 'ö' + 256);
	ruKey.emplace(23, '÷' + 256);
	ruKey.emplace(24, 'í' + 256);
	ruKey.emplace(25, 'ÿ' + 256);
	ruKey.emplace(46, 'õ' + 256);
	ruKey.emplace(47, 'ú' + 256);
	ruKey.emplace(48, 'æ' + 256);
	ruKey.emplace(51, 'ý' + 256);
	ruKey.emplace(49, 'á' + 256);
	ruKey.emplace(50, 'þ' + 256);

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
