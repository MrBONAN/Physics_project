#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "OBJ.h"
#include "Indicator.h"
class Button : public OBJ
{
public:
	Button(sf::RenderWindow& window, vector<float> sizes);
	Button(sf::RenderWindow& window);

	void setPosition(float x, float y) override;
	void setScale(float d) override { btn.setScale(d, d); }
	void setSprite1() override {btn.setTextureRect(sf::IntRect(0, 0, dx, dy));}
	void setSprite2() override {btn.setTextureRect(sf::IntRect(0, dy, dx, dy));}

	int getCurPos() { return posCur; }
	void curLeft() { posCur = max(0, posCur - 1); }
	void curRight() { posCur = min(getStrSize(), posCur + 1); }

	void addChar(char c, int id);
	void deleteChar(int id);
	int  getStrSize() { return str.size(); }
	void setIndentText(int ind);
	
	Indicator ind;

	void checkActive(const sf::Vector2i& msCord) override;
	void checkFocus(const sf::Vector2i& msCord) override;
	bool Event(const sf::Vector2i& msCord) override;

	void show();
private:
	// текст и его настройки
	void updateText() { text.setString(str); }
	int posCur = 0;
	
	string str;		// хранение строки
	sf::Font font;	// хранение шрифта
	sf::Text text;	// объект типа Text
	int indent = 0;		// размеры отступа по краям

	void setTextSettings();

	// визуальные эффекты нажатия
	bool active = false;
	bool isAlreadyUpdate = false; // чтобы постоянно не менять спрайт

	// координаты текстуры на исходном изображении
	float x1 = 0, x2 = 0;
	float y1 = 0, y2 = 0;
	int dx = 70, dy = 15;

	sf::Sprite btn;
};
#endif
