#pragma once
#include"GAME_OBJECT.h"
#include "OBJECT.h"
#include "PLANE.h"
#include"MATRIX.h"
class FLOOR :
    public GAME_OBJECT,
    public OBJECT
{
    PLANE Plane;
    MATRIX World;
    COLOR Color[2];
public:
    FLOOR(class GAME* game);
    void update();
    void draw();
};

