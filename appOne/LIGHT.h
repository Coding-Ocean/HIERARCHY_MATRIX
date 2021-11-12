#pragma once
#include "GAME_OBJECT.h"
#include "OBJECT.h"
class LIGHT :
    public GAME_OBJECT,
    public OBJECT
{
public:
    LIGHT(class GAME* game, float x=0, float y=0, float z=1);
};

