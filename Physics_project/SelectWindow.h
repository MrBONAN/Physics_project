#pragma once
#include "MyWindows.h"
#include "InputWindow.h"
#include <experimental/filesystem>
#include <list>

namespace fs = std::experimental::filesystem;
using std::list;

class SelectWindow
	: public MyWindows
{
public:
	SelectWindow();
	~SelectWindow();
private:
	void checkAllEvents(const sf::Vector2i& msCord) override;
	Button left, right, input;
	Button* tests[6];
	list<string> FindFiles();
	vector<string> filenames;
	int pageNum;
	void updatePage();
};

