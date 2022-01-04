#pragma once
#include "Scene.h"
#include "AddScene.h"
//#include "Interface.h"


class Menu :
    public Scene
{
public:
    Menu(sf::RenderWindow& window, Scene& intface, vector<Scene*>& allScene);

    void show() override;

    bool saveInfo(string path) override {}
    bool readInfo(string path) override {}
private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;
    void setAllText(const sf::Event& event) override {}

    void openTest();
    void makeTest();
    void editTest();

    string outInfo() override { return string(); }
    void inpInfo(istream& is) override {}

    Button info;

    Scene& intface;
    vector<Scene*>& allScene;
};