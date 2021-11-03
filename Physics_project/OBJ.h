#ifndef _OBJ_H_
#define _OBJ_H_


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

	static void Init(string TexPath = "Icons.png");
	OBJ(sf::RenderWindow& window);

	virtual void setPosition(float x, float y) = 0;
	virtual void setScale(float d) = 0;
	virtual void setSprite1() = 0;
	virtual void setSprite2() = 0;

	virtual void checkActive(const sf::Vector2i& msCord) = 0;
	virtual void checkFocus(const sf::Vector2i& msCord) = 0;
	virtual bool Event(const sf::Vector2i& msCord) = 0;

	virtual void show() = 0;

	sf::RenderWindow& window; // ����, ������� ������������� ������ ��� �������� �������
	sf::Texture texture; // �������� �������
	static sf::RenderTexture renderTex; // ��������������� ��������
	static sf::Texture defTexture; // �������� �� ���������
};

#endif
