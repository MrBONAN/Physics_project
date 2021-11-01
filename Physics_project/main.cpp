#include "Headers.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1050, 700), "SFML works!");
    
    window.setFramerateLimit(60);

    string path = "Icons_2.png";

    OBJ::Init(path);

    /*Button btn1(window);
    btn1.setPosition(10, 400);
    Button btn2(window);
    btn2.setPosition(535, 400);
    Button btn3(window);
    btn3.setPosition(10, 525);
    Button btn4(window);
    btn4.setPosition(535, 525);

    Button ex(window, {17, 49, 1, 1, 512, 190, 5, 5, 5});
    ex.setPosition(10, 10);*/

    Test test(window);

    bool msPress = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
       /* if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            btn1.checkFocus(sf::Mouse::getPosition(window));
            btn2.checkFocus(sf::Mouse::getPosition(window));
            btn3.checkFocus(sf::Mouse::getPosition(window));
            btn4.checkFocus(sf::Mouse::getPosition(window));
            OBJ::mouseJustPressed = false;
        }
        else if (OBJ::mouseJustPressed) {

            btn1.Event(sf::Mouse::getPosition(window));
            btn2.Event(sf::Mouse::getPosition(window));
            btn3.Event(sf::Mouse::getPosition(window));
            btn4.Event(sf::Mouse::getPosition(window));
            OBJ::mouseJustPressed = true;
        }*/
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            msPress = true;
            test.checkAllFocus(sf::Mouse::getPosition(window));
        }
        else if (msPress) {
            msPress = false;
            test.checkAllEvents(sf::Mouse::getPosition(window));
        }

        window.clear(sf::Color(200, 200, 200, 255));
      /*  btn1.show();
        btn2.show();
        btn3.show();
        btn4.show();
        ex.show();*/
        test.show();
        window.display();
    }

    return 0;
}