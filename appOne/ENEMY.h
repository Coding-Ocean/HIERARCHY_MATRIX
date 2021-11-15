#pragma once
#include "GAME_OBJECT.h"
#include "OBJECT.h"
#include "SPHERE.h"
#include "CYLINDER.h"
class ENEMY :
    public GAME_OBJECT,
    public OBJECT
{
    SPHERE Sphere;
    CYLINDER Cylinder;
    MATRIX StickModel, HeadModel, NucleusModel;
    MATRIX Master, Stick, Head, NucleusA, NucleusB;
    float AnimAngle = 0;
public:
    ENEMY(class GAME* game);
    void update();
    void draw();
};

