#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using std::vector;
using std::string;
using std::u16string;
using std::map;

#include <codecvt>
#include <cassert>
#include <locale>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

using namespace std;

void makeTexture(float Y, float dx, float dy, sf::RenderTexture& renderTexture, sf::Texture texture, vector<float> sizes)
{// Y - смещение по y
 // x, y - на картинке
 // xyCorner - размеры углов
 // yLeftRight - раземеры левой и правой сторон
 // xTopButtom - размеры верха и низа
	int x = sizes[0];
	int y = sizes[1];
	int xyCorner = sizes[2];
	int yLeftRight = sizes[3];
	int xTopButtom = sizes[4];

	sf::Sprite sp;
	sp.setTexture(texture);

	// corners
	sp.setTextureRect({ x, y, xyCorner, xyCorner });
	sp.setPosition({0, Y});
	renderTexture.draw(sp);

	sp.setTextureRect({ x + xyCorner + xTopButtom, y,
		xyCorner, xyCorner });
	sp.setPosition({ dx - xyCorner, Y });
	renderTexture.draw(sp);

	sp.setTextureRect({ x + xyCorner + xTopButtom,
		y + xyCorner + yLeftRight,
		xyCorner, xyCorner });
	sp.setPosition({ dx - xyCorner, Y + dy - xyCorner });
	renderTexture.draw(sp);

	sp.setTextureRect({ x, y + xyCorner + yLeftRight,
		xyCorner, xyCorner });
	sp.setPosition({ 0, Y + dy - xyCorner });
	renderTexture.draw(sp);

	//left-right
	sp.setScale(1, (dy - 2 * xyCorner) / float(yLeftRight));

	sp.setTextureRect({ x, y + xyCorner,
		xyCorner, yLeftRight });
	sp.setPosition({ 0, Y + xyCorner });
	renderTexture.draw(sp);

	sp.setTextureRect({ x + xyCorner + xTopButtom, y + xyCorner,
		xyCorner, yLeftRight });
	sp.setPosition({ float(dx - xyCorner), Y + xyCorner });
	renderTexture.draw(sp);

	//top-buttom
	sp.setScale((dx - 2 * xyCorner) / float(xTopButtom), 1);

	sp.setTextureRect({ x + xyCorner, y,
		xTopButtom, xyCorner });
	sp.setPosition({ float(xyCorner), Y });
	renderTexture.draw(sp);

	sp.setTextureRect({ x + xyCorner, y + xyCorner + yLeftRight,
		xTopButtom, xyCorner });
	sp.setPosition({ float(xyCorner), Y + dy - xyCorner});
	renderTexture.draw(sp);

	//center
	sp.setScale((dx - 2 * xyCorner) / float(xTopButtom),
		        (dy - 2 * xyCorner) / float(yLeftRight));
	sp.setTextureRect({ x + xyCorner, y + xyCorner,
		xTopButtom, yLeftRight });
	sp.setPosition({float(xyCorner), Y + float(xyCorner)});
	renderTexture.draw(sp);

	renderTexture.display();
}

string pad(std::string s, int len = 26)
{
	if (s.length() < len)
		s.insert(s.begin(), len - s.length(), ' ');
	return s;
}

string from16to8string(u16string inp) {
	string result;
	setlocale(LC_ALL, "RUS");
	map<char16_t, char> f16to8rus;
	//1040 1072
	for (int i = 0; i < 64; i++)
		f16to8rus.emplace((char16_t)(1040 + i), (char)(-64 + i));

	for (auto it : inp) {
		auto f = f16to8rus.find(it);
		if (f != f16to8rus.end()) {
			result += f->second;
		}
		else {;
			result += (char)it;
		}
	}
	return result;
}
