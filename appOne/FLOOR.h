#pragma once
#include"GAME_OBJECT.h"
#include "OBJECT.h"
#include "PLANE.h"
#include"MATRIX.h"
class FLOOR :
    public GAME_OBJECT,
    public OBJECT
{
public:
    FLOOR(class GAME* game);
    int setup();
    void draw();
    VECTOR pos();
    struct DATA {
        VECTOR pos;
        VECTOR angle;
        COLOR color[2];
    };
private:
    DATA Data;
    PLANE Plane;
    MATRIX World;
};

