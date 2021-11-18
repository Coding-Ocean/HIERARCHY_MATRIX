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

    //Data
    const ALL_DATA* allData();

    //Objects
    class OBJECT* object(OBJ_ID id);
    int addObject(OBJ_ID id, class OBJECT*);

    //Object state
    OBJ_STATE objState();
    void objStateManager();
private:
    ALL_DATA AllData;
    std::vector<class OBJECT*> Objects;
    OBJ_STATE ObjState;
};
