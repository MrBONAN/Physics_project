#include "Scene.h"
bool Scene::teacherMode  = true;
bool Scene::menuIsActive = true;

string pad(std::string s, int len = 26)
{
	if (s.length() < len)
		s.insert(s.begin(), len - s.length(), ' ');
	return s;
}

Scene::Scene(sf::RenderWindow& window):
	window(window),
	exerciseRect(window, { INFOsize, 512, 190 })
{}

void Scene::checkAllInteraction(const sf::Event& event)
{
	//������ ������ ��� ������
	if (event.type == sf::Event::MouseButtonPressed) {
		checkAllActive(sf::Mouse::getPosition(window));
		checkAllFocus(sf::Mouse::getPosition(window), true);
	}
	//����� ������ � ������ ������
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		checkAllFocus(sf::Mouse::getPosition(window));
	}
	//������ ���� ��������
	if (event.type == sf::Event::MouseButtonReleased) {
		checkAllEvents(sf::Mouse::getPosition(window));
	}
	// ������� ����� ������
	setAllText(event);
}
