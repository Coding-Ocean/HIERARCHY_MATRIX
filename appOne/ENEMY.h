#pragma once
#include "GAME_OBJECT.h"
#include "OBJECT.h"
#include "SPHERE.h"
#include "CYLINDER.h"
class ENEMY :
    public GAME_OBJECT,
    public OBJECT
{
public:
    ENEMY(class GAME* game);
    int setup();
    void update();
    void draw();
    VECTOR pos();
public:
    struct DATA {
        VECTOR pos;
        float animSpeed;
        COLOR headColor;
    };
private:
    DATA Data;
    float AnimAngle = 0;
    SPHERE Sphere;
    CYLINDER Cylinder;
    MATRIX StickModel, HeadModel, NucleusModel;
    MATRIX Master, Stick, Head, NucleusA, NucleusB;
};

