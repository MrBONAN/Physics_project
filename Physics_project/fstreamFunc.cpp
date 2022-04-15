#include "fstreamFunc.h"
#include <cstdlib>
#include <sstream>
#include <random>
using std::stringstream;
using std::rand;

ostream& operator<<(ostream& os, Scene& obj)
{
	os << obj.outInfo();
	return os;
}

istream& operator>>(istream& is, Scene& obj)
{
	obj.inpInfo(is);
	return is;
}


ostream& operator<<(ostream& os, Interface& obj)
{
	SetConsoleCP(1251);
	stringstream oString;
	oString << obj.scenes.size() - 1 << endl;
	for (int i = 0; i < obj.scenes.size() - 1; i++)
	{
		oString << *(obj.scenes[i]);
	}
	srand(123456);
	int cnt = 100;
	while (!oString.eof())
		//os << char((oString.get() + 500) % 256);
		//os << char((oString.get() + rand() % 256) % 256);
		//os << char(oString.get());
		os << char((oString.get() + cnt % 256) % 256);

	//srand(123456);*/
	//os << oString.str();
	/*cout << bfr.str() << endl;
	while (!bfr.eof())
		cout << char((bfr.get() - rand() % 256 + 256) % 256);*/


	return os;
}

istream& operator>>(istream& is, Interface& obj)
{
	SetConsoleCP(1251);

	srand(123456);
	int cnt = 100;
	stringstream iString;
	while (!is.eof())
		//iString << char((is.get() + 512 - 500) % 256);
		//iString << char((is.get() - rand() % 256 + 256) % 256);
		//iString << char(is.get());
		iString << char((is.get() - cnt % 256 + 256) % 256);

	string temp;
	getline(iString, temp);
	int len = atoi(temp.c_str());
	obj.scenes.clear();

	for (int i = 0; i < len; i++)
	{
		getline(iString, temp);
		int type = atoi(temp.c_str());
		switch (type)
		{
		case 0:
			obj.scenes.push_back(new Test(obj.window));
			break;
		case 1:
			obj.scenes.push_back(new writeAns(obj.window));
			break;
		}
		iString >> **obj.scenes.rbegin();
	}
	obj.id = 0;
	return is;
}