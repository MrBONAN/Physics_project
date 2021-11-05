#include "Headers.h"

int main ()
{
    sf::RenderWindow window(sf::VideoMode(1050, 700), "SFML works!");
    window.setFramerateLimit(60);

    string path = "Icons_2.png";
    OBJ::Init(path);

    vector<Scene*> tests;
    for (int i = 0; i < 0; i++)
    {
        tests.push_back(new Test(window));
    }
    tests.push_back(new AddScene(window, tests));
    int id = 0;
    
    Button left(window, {81, 33, 113,33, 31, 31, 0, 31, 31 }); 
    Button right(window, {81, 1, 113, 1, 31, 31, 0, 31, 31});
    right.ind.off();
    left.setPosition(10,630);
    right.setPosition(973, 630);

    bool msPress = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                left.checkActive(sf::Mouse::getPosition(window));
                right.checkActive(sf::Mouse::getPosition(window));
                
            }
            //кнока нажата в данный момент
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                left.checkFocus(sf::Mouse::getPosition(window));
                right.checkFocus(sf::Mouse::getPosition(window));
            }
            //кнопка была отпущена
            if (event.type == sf::Event::MouseButtonReleased) {
                if (left.Event(sf::Mouse::getPosition(window))) id = max(0, id - 1);
                if (right.Event(sf::Mouse::getPosition(window))) id = min(int(tests.size()) - 1, id + 1);
                
            }
            tests[id]->checkAllInteraction(event);
        }

        window.clear(sf::Color(200, 200, 200, 255));
        tests[id]->show();
        left.show();
        right.show();
        window.display();
    }

    for (auto& it : tests) {
        delete it;
    }

    return 0;
}