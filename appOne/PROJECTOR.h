#pragma once
#include "GAME_OBJECT.h"
#include "OBJECT.h"
class PROJECTOR:
    public GAME_OBJECT,
    public OBJECT
{
public:
    PROJECTOR(
        class GAME* game, 
        float fov=0.785f, 
        float aspect=1.7777777f, 
        float near_=0.1f, 
        float far_=100.0f);
};

