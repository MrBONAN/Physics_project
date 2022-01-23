#pragma once
#include "OBJ.h"
#include "Indicator.h"
//#include "Headers.h"

#define BUTTONsize 49, 1, 65, 1, 5, 5, 5
#define INFOsize   145, 1, 145, 17, 5, 5, 5

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

	Indicator ind;	// ��������� ������

	void checkActive(const sf::Vector2i& msCord) override;
	void checkFocus(const sf::Vector2i& msCord) override;
	bool Event(const sf::Vector2i& msCord) override;

	void show();
private:
	// ����� � ��� ���������
	void updateText() { text.setString(str); }
	void setTextSettings();

	int posCur = 0;
	
	string str = "";// �������� ������
	sf::Font font;	// �������� ������
	sf::Text text;	// ������ ���� Text

	int indent = 0;	// ������� ������� �� �����

	// ���������� ������� �������
	bool active = false;
	bool isAlreadyUpdate = false; // ����� ��������� �� ������ ������

	// ���������� �������� �� �������� �����������
	float x1 = 0, x2 = 0;
	float y1 = 0, y2 = 0;
	int dx = 0, dy = 0;

	sf::Sprite btn;
};
