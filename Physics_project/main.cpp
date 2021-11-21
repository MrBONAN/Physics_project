#include "Headers.h"

int main ()
{
    sf::RenderWindow window(sf::VideoMode(1050, 700), "SFML works!");
    window.setFramerateLimit(60);

    string path = "Icons_2.png";
    OBJ::Init(path);

    Interface intface(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            intface.checkAllInteractions(event);
        }

        window.clear(sf::Color(200, 200, 200, 255));
        
        intface.show();
        window.display();
    }

    return 0;
}