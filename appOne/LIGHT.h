#pragma once
#include "GAME_OBJECT.h"
#include "OBJECT.h"
class LIGHT :
    public GAME_OBJECT,
    public OBJECT
{
public:
    LIGHT(class GAME* game);
    int setup();
    struct DATA {
        VECTOR objPos;
    };
private:
    DATA Data;
};

