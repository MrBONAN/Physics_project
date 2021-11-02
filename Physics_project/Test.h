#ifndef _TEST_H_
#define _TEST_H_
#include "Scene.h"
class Test :
    public Scene
{
public:
    Test(sf::RenderWindow& window);

    void checkALlInteraction(const sf::Event& event) override;

    void show();

    ~Test();
private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;
    vector<Button*> btns;
    vector<Indicator*> indicators;
    int selNumber = -1;

    sf::Vector2i pastMsCord;
};
#endif
