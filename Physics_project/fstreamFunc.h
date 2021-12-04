#ifndef _OUTFUNC_H_
#define _OUTFUNC_H_
#include "Headers.h"

ostream& operator<<(ostream& os, Interface& obj);
ostream& operator<<(ostream& os, Scene& obj);

istream& operator>>(istream& os, Interface& obj);
istream& operator>>(istream& os, Scene& obj);

#endif
