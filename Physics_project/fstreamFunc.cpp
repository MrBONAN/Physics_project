#include "fstreamFunc.h"
#include <cstdlib>

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
	os << obj.scenes.size() - 1 << endl;
	for (int i = 0; i < obj.scenes.size() - 1; i++)
	{
		os << *(obj.scenes[i]);
	}
	SetConsoleCP(866);
	return os;
}

istream& operator>>(istream& is, Interface& obj)
{
	string temp;
	getline(is, temp);
	int len = atoi(temp.c_str());
	obj.scenes.clear();

	for (int i = 0; i < len; i++)
	{
		getline(is, temp);
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
		is >> **obj.scenes.rbegin();
	}
	obj.id = 0;
	return is;
}