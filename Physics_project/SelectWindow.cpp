#include "SelectWindow.h"

string pad(std::string s, int len = 26);
string from16to8string(u16string inp);

extern string dirPath;

SelectWindow::SelectWindow() :
    MyWindows({ 500, 487 }, { 245, 30 }, // 260 50
        pad("Выберите файл для открытия", 33)),
    left(window, { SWITCHsize, 31, 31 }),
    right(window, { SWITCHsize, 31, 31 }),
    input(window, { BUTTONsize, 245, 20 })
{
    info.setScale(2);
    info.setPosition(5, 5);

    input.setPosition(5, 80);
    input.setStr(pad("Поиск по названию теста", 34));

    left.setPosition(67, 420);
    left.setScale(-2, 2);
    right.setPosition(433, 420);

    for (int i = 0; i < sizeof(tests) / sizeof(Button*); i++) {
        tests[i] = new Button(window, { BUTTONsize, 245, 20 });
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
            result = dirPath + filenames[pageNum * cntButtons + i];
    }
    if (input.Event(msCord)) {
        InputWindow inputwindow("Введите название файла без его\nрасширения (он должен находиться в\nпапке tests рядом с этой программой)");
        string path = inputwindow.loop(typeInput::OPENfile);
        if (path != "CLOSE") result = path;
    }
}


list<string> SelectWindow::FindFiles()
{
    list<string> files;
    fs::path dir = dirPath;
    
    for (fs::directory_iterator it(dir), end; it != end; ++it)
    {
        if (it->path().extension() == ".mfp")
        {
            /*u16string t = u"ТЕст";
            string k = t.c_str();*/
            string filename = from16to8string(it->path().generic_u16string());
            filename = filename.substr(dirPath.length());
            files.push_back(filename);
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
            string filename = filenames[serialNum];
            int maxlen = 32;
            if (filename.length() > maxlen - 1) {
                filename.resize(maxlen - 6);
                filename += "...mfp";
            }
            tests[i]->setStr(to_string(serialNum + 1) + ". " + filename);
        }
        else {
            tests[i]->showButton = false;
        }
    }
}
