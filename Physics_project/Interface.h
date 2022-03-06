#pragma once
#include "Classes.h"
#include "Menu.h"
#include "Scene.h"
#include "ConfirmWindow.h"


class Interface :
    public Scene
{
public:
    Interface(sf::RenderWindow& window);

    void checkAllInteractions(const sf::Event& event);
    void show() override;

    bool saveInfo(string pathSave);
    bool readInfo(string pathRead);

    void setStartTest(bool on) { start = on; }
    void setEndTest(bool on) { end = on; }

    ~Interface() override;
private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;

    Button left, right, close;
    Button levelNumber;

    Menu* menu;

    bool start = false;
    bool end = false;
    Button startButton;

    vector<Scene*> scenes;
    int id = 0;

    friend ostream& operator<<(ostream& os, Interface& obj);
    friend istream& operator>>(istream& is, Interface& obj);
    friend AddScene;
    friend EndTest;
    friend Menu;
};