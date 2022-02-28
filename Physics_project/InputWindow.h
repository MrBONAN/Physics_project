#pragma once
#include "Button.h"
#include "MyWindows.h"
#include "ConfirmWindow.h"
#include "InfoWindow.h"
#include <fstream>
using std::fstream;

enum typeInput {
	OPENfile,
	CREATEfile
};

class InputWindow
	: public MyWindows
{
public:
	InputWindow(string text);

	string loop(typeInput type);

private:
	void checkAllEvents(const sf::Vector2i& msCord) override;
	void setAllText(const sf::Event& event) override;

	Button input, ok;
	bool inputActive = false;

	typeInput type;
	void openFile();
	void createFile();
};

