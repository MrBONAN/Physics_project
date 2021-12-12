#ifndef _MENU_H_
#define _MENU_H_
#include "Scene.h"
#include "AddScene.h"
class Menu :
    public Scene
{
public:
    Menu(sf::RenderWindow& window, vector<Scene*>& allScene);

    void show() override;
private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;
    void setAllText(const sf::Event& event) override {}

    string outInfo() override { return string(); }
    void inpInfo(istream& is) override {}

    Button info;

    vector<Scene*>& allScene;
};
#endif
