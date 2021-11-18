#pragma once

#include "MATRIX.h"
#include "COLOR.h"
#include "OBJ_ID.h"
#include "OBJECT.h"
class CANNON :
    public OBJECT
{
public:
    CANNON(class GAME* game);
    ~CANNON();
    int setup();
    void update();
    void draw();
    VECTOR pos();
    VECTOR angle();
    struct DATA {
        VECTOR pos;
        VECTOR angle;
        COLOR wheelColor;
        COLOR bodyColor;
        float ambient;
        float advSpeed;
        float advRotSpeed;
        float rotSpeed;
        float rotBackSpeed;
        int endOfRotationFlag;
        OBJ_ID objId;
    };
private:
    DATA Data;
    OBJECT* Target;
    class CYLINDER* Cylinder;
    class BARREL* Barrel;
    MATRIX Master, WheelL, WheelR, Body;
};