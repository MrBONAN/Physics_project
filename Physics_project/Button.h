#pragma once
#include "OBJ.h"
#include "Indicator.h"
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
//#include "Headers.h"

//#define BUTTONsize 49, 1, 65, 1, 5, 5, 5
//#define INFOsize   145, 1, 145, 17, 5, 5, 5
#define BUTTONsize 17, 1, 17, 17, 5, 5, 5
#define INFOsize   1, 1, 1, 17, 5, 5, 5
#define SWITCHsize 65, 1, 97, 1, 0, 31, 31

class Button :
	public OBJ
{
public:

	Button(sf::RenderWindow& window, vector<float> sizes);
	Button(sf::RenderWindow& window);

	void setPosition(float x, float y) override;
	void setScale(float d) override { btn.setScale(d, d); }
	void setScale(float dx, float dy) { btn.setScale(dx, dy); }
	void setSprite1() override {btn.setTextureRect(sf::IntRect(0, 0, dx, dy));}
	void setSprite2() override {btn.setTextureRect(sf::IntRect(0, dy, dx, dy));}


	void setText(const sf::Event& event);
	void setText(const sf::Event& event, int comand);
	int getKey(const sf::Event& event);
	int lastSymbol = 0;

	bool showCursor = false;
	int getCurPos() { return posCur; }
	void curLeft() { posCur = max(0, posCur - 1); updateSupportingChar();  }
	void curRight() { posCur = min(getStrSize(), posCur + 1); updateSupportingChar();
	}

	void addChar(char c, int id);
	void deleteChar(int id);
	void setStr(string str);
	string getStr() { return str; }
	int  getStrSize() { return str.size(); }
	void setIndentText(int ind);

	Indicator ind;	// ��������� ������

	void checkActive(const sf::Vector2i& msCord) override;
	void checkFocus(const sf::Vector2i& msCord) override;
	bool Event(const sf::Vector2i& msCord) override;

	void show() override;
private:
	// ����� � ��� ���������
	void updateText() { text.setString(str); }
	void updateSupportingChar();
	void setTextSettings(sf::Text& text);

	// ���� ������
	//static void initInput();

	int posCur = 0;
	sf::Text supportingChar;
	
	string str = "";// �������� ������
	sf::Font font;	// �������� ������
	sf::Text text;	// ������ ���� Text
	sf::Color color = sf::Color::Black;

	int indent = 0;	// ������� ������� �� �����

	// ���������� ������� �������
	bool active = false;
	bool isAlreadyUpdate = false; // ����� ��������� �� ������ ������

	// ���������� �������� �� �������� �����������
	float x1 = 0, x2 = 0;
	float y1 = 0, y2 = 0;
	int dx = 0, dy = 0;

	sf::Sprite btn;

	static int selSymbol(int key, const map<int, int>& langKey,
		const map<int, int>& langSymbKey);
};
