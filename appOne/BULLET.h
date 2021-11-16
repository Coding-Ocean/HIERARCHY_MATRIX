#pragma once
#include "GAME_OBJECT.h"
#include "OBJECT.h"
#include "CONE.h"
class BULLET :
    public GAME_OBJECT,
    public OBJECT
{
public:
    BULLET(class GAME* game);
    ~BULLET();
    int setup();
    void update();
    void draw();
    int finished();
    struct DATA {
        VECTOR pos;
        VECTOR angle;
        COLOR color;
        int numTargets;
        GAME::OBJ_ID objId[8];
    };
private:
    DATA Data;
    CONE* Cone;
    MATRIX Master;
    OBJECT** Targets;
    int Step = 0;
};

