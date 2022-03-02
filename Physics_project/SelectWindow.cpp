#include "SelectWindow.h"

string pad(std::string s, int len = 26);

SelectWindow::SelectWindow() :
    MyWindows({ 390, 487 }, { 190, 30 }, // 260 50
        "Выберите файл, который\nнужно открыть"),
    left(window, { SWITCHsize, 31, 31 }),
    right(window, { SWITCHsize, 31, 31 }),
    input(window, { BUTTONsize, 190, 20 })
{
    info.setScale(2);
    info.setPosition(5, 5);

    input.setPosition(5, 80);
    input.setStr(pad("Поиск по названию теста"));

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
    
    // поиск файлов
    // копирование данных в vector
    list<string> temp = FindFiles();
    filenames.assign(temp.begin(), temp.end());

    pageNum = 0;
    updatePage();
}

SelectWindow::~SelectWindow()
{
    for (auto it : tests) delete it;
}

void SelectWindow::checkAllEvents(const sf::Vector2i& msCord)
{
    int cntButtons = sizeof(tests) / sizeof(Button*);
    if (left.Event(msCord)) {
        pageNum = max(0, pageNum - 1);
        updatePage();
    }
    if (right.Event(msCord)) {
        if ((pageNum + 1) * cntButtons < filenames.size()) pageNum++;
        updatePage();
    }
    for (int i = 0; i < cntButtons; i++)
    {
        if (tests[i]->Event(msCord))
            result = "tasks\\" + filenames[pageNum * cntButtons + i];
    }
    if (input.Event(msCord)) {
        InputWindow inputwindow("Введите название файла без его\nрасширения (он должен находиться в\nпапке tasks рядом с этой программой)");
        string path = inputwindow.loop(typeInput::OPENfile);
        if (path != "CLOSE") result = path;
    }
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

void SelectWindow::updatePage()
{
    int cntButtons = sizeof(tests) / sizeof(Button*);
    for (int i = 0; i < cntButtons; i++)
    {
        int serialNum = pageNum * cntButtons + i;
        if (serialNum < filenames.size())
        {
            tests[i]->showButton = true;
            tests[i]->setStr(to_string(serialNum + 1) + ". " + filenames[serialNum]);
        }
        else {
            tests[i]->showButton = false;
        }
    }
}
