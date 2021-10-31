#include "OBJ.h"

sf::RenderTexture OBJ::renderTex;

sf::Texture OBJ::defTexture;

void OBJ::Init(string TexPath)
{
	defTexture.loadFromFile(TexPath);
	renderTex.create(1000, 1000);
}

OBJ::OBJ(sf::RenderWindow& window) : window(window){ renderTex.create(1000, 1000); }
