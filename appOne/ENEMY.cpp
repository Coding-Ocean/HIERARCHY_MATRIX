#include "GAME.h"
#include "ENEMY.h"
ENEMY::ENEMY(GAME* game)
    :OBJECT(game)
{
}

int ENEMY::setup()
{
    Data = game()->allData()->enemyData;
    
    HeadModel.identity();
    HeadModel.mulScaling(0.9f, 0.9f, 0.9f);

    StickModel.identity();
    StickModel.mulTranslate(0, -0.9f, 0);
    StickModel.mulRotateX(1.57f);
    StickModel.mulScaling(0.1f, 0.1f, 1.0f);

    NucleusModel.identity();
    NucleusModel.mulScaling(0.1f, 0.1f, 0.1f);

    return 0;
}

void ENEMY::update()
{
    if (objState() == OBJ_STATE::MOVE) {
        if (isTrigger(KEY_X)) {
            const FORMATION_DATA& fd = game()->allData()->formationData[FormationId];
            Data.pos = fd.enemyPos;
        }
    }

    if (objState()==OBJ_STATE::ROTATE_BACK) {
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

    NucleusB.identity();
    NucleusB.mulRotateZ(-0.7f);
    NucleusB.mulRotateX(AnimAngle);
    NucleusB.mulTranslate(0, 0, -0.6f);
}

void ENEMY::draw()
{
    Cylinder.draw(Master * StickModel, Data.stickColor, Data.ambient);
    
    Sphere.draw(Master * HeadModel, Data.headColor, Data.ambient);

    NucleusA = Master * NucleusA;
    Sphere.draw(NucleusA * NucleusModel);

    NucleusB = Master * NucleusB;
    Sphere.draw(NucleusB * NucleusModel);
}

VECTOR ENEMY::pos()
{
    return Data.pos;
}
