#include "Scene.h"

Scene::Scene(sf::RenderWindow& window):
	window(window),
	exerciseRect(window, { 17, 49, 17, 17, 512, 190, 5, 5, 5 })
{
	numKey.emplace(0, 21);	// A �
	numKey.emplace(1, 9);	// B �
	numKey.emplace(2, 18);	// C �
	numKey.emplace(3,  2);	// D �
	numKey.emplace(4, 20);	// E �
	numKey.emplace(5, 0);	// F �
	numKey.emplace(6, 16);	// G �
	numKey.emplace(7, 18);	// H �
	numKey.emplace(8, 25);	// I �
	numKey.emplace(9, 15);	// J �
	numKey.emplace(10, 12);	// K �
	numKey.emplace(11, 4);	// L �
	numKey.emplace(12, 29);	// M �
	numKey.emplace(13, 19);	// N �
	numKey.emplace(14, 26);	// O �
	numKey.emplace(15, 8);	// P �
	numKey.emplace(16, 10);	// Q �
	numKey.emplace(17, 11);	// R �
	numKey.emplace(18, 28);	// S �
	numKey.emplace(19, 5);	// T �
	numKey.emplace(20, 3);	// U �
	numKey.emplace(21, 13);	// V �
	numKey.emplace(22, 23);	// W �
	numKey.emplace(23, 24);	// X �
	numKey.emplace(24, 14);	// Y �
	numKey.emplace(25, 32);	// Z �
	numKey.emplace(46, 22);	// [ �
	numKey.emplace(47, 27);	// ] �
	numKey.emplace(48, 7);	// ; �
	numKey.emplace(51, 30);	// ' �
	numKey.emplace(49, 1);	// , �
	numKey.emplace(50, 32);	// . �
	
	numKey.emplace(52, 33);	// / .
	numKey.emplace(58, 34);	// enter
	numKey.emplace(38, 35);	// shift
	numKey.emplace(35, 36);	//  
}

void Scene::setText(Button& btn, const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
			cout << event.key.code << endl;
	}
