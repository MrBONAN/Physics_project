#pragma once
#include "Scene.h"
#include "Test.h"
#include "writeAns.h"

class AddScene :
    public Scene
{
public:
    AddScene(sf::RenderWindow& window, vector<Scene*>& allScene);

    void show() override;

    bool saveInfo(string path) override {}
    bool readInfo(string path) override {}
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
