//#include "Headers.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

#include "OBJ.h"
#include "Button.h"
#include "Test.h"
#include "writeAns.h"
#include "Interface.h"
#include "Indicator.h"
#include "AddScene.h"
#include "Scene.h"
#include "Menu.h"

using namespace std;

#define SAVE

void HideConsole() { ::ShowWindow(::GetConsoleWindow(), SW_HIDE); }
void ShowConsole() { ::ShowWindow(::GetConsoleWindow(), SW_SHOW); }


int main ()
{
    //HideConsole();
    setlocale(LC_ALL, "RUS");

    sf::RenderWindow window(sf::VideoMode(1050, 700), L"Проект");
    window.setFramerateLimit(60);

    string path = "Icons_2.png";

    string pathSave("work.mfp");

    OBJ::Init(path);

    Interface intface(window);

//#ifndef SAVE
//    intface.readInfo(pathSave);
//#endif

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

//#ifdef SAVE
//    intface.saveInfo(pathSave);
//#endif
    //ShowConsole();
    return 0;
}