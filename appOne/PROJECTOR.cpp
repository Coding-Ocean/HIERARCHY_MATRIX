#include"MODEL.h"
#include "PROJECTOR.h"
PROJECTOR::PROJECTOR(class GAME* game, float fov, float aspect, float near_, float far_)
:GAME_OBJECT(game)
{
    MODEL::proj.pers(fov, aspect, near_, far_);
}
