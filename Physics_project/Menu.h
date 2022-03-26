#pragma once
#include "Classes.h"
#include "Scene.h"
#include "EndTest.h"
#include "Interface.h"
#include "InputWindow.h"
#include "SelectWindow.h"
#include "SaveScene.h"

class Menu :
    public Scene
{
public:
    Menu(sf::RenderWindow& window, Interface& intface, vector<Scene*>& allScene);

    void show() override;

    //~Menu() override {if (addscene != nullptr) { delete addscene; addscene = nullptr; }}
    // тут, наверное, тоже может быть утечка памяти, поэтому просто коментирую этот момент
private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;

    bool openTest();

    void solveTest();
    void makeTest();
    void editTest();

    Button info;

    SaveScene* savescene;
    Interface& intface;
    vector<Scene*>& allScene;
};