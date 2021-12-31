#pragma once
#include "Interface.h"
#include "AddScene.h"
#include <iostream>

ostream& operator<<(ostream& os, Interface& obj);
ostream& operator<<(ostream& os, Scene& obj);

istream& operator>>(istream& os, Interface& obj);
istream& operator>>(istream& os, Scene& obj);
