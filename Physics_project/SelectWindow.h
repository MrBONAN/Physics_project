#pragma once
#include "MyWindows.h"
#include <experimental/filesystem>
#include <list>

namespace fs = std::experimental::filesystem;
using std::list;

class SelectWindow
	: public MyWindows
{
public:
	SelectWindow();
private:
	void checkAllEvents(const sf::Vector2i& msCord) override {}
	list<string> FindFiles();
};

