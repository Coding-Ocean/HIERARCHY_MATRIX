#pragma once

#include"MATRIX.h"
#include "GAME_OBJECT.h"
#include "OBJECT.h"
#include "BARREL.h"
#include "CYLINDER.h"
class CANNON :
    public GAME_OBJECT,
    public OBJECT
{
    CYLINDER Cylinder;
    BARREL Barrel;
    MATRIX Master, WheelL, WheelR, BarrelMat;
public:
    CANNON(class GAME* game);
    void update();
    void draw();
};

