#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "OBJ.h"
class Button : public OBJ
{
public:
	Button(sf::RenderWindow& window, vector<int> sizes);
	Button(sf::RenderWindow& window);

	void setPosition(float x, float y) override { btn.setPosition(sf::Vector2f(x, y));}
	void setScale(float d) override { btn.setScale(d, d); }
	void setSprite1() override {btn.setTextureRect(sf::IntRect(0, 0, dx, dy));}
	void setSprite2() override {btn.setTextureRect(sf::IntRect(0, dy, dx, dy));}

	void checkFocus(const sf::Vector2i& msCord) override;
	bool Event(const sf::Vector2i& msCord) override;


	void show() { window.draw(btn); }
private:
	// ���������� �������
	bool active = false;
	bool isAlreadyUpdate = false; // ����� ��������� �� ������ ������

	// ���������� �������� �� �������� �����������
	int x1 = 0, x2 = 0;
	int y1 = 0, y2 = 0;
	int dx = 70, dy = 15;



	//
	sf::Sprite btn;
};
#endif
