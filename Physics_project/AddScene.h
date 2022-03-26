#pragma once
#include "Classes.h"
#include "Scene.h"
#include "Test.h"
#include "writeAns.h"
#include <sys\stat.h>
#include "Interface.h"
#include "InputWindow.h"
#include "MyWindows.h"

enum typeTest {
    TEST,
    WRITEANS
};

class AddScene :
    public MyWindows
{
public:
    AddScene();
    ~AddScene();
private:
    void checkAllEvents(const sf::Vector2i& msCord) override;
};
