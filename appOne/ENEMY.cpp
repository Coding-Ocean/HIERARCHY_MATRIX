#include "GAME.h"
#include "ENEMY.h"
ENEMY::ENEMY(GAME* game)
    :GAME_OBJECT(game)
{
}

int ENEMY::setup()
{
    Data = game()->allData.enemyData;

    HeadModel.identity();
    HeadModel.mulScaling(0.9f, 0.9f, 0.9f);

    StickModel.identity();
    StickModel.mulTranslate(0, -0.9f, 0);
    StickModel.mulRotateX(1.57f);
    StickModel.mulScaling(0.1f, 0.1f, 1.0f);

    return 0;
}

void ENEMY::update()
{
    if (game()->object(OBJ_ID::BULLET)->finished()) {
        AnimAngle = 0;
    }
    else {
        AnimAngle += Data.animSpeed;
    }

    Master.identity();
    Master.mulTranslate(Data.pos.x, Data.pos.y, Data.pos.z);

    NucleusA.identity();
    NucleusA.mulRotateZ(0.7f);
    NucleusA.mulRotateX(AnimAngle);
    NucleusA.mulTranslate(0, 0, 0.6f);
    NucleusA.mulScaling(0.1f, 0.1f, 0.1f);
}

void ENEMY::draw()
{

    Cylinder.draw(Master * StickModel, COLOR(255,255,255), 0.4);
    
    Sphere.draw(Master * HeadModel, Data.headColor);

    NucleusA = Master * NucleusA;
    Sphere.draw(NucleusA);

    NucleusA.identity();
    NucleusA.mulRotateZ(-0.7f);
    NucleusA.mulRotateX(AnimAngle);
    NucleusA.mulTranslate(0, 0, -0.6f);
    NucleusA.mulScaling(0.1f, 0.1f, 0.1f);
    NucleusA = Master * NucleusA;
    Sphere.draw(NucleusA);
}

VECTOR ENEMY::pos()
{
    return Data.pos;
}
