#pragma once
#include "Classes.h"
#include "Scene.h"
class EndTest :
    public Scene
{
public:
    EndTest(sf::RenderWindow& window, Interface& intface, vector<Scene*>& allScene);

    void show() override;

private:
    void checkAllActive(const sf::Vector2i& msCord) override {}
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override {}
    void checkAllEvents(const sf::Vector2i& msCord) override {}

    Button info, endTest;

    Interface& intface;
    vector<Scene*>& allScene;
};

