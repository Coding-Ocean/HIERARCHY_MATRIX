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
public:
    BULLET(class GAME* game);
    void update();
    void draw();
};

