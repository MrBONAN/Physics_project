#include "Interface.h"

Interface::Interface(sf::RenderWindow& window) : Scene(window),
left(window, { 81, 33, 113,33, 31, 31, 0, 31, 31 }),
right(window, { 81, 1, 113, 1, 31, 31, 0, 31, 31 })
{
	left.setPosition(10, 630);
	right.setPosition(973, 630);
}

void Interface::show()
{
}
