#include "Headers.h"
//
//void makeTexture(int dx, int dy, int x, int y, sf::RenderTexture& renderTexture, sf::Texture& defTexture, vector<int> sizes)
//{ // в size: corner, yCenterLeftRight, xCenterTopBottom
//	sf::Sprite corner, centerLeftRight, centerTopBottom, center;
//	corner.setTexture(defTexture);
//	centerLeftRight.setTexture(defTexture);
//	centerTopBottom.setTexture(defTexture);
//	center.setTexture(defTexture);
//
//	int xyCorner = sizes[0];
//	int yCenterLeftRight = sizes[1];
//	int xCenterTopButtom = sizes[2];
//
//	// задаём их координаты на исходной текстуре
//	corner.setTextureRect(sf::IntRect(x, y, x + xyCorner, y + xyCorner));
//	centerLeftRight.setTextureRect(sf::IntRect(x, y + xyCorner, x + xyCorner, y + xyCorner + yCenterLeftRight));
//	centerTopBottom.setTextureRect(sf::IntRect(x + xyCorner, y, x + xyCorner + xCenterTopButtom, y + xyCorner));
//	center.setTextureRect(sf::IntRect(x + xyCorner, y + xyCorner, x + xyCorner + xCenterTopButtom, y + xyCorner + yCenterLeftRight));
//
//	// подгоняем размеры частей
//	centerLeftRight.setScale(sf::Vector2f(1, (dy - 2 * xyCorner) / yCenterLeftRight));
//	centerTopBottom.setScale(sf::Vector2f((dx - 2 * xyCorner) / xCenterTopButtom, 1));
//	center.setScale(sf::Vector2f((dx - xyCorner) / xCenterTopButtom,
//								(dy - 2 * xyCorner) / yCenterLeftRight));
//	renderTexture.clear();
//	printOnRenderTexture(0, renderTexture, corner, centerLeftRight, centerTopBottom, center, sizes);
//	renderTexture.display();
//}
//
//void printOnRenderTexture(int y, sf::RenderTexture& renderTexture,
//	sf::Sprite& corner, sf::Sprite& centerLeftRight,
//	sf::Sprite& centerTopBottom, sf::Sprite& center,
//	vector<int>& sizes)
//{
//	int xyCorner = sizes[0];
//	int yCenterLeftRight = sizes[1];
//	int xCenterTopButtom = sizes[2];
//
//	corner.setPosition(sf::Vector2f(0, y));
//	renderTexture.draw(corner);
//	corner.rotate(90);
//
//	corner.setPosition(sf::Vector2f(xyCorner * 2 + xCenterTopButtom, y));
//	renderTexture.draw(corner);
//	corner.rotate(90);
//
//	corner.setPosition(sf::Vector2f(xyCorner * 2 + xCenterTopButtom, xyCorner * 2 + yCenterLeftRight + y));
//	renderTexture.draw(corner);
//	corner.rotate(90);
//
//	corner.setPosition(sf::Vector2f(0, xyCorner * 2 + yCenterLeftRight + y));
//	renderTexture.draw(corner);
//	corner.rotate(90);
//
//
//	center.setPosition(sf::Vector2f(xyCorner, y + xyCorner));
//	renderTexture.draw(center);
//
//
//	centerLeftRight.setPosition(sf::Vector2f(0, xyCorner + y));
//	renderTexture.draw(centerLeftRight);
//	centerLeftRight.rotate(180);
//
//	centerLeftRight.setPosition(sf::Vector2f(xyCorner * 2 + xCenterTopButtom, xyCorner + yCenterLeftRight + y));
//	renderTexture.draw(centerLeftRight);
//	centerLeftRight.rotate(180);
//
//	centerTopBottom.setPosition(sf::Vector2f(xyCorner, y));
//	renderTexture.draw(centerTopBottom);
//	centerTopBottom.rotate(180);
//
//	centerTopBottom.setPosition(sf::Vector2f(xyCorner + xCenterTopButtom, y + xyCorner * 2 + yCenterLeftRight));
//	renderTexture.draw(centerTopBottom);
//	centerTopBottom.rotate(180);
//}

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
	renderTexture.clear(sf::Color(0,0,0,0));

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
