#pragma once
#include "Classes.h"
#include "Scene.h"
class writeAns :
    public Scene
{
public:
    writeAns(sf::RenderWindow& window);

    void showAnswer() override;
    bool checkAnswer() override;

    void show() override;
    int selNumber = -1;

private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;
    void setAllText(const sf::Event& event) override;
    void checkIndicator(const sf::Vector2i& msCord, vector<Button*>& btns, int i);
    
    string outInfo() override;
    void inpInfo(istream& is) override;

    Button answerBox;
};
