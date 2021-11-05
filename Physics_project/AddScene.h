#pragma once
#include "Scene.h"
#include "Test.h"
class AddScene :
    public Scene
{
public:
    AddScene(sf::RenderWindow& window, vector<Scene*>& allScene);

    void checkAllInteraction(const sf::Event& event) override;

    void show() override;
private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;
    
    sf::Vector2i pastMsCord;

    Button info;

    vector<Button*> btns;
    vector<Scene*>& allScene;
};

