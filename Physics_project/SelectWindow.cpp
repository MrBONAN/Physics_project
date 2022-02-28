#include "SelectWindow.h"

#include <experimental/filesystem>
#include <iostream>
#include <vector>
#include <string>

SelectWindow::SelectWindow() :
    MyWindows({ 390, 487 }, { 190, 30 }, // 260 50
        "�������� ����, �������\n����� �������"),
    left(window, { SWITCHsize, 31, 31 }),
    right(window, { SWITCHsize, 31, 31 }),
    input(window, { BUTTONsize, 190, 20 })
{
    info.setScale(2);
    info.setPosition(5, 5);

    input.setPosition(5, 80);
    input.setStr(pad("����� �� �������� �����"));

    left.setPosition(67, 420);
    left.setScale(-2, 2);
    right.setPosition(323, 420);

    for (int i = 0; i < sizeof(tests) / sizeof(Button*); i++) {
        tests[i] = new Button(window, { BUTTONsize, 190, 20 });
        tests[i]->setPosition(5, 150 + i * 45);
    }

    showBtns.push_back(&info);
    showBtns.push_back(&left);
    showBtns.push_back(&right);
    showBtns.push_back(&input);
    for (auto it : tests) showBtns.push_back(it);

    btns.push_back(&left);
    btns.push_back(&right);
    btns.push_back(&input);
    for (auto it : tests) btns.push_back(it);
}

string SelectWindow::loop(typeInput type)
{
    this->type = type;
    return MyWindows::loop();
}

SelectWindow::~SelectWindow()
{
    for (auto it : tests) delete it;
}

void SelectWindow::checkAllEvents(const sf::Vector2i& msCord)
{

}


list<string> SelectWindow::FindFiles()
{
    list<string> files;
    fs::path dir = ".\\tasks";
    for (fs::directory_iterator it(dir), end; it != end; ++it)
    {
        if (it->path().extension() == ".mfp")
        {
            string filename = it->path().generic_u8string();
            files.push_back(filename.substr(8));
        }
    }
    return files;
}
