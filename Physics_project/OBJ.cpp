#include "OBJ.h"

sf::RenderTexture OBJ::renderTex;
sf::Texture OBJ::defTexture;
bool OBJ::mouseJustPressed = true;

void OBJ::Init(string TexPath)
{
	defTexture.loadFromFile(TexPath);
}

OBJ::OBJ(sf::RenderWindow& window) : window(window){ renderTex.create(1000, 1000); }
