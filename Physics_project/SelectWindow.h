#pragma once
#include "MyWindows.h"
#include "InputWindow.h"
#include <experimental/filesystem>
#include <list>

#include <iostream>
#include <string>
#include <codecvt>
#include <cassert>
#include <locale>

string pad(std::string s, int len = 26);

namespace fs = std::experimental::filesystem;
using std::list;

class SelectWindow
	: public MyWindows
{
public:
	SelectWindow();
	string loop(typeInput type);
	~SelectWindow();
private:
	void checkAllEvents(const sf::Vector2i& msCord) override;
	Button left, right, input;
	typeInput type;
	Button* tests[6];
	list<string> FindFiles();
	vector<string> filenames;
	int pageNum;
	void updatePage();
};

