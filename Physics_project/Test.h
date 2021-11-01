#ifndef _TEST_H_
#define _TEST_H_
#include "Scene.h"
class Test :
    public Scene
{
public:
    Test(sf::RenderWindow& window);

    void show();

    ~Test();
//private:
    void checkAllFocus(const sf::Vector2i& msCord);
    void checkAllEvents(const sf::Vector2i& msCord);
    vector<Button*> btns;

    sf::Vector2i pastMsCord;
};
#endif
