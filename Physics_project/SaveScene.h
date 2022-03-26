#pragma once
#include "Classes.h"
#include "Scene.h"
#include "Test.h"
#include "writeAns.h"
#include <sys\stat.h>
#include "Interface.h"
#include "InputWindow.h"

class SaveScene :
    public Scene
{
public:
    SaveScene(sf::RenderWindow& window, Interface& intface, vector<Scene*>& allScene);

    void show() override;

private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;

    void saveTest();
    void menuExit();

    Button info;

    Interface& intface;
    vector<Scene*>& allScene;
};
