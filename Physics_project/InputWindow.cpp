#include "InputWindow.h"

string pad(std::string s, int len = 26);

InputWindow::InputWindow(string text) : MyWindows({ 530, 205 }, {260, 50}, text),
	input	(window, { BUTTONsize, 260, 20 }),
	ok		(window, { BUTTONsize, 40, 20})
{
	info.setScale(2);
	info.setPosition(5, 5);

	input.setScale(2);
	input.setPosition(5, 115);
	input.showCursor = true;

	ok.setScale(2);
	ok.setPosition(225, 160);
	ok.setStr(pad("ок", 5));


	showBtns.push_back(&info);
	showBtns.push_back(&input);
	showBtns.push_back(&ok);

	btns.push_back(&input);
	btns.push_back(&ok);
}

string InputWindow::loop(typeInput type)
{
	this->type = type;
	return MyWindows::loop();
}

void InputWindow::checkAllEvents(const sf::Vector2i& msCord)
{
	if (input.Event(msCord)) {
		if (inputActive) {
			inputActive = false;
			input.ind.off();
		} else {
			inputActive = true;
			input.ind.on();
		}
	}
	if (ok.Event(msCord)) {
		inputActive = false;
		input.ind.off();
		switch (type)
		{
		case OPENfile:
			openFile();
			break;
		case CREATEfile:
			createFile();
			break;
		default:
			break;
		}
	}
}

void InputWindow::setAllText(const sf::Event& event)
{
	if (inputActive) {
		int comand = input.getKey(event);
		if (comand != int('\n') && (input.getStr().size() < 22 || comand < 0))
			input.setText(event, comand);
	}
	
}

void InputWindow::openFile()
{
	string path = "tasks\\" + input.getStr() + ".mfp";
	fstream fin;
	fin.open(path, fstream::in);
	bool res;
	if (fin.is_open())
		result = path;
	else {
		InfoWindow infowindow("Данный файл не существует.");
		infowindow.loop();
	}
	fin.close();
}

void InputWindow::createFile()
{
	string path = "tasks\\" + input.getStr() + ".mfp";
	fstream fin;
	fin.open(path, fstream::in);
	bool res;
	if (fin.is_open()) {
		ConfirmWindow confwindow("Файл уже существует.\nПерезаписать его?");
		if(confwindow.loop() == "YES") result = path;
	}
	else result = path;
	fin.close();
}
