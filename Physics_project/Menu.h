#pragma once
#include "Scene.h"
#include "AddScene.h"
#include "EndTest.h"
//#include "Interface.h"


class Menu :
    public Scene
{
public:
    Menu(sf::RenderWindow& window, Scene& intface, vector<Scene*>& allScene);

    void show() override;

    //~Menu() override {if (addscene != nullptr) { delete addscene; addscene = nullptr; }}
    // тут, наверное, тоже может быть утечка памяти, поэтому просто коментирую этот момент
private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;

    void openTest();
    void makeTest();
    void editTest();

    Button info;

    AddScene* addscene;
    Scene& intface;
    vector<Scene*>& allScene;
};