#include "Headers.h"
//#define SAVE

int main ()
{
    setlocale(LC_ALL, "RUS");

    sf::RenderWindow window(sf::VideoMode(1050, 700), "SFML works!");
    window.setFramerateLimit(60);

    string path = "Icons_2.png";

    string pathSave("work.txt");
    fstream finout;

    OBJ::Init(path);

    Interface intface(window);

#ifndef SAVE
    finout.open(pathSave, fstream::in);
    if (finout.is_open())
        finout >> intface;
    else { cout << "ERROR" << endl; }
    finout.close();
#endif

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

#ifdef SAVE
    finout.open(pathSave, fstream::out);
    if(finout.is_open())
        finout << intface;
    else { cout << "ERROR" << endl; }
    finout.close();
#endif
    return 0;
}