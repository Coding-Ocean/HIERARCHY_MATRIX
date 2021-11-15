#pragma once
#include "GAME_OBJECT.h"
#include "OBJECT.h"
#include "CONE.h"
class BULLET :
    public GAME_OBJECT,
    public OBJECT
{
    CONE Cone;
    MATRIX Master;
    COLOR Color;
    int Step = -1;
    OBJECT* Target[3];
public:
    BULLET(class GAME* game);
    void update();
    void draw();
    int finished();
};

