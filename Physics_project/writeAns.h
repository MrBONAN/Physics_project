#ifndef _WRITE_ANS_H_
#define _WIRTE_AND_H_
#include "Scene.h"
class writeAns :
    public Scene
{
public:
    writeAns(sf::RenderWindow& window);

    void show() override;
    int selNumber = -1;

private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;
    void setAllText(const sf::Event& event) override;
    void checkIndicator(const sf::Vector2i& msCord, vector<Button*>& btns, int i);

    vector<Button*> btns;
    Button answerBox;

    sf::Vector2i pastMsCord;
};
#endif
