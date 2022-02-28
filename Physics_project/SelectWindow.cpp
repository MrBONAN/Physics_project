#include "SelectWindow.h"

#include <experimental/filesystem>
#include <iostream>
#include <vector>
#include <string>

SelectWindow::SelectWindow() :
    MyWindows({ 260, 50 }, { 530, 205 },
        "Выберите файл, который нужно открыть")
{
    info.setScale(2);
    info.setPosition(5, 5);

    //yes.setScale(2);

    showBtns.push_back(&info);

    //btns.push_back(&yes);
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
