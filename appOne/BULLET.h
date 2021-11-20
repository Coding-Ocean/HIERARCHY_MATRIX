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
        float radius;
        float length;
        float advSpeed;
        float rotSpeed;
        int numTargets;
        OBJ_ID objId[8];//３つしか使っていない
        float collisionDistance;
        COLOR color;
        float ambient;
    };
private:
    //Data
    DATA Data;
    OBJECT** Targets;//全ターゲットの配列
    int TargetNo = 0;//今向かっているターゲット
    //Model
    CONE* Cone;
    //Matrix
    MATRIX Master;
};
