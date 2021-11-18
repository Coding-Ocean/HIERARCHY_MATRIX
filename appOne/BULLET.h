#pragma once
#include "OBJECT.h"
#include "CONE.h"
class BULLET :
    public OBJECT
{
//Functions
public:
    BULLET(class GAME* game);
    ~BULLET();
    int setup();
    void update();
    void draw();
    VECTOR pos();
//DATA
public:
    struct DATA {
        VECTOR pos;
        VECTOR angle;
        float advSpeed;
        float rotSpeed;
        int numTargets;
        OBJ_ID objId[8];
        float collisionDistance;
        COLOR color;
        float ambient;
    };
private:
    DATA Data;
    OBJECT** Targets;
    int TargetNo = 0;
    CONE* Cone;
    MATRIX Master;
};
