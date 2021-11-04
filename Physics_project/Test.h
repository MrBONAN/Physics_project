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
    int selNumber = -1;
    ~Test();
private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;
    void checkIndicator(const sf::Vector2i& msCord, vector<Button*>& btns, int i);
    
    vector<Button*> btns;
    vector<Indicator*> indicators;
    

    sf::Vector2i pastMsCord;
};
#endif
