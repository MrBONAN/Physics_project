#include "Scene.h"
bool Scene::teacherMode  = true;
bool Scene::menuIsActive = true;


Scene::Scene(sf::RenderWindow& window):
	window(window),
	exerciseRect(window, { INFOsize, 512, 190 })
{}

void Scene::checkAllInteraction(const sf::Event& event)
{
	//кнопка только что нажата
	if (event.type == sf::Event::MouseButtonPressed) {
		checkAllActive(sf::Mouse::getPosition(window));
		checkAllFocus(sf::Mouse::getPosition(window), true);
	}
	//кнока нажата в данный момент
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		checkAllFocus(sf::Mouse::getPosition(window));
	}
	//кнопка была отпущена
	if (event.type == sf::Event::MouseButtonReleased) {
		checkAllEvents(sf::Mouse::getPosition(window));
	}
	// включен режим учител
	setAllText(event);
}
