#ifndef _ADD_SCENE_H_
#define _ADD_SCENE_H_
#include "Scene.h"
#include "Test.h"
#include "writeAns.h"
//#include "Interface.h"
class AddScene :
    public Scene
{
public:
    AddScene(sf::RenderWindow& window, vector<Scene*>& allScene);

    void show() override;
private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;
    void setAllText(const sf::Event& event) override {}

    Button info;

    vector<Scene*>& allScene;
};
#endif
