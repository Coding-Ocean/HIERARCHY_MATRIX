#pragma once
#include <vector>
#include "ALL_DATA.h"
class GAME
{
public:
    GAME();
    ~GAME();
    int setup();
    void run();
    //All Data
    const ALL_DATA* allData();
    //Objects
    int addObject(OBJ_ID id, class OBJECT*);
    class OBJECT* object(OBJ_ID id);
private:
    ALL_DATA AllData;
    std::vector<class OBJECT*> Objects;
};
