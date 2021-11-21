#pragma once
#include "OBJECT.h"
#include "SPHERE.h"
#include "CYLINDER.h"
class ENEMY :
    public OBJECT
{
//functions
public:
    ENEMY(class GAME* game);
    int setup();
    void update();
    void draw();
    VECTOR pos();
//Data
public:
    struct DATA {
        VECTOR pos;
        VECTOR offsetPos;//頭の中心へのオフセット
        float offsetPosY;
        float animSpeed;
        COLOR headColor;
        COLOR stickColor;
        float ambient;
    };
private:
    //data
    DATA Data;
    float AnimAngle = 0;
    float AngleForPos = 0;
    //model
    SPHERE Sphere;
    CYLINDER Cylinder;
    //matrix
    MATRIX StickModel, HeadModel, NucleusModel;
    MATRIX Master, Stick, Head, NucleusA, NucleusB;
};

