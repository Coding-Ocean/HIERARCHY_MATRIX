#include "GAME.h"
#include "ENEMY.h"
ENEMY::ENEMY(GAME* game)
    :GAME_OBJECT(game)
{
    Pos.set(6, 1.4f, 6);
    Angle.set(0, 0, 0);

    HeadModel.identity();
    HeadModel.mulScaling(0.9f, 0.9f, 0.9f);

    StickModel.identity();
    StickModel.mulTranslate(0, -0.9f, 0);
    StickModel.mulRotateX(1.57f);
    StickModel.mulScaling(0.1f, 0.1f, 1.0f);
}

void ENEMY::update()
{
    if (game()->object(GAME::OBJ::BULLET)->finished() ||
        game()->stateIsRotateBack()) {
        AnimAngle = 0;
    }
    else {
        AnimAngle += 0.04f;
    }
}

void ENEMY::draw()
{
    Master.identity();
    Master.mulTranslate(Pos.x, Pos.y, Pos.z);

    Cylinder.draw(Master * StickModel);
    
    Sphere.draw(Master * HeadModel, COLOR(90,90,90));

    NucleusA.identity();
    NucleusA.mulRotateZ(0.7f);
    NucleusA.mulRotateX(AnimAngle*10);
    NucleusA.mulTranslate(0, 0, 0.6f);
    NucleusA.mulScaling(0.1f, 0.1f, 0.1f);
    NucleusA = Master * NucleusA;
    Sphere.draw(NucleusA);

    NucleusA.identity();
    NucleusA.mulRotateZ(-0.7f);
    NucleusA.mulRotateX(AnimAngle*10);
    NucleusA.mulTranslate(0, 0, -0.6f);
    NucleusA.mulScaling(0.1f, 0.1f, 0.1f);
    NucleusA = Master * NucleusA;
    Sphere.draw(NucleusA);
}
