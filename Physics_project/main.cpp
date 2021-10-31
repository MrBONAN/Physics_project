#include "Headers.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!");
    
    window.setFramerateLimit(60);

    string path = "Icons_2.png";

    OBJ::Init(path);

    Button btn(window);

    /*sf::Texture tx;
    tx.loadFromFile("Icons_2.png");
    sf::RenderTexture rt;
    rt.create(1000, 1000);
    makeTexture(0, 15, 15, rt, tx, { 17, 1, 4, 11, 11 });
    sf::Sprite */

    //sf::Texture text;
    //text.loadFromFile("Icons.png");
    //sf::RenderTexture rt;
    //rt.create(100, 100);
    ////rt.clear(sf::Color(255, 0, 0, 255));
    //rt.display();
    //makeTexture(15, 15, 17, 1, rt, text, { 4, 11, 11 });
    //sf::Sprite test;
    //test.setTexture(rt.getTexture());
    ////test.setTextureRect(sf::IntRect(17, 1, 15, 15));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(200, 200, 200, 255));
        btn.show();
        window.display();
    }

    return 0;
}