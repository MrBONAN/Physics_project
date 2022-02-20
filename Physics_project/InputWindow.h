#pragma once
#include "Button.h"
#include <fstream>
using std::fstream;

enum typeInput {
	OPENfile,
	CREATEfile
};

class InputWindow
{
public:
	InputWindow(string text);

	string loop(typeInput type);

private:
	void checkAllInteractions(const sf::Event&);
	void checkAllActive(const sf::Vector2i& msCord);
	void checkAllFocus(const sf::Vector2i& msCord, bool first = false);
	void checkAllEvents(const sf::Vector2i& msCord);
	void setAllText(const sf::Event& event);

	void show();

	sf::RenderWindow window;
	Button info, input, ok;
	bool inputActive = false;

	string result = "NONE";
	typeInput type;
	void openFile();
	void createFile();
};

