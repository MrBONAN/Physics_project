#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include "Scene.h"
class Interface :
    public Scene
{
public:
    Interface(sf::RenderWindow& window);

    void show() override;
private:
    void checkAllActive(const sf::Vector2i& msCord) override {}
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override {}
    void checkAllEvents(const sf::Vector2i& msCord) override {}
    void setAllText(const sf::Event& event) override {}

    Button left, right;

};
#endif
