#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "OBJ.h"
#include "Indicator.h"
//#include "Headers.h"

void makeTexture(float Y, float dx, float dy, sf::RenderTexture& renderTexture, sf::Texture texture, vector<float> sizes);

class Button : public OBJ
{
public:
	/*friend class boost::serialization::access;
	template <class Archive> void serialize(Archive& ar, unsigned) {
		ar& itemID& itemCount;
	}*/

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
	void setStr(string str) { this->str = str; updateText(); }
	string getStr() { return str; }
	int  getStrSize() { return str.size(); }
	void setIndentText(int ind);

	Indicator ind;	// индикатор кнопки

	void checkActive(const sf::Vector2i& msCord) override;
	void checkFocus(const sf::Vector2i& msCord) override;
	bool Event(const sf::Vector2i& msCord) override;

	void show();
private:
	// текст и его настройки
	void updateText() { text.setString(str); }
	void setTextSettings();

	int posCur = 0;
	
	string str = "";// хранение строки
	sf::Font font;	// хранение шрифта
	sf::Text text;	// объект типа Text

	int indent = 0;	// размеры отступа по краям

	// визуальные эффекты нажатия
	bool active = false;
	bool isAlreadyUpdate = false; // чтобы постоянно не менять спрайт

	// координаты текстуры на исходном изображении
	float x1 = 0, x2 = 0;
	float y1 = 0, y2 = 0;
	int dx = 0, dy = 0;

	sf::Sprite btn;
};
#endif
