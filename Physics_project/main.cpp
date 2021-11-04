#include "Headers.h"

int main ()
{
    sf::RenderWindow window(sf::VideoMode(1050, 700), "SFML works!");
    window.setFramerateLimit(60);

    string path = "Icons_2.png";
    OBJ::Init(path);

    vector<Test*> tests;
    for (int i = 0; i < 10; i++)
    {
        tests.push_back(new Test(window));
    }
    int id = 0;


    bool msPress = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            tests[id]->checkALlInteraction(event);
        }

        window.clear(sf::Color(200, 200, 200, 255));
        tests[id]->show();
        window.display();
    }

    for (auto& it : tests) {
        delete it;
    }

    return 0;
}