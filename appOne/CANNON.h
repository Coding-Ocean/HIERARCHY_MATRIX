#pragma once

#include "MATRIX.h"
#include "COLOR.h"
#include "GAME_OBJECT.h"
#include "OBJECT.h"
class CANNON :
    public GAME_OBJECT,
    public OBJECT
{
public:
    CANNON(class GAME* game);
    ~CANNON();
    int setup();
    void update();
    void draw();
    struct DATA {
        VECTOR objPos;
        COLOR wheelColor;
        COLOR bodyColor;
        float ambient;
        float advSpeed;
        float advRotSpeed;
        float rotSpeed;
    };
private:
    DATA Data;
    class CYLINDER* Cylinder;
    class BARREL* Barrel;
    MATRIX Master, WheelL, WheelR, Body;
};

