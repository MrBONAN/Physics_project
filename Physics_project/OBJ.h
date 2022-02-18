#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

using std::cout;
using std::cin;
using std::endl;

void makeTexture(float Y, float dx, float dy, sf::RenderTexture& renderTexture, sf::Texture texture, vector<float> sizes);

class OBJ
{
public:

	static void Init(string TexPath);
	OBJ(sf::RenderWindow& window);

	virtual void setPosition(float x, float y) = 0;
	virtual void setScale(float d) = 0;
	virtual void setSprite1() = 0;
	virtual void setSprite2() = 0;

	virtual void checkActive(const sf::Vector2i& msCord) = 0;
	virtual void checkFocus(const sf::Vector2i& msCord) = 0;
	virtual bool Event(const sf::Vector2i& msCord) = 0;

	virtual void show() = 0;
protected:
	sf::RenderWindow& window; // ����, ������� ������������� ������ ��� �������� �������
	sf::Texture texture; // �������� �������
	static sf::RenderTexture renderTex; // ��������������� ��������
	static sf::Texture defTexture; // �������� �� ���������

	static int enCode;
	static int ruCode;
	static map<int, int> enKey;
	static map<int, int> ruKey;
	static map<int, int> enSymbKey;
	static map<int, int> ruSymbKey;
	static map<int, int> specChar;
	
};

