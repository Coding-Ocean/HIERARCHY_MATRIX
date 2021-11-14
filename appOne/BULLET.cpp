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
    if (game()->stateIsMove()) {
        Pos = game()->cannon()->pos();
        Angle = game()->cannon()->angle();
    }

    if (game()->stateIsRotate()) {
        Angle = game()->cannon()->angle();
    }

    if (game()->stateIsFly()) {
        if (Step == -1) {
            Target[0] = game()->satellite1();
            Target[1] = game()->satellite2();
            Target[2] = game()->snowMan();
            Step = 0;
        }
        if (Step <= 2) {
            VECTOR dir = Target[Step]->pos() - Pos;
            float len = dir.mag();
            Pos += dir.normalize() * 0.1f;
            rotate(dir, 1);
            if (len < 0.11f) {
                Step++;
            }
        }
        else if (isTrigger(KEY_Z)) {
            Step = -1;
            game()->changeStateToRotateBack();
        }
    }

    Master.translate(Pos.x, Pos.y, Pos.z);
    Master.mulRotateY(Angle.y);
    Master.mulRotateX(Angle.x);
    Master.mulScaling(0.6f, 0.6f, 0.6f);
}

void BULLET::draw()
{
    Cone.draw(Master,Color);
}
