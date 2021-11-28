#include "fstreamFunc.h"

ostream& operator<<(ostream& os, Scene& obj)
{
	os << obj.outInfo();
	return os;
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