#pragma once
#include "Classes.h"
#include "Scene.h"
#include "AddScene.h"
#include "EndTest.h"
#include "Interface.h"

class Menu :
    public Scene
{
public:
    Menu(sf::RenderWindow& window, Interface& intface, vector<Scene*>& allScene);

    void show() override;

    //~Menu() override {if (addscene != nullptr) { delete addscene; addscene = nullptr; }}
    // ���, ��������, ���� ����� ���� ������ ������, ������� ������ ���������� ���� ������
private:
    void checkAllActive(const sf::Vector2i& msCord) override;
    void checkAllFocus(const sf::Vector2i& msCord, bool first = false)  override;
    void checkAllEvents(const sf::Vector2i& msCord) override;

    void openTest();
    void makeTest();
    void editTest();

    Button info;

    AddScene* addscene;
    Interface& intface;
    vector<Scene*>& allScene;
};