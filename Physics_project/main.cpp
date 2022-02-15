#include "Interface.h"
#include "InputWindow.h"
void HideConsole() { ::ShowWindow(::GetConsoleWindow(), SW_HIDE); }
void ShowConsole() { ::ShowWindow(::GetConsoleWindow(), SW_SHOW); }

int main ()
{
    HideConsole();
    //ShowConsole();
    setlocale(LC_ALL, "RUS");

    InputWindow t("test");
    t.loop();
    return 0;
    sf::RenderWindow window(sf::VideoMode(1050, 700), L"������");
    window.setFramerateLimit(30);

    string path = "Icons_3.png";

    OBJ::Init(path);
    Button::init(path);

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