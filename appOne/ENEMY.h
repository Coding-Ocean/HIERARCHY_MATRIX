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
    MATRIX SphereModelA, SphereModelB;
    MATRIX SphereA, SphereB, Connect;
public:
    ENEMY(class GAME* game);
};

