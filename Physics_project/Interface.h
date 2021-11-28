#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include "Scene.h"

class Interface :
    public Scene
{
public:
    Interface(sf::RenderWindow& window);

    void checkAllInteractions(const sf::Event& event);
    void show() override;

    ~Interface() { for (auto& it : scenes) delete it; }
private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;
    void setAllText(const sf::Event& event) override {}
    string outInfo() override { return string(); }

    Button left, right, close;

    vector<Scene*> scenes;
    int id;

    friend ostream& operator<<(ostream& os, Interface& obj);
};
#endif
