#pragma once
#include "Scene.h"
#include "Test.h"
#include "writeAns.h"
#include <sys\stat.h>

class AddScene :
    public Scene
{
public:
    AddScene(sf::RenderWindow& window, Scene& intface, vector<Scene*>& allScene);

    void show() override;

private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;

    void saveTest();

    Button info;

    Scene& intface;
    vector<Scene*>& allScene;
};
