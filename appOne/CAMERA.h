#pragma once
#include "VECTOR.h"
#include "GAME_OBJECT.h"
#include "OBJECT.h"
class CAMERA :
    public GAME_OBJECT, 
    public OBJECT
{
public:
    CAMERA(class GAME* game);
    int setup();
    void update();
    VECTOR angle();
    struct DATA {
        VECTOR pos;
        VECTOR angle;
        float distance = 0;
        float rotSpeed = 0;
        float zoomSpeed = 0;
        int targetIdx = 0;
    };
private:
    struct DATA Data;
    OBJECT* Target[5];
    VECTOR TargetPos;
    VECTOR UpVec;
};

