#include "Scene.h"

Scene::Scene(sf::RenderWindow& window):
	window(window),
	exerciseRect(window, { 17, 49, 17, 17, 512, 190, 5, 5, 5 })
{
	numKey.emplace(0, 21);	// A Ô
	numKey.emplace(1, 9);	// B È
	numKey.emplace(2, 18);	// C Ñ
	numKey.emplace(3,  2);	// D Â
	numKey.emplace(4, 20);	// E Ó
	numKey.emplace(5, 0);	// F À
	numKey.emplace(6, 16);	// G Ï
	numKey.emplace(7, 18);	// H Ð
	numKey.emplace(8, 25);	// I Ø
	numKey.emplace(9, 15);	// J Î
	numKey.emplace(10, 12);	// K Ë
	numKey.emplace(11, 4);	// L Ä
	numKey.emplace(12, 29);	// M Ü
	numKey.emplace(13, 19);	// N Ò
	numKey.emplace(14, 26);	// O Ù
	numKey.emplace(15, 8);	// P Ç
	numKey.emplace(16, 10);	// Q É
	numKey.emplace(17, 11);	// R Ê
	numKey.emplace(18, 28);	// S Û
	numKey.emplace(19, 5);	// T Å
	numKey.emplace(20, 3);	// U Ã
	numKey.emplace(21, 13);	// V Ì
	numKey.emplace(22, 23);	// W Ö
	numKey.emplace(23, 24);	// X ×
	numKey.emplace(24, 14);	// Y Í
	numKey.emplace(25, 32);	// Z ß
	numKey.emplace(46, 22);	// [ Õ
	numKey.emplace(47, 27);	// ] Ú
	numKey.emplace(48, 7);	// ; Æ
	numKey.emplace(51, 30);	// ' Ý
	numKey.emplace(49, 1);	// , Á
	numKey.emplace(50, 32);	// . Þ
	
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
