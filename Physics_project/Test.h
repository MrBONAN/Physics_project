#ifndef _TEST_H_
#define _TEST_H_
#include "Scene.h"
class Test :
    public Scene
{
public:
    Test(sf::RenderWindow& window);
    
    void show() override;
    int selNumber = -1;
    ~Test();
private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;
    void setAllText(const sf::Event& event) override;
    void checkIndicator(const sf::Vector2i& msCord, vector<Button*>& btns, int i);

    string outInfo() override;
};
#endif
