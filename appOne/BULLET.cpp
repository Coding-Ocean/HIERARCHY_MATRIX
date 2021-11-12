#include "GAME.h"
#include "BULLET.h"

BULLET::BULLET(GAME* game)
    :GAME_OBJECT(game)
    , Cone(36, 1)
{
    Color.set(255, 60, 60);
}

void BULLET::update()
{
    Pos = game()->cannon()->pos();
    Angle = game()->cannon()->angle();
    float dist = 0.5f;

    if (game()->stateIsRotate()) {
        dist = (game()->satellite1()->pos() - Pos).mag();
    }

    Master.translate(Pos.x, Pos.y, Pos.z);
    Master.mulRotateY(Angle.y);
    Master.mulRotateX(Angle.x);
    Master.mulScaling(0.6f, 0.6f, dist);
}

void BULLET::draw()
{
    Cone.draw(Master,Color);
}
