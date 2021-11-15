#pragma once
#include "VECTOR.h"
#include "GAME_OBJECT.h"
#include "OBJECT.h"
class CAMERA :
    public GAME_OBJECT, 
    public OBJECT
{
public:
    struct DATA {
        VECTOR angle;
        float distance = 0;
        float rotSpeed = 0;
        float zoomSpeed = 0;
    };
private:
    struct DATA Data;
    VECTOR UpVec;
    OBJECT* Target[5];
    int TargetIdx = 0;
    VECTOR TargetPos;
public:
    CAMERA(class GAME* game);
    int create();
    void update();
};

