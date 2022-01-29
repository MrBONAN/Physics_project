#pragma once
#include "Classes.h"
#include "Scene.h"
class Test :
    public Scene
{
public:
    Test(sf::RenderWindow& window);
    
    void showAnswer() override;
    bool checkAnswer() override;
    int selNumber = -1;
    int selAnsNumber = -1;

    void show() override;

    ~Test() override;

private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;
    void setAllText(const sf::Event& event) override;
    void checkIndicator(const sf::Vector2i& msCord, vector<Button*>& btns, int i, int& selNumber);

    string outInfo() override;
    void inpInfo(istream& is) override;

    vector<Button*> btnAnswer;
};
