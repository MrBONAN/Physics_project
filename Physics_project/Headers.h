#ifndef _HEADERS_H_
#define _HEADERS_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

#include "OBJ.h"
#include "Button.h"
#include "Test.h"
//#include "writeAns.h"
#include "Interface.h"

#include "AddScene.h"

using namespace std;

using std::cout;
using std::cin;
using std::endl;

void makeTexture(float Y, float dx, float dy, sf::RenderTexture& renderTexture, sf::Texture texture, vector<float> sizes);
//void printOnRenderTexture(int y, sf::RenderTexture& renderTexture,
//	sf::Sprite& corner, sf::Sprite& centerLeftRight,
//	sf::Sprite& centerTopBottom, sf::Sprite& center,
//	vector<int>& sizes);

#endif
