#include "GAME.h"
#include "CAMERA.h"
#include "PROJECTOR.h"
#include "LIGHT.h"
#include "FLOOR.h"
#include "CANNON.h"
#include "BULLET.h"
#include "SATELLITE.h"
#include "SNOW_MAN.h"
#include "HUMAN.h"

bool GAME::stateIsMove()
{
    return State == MOVE;
}

bool GAME::stateIsRotate()
{
    return State == ROTATE;
}

void GAME::changeStateToMove()
{
    State = MOVE;
}

void GAME::changeStateToRotate()
{
    State = ROTATE;
}

int GAME::create()
{
    window(1920, 1080, full);
    CreateObject(new CAMERA(this));
    CreateObject(new PROJECTOR(this));
    CreateObject(new LIGHT(this,0,1,0));
    CreateObject(new FLOOR(this));
    CannonIdx = CreateObject(new CANNON(this));
    BulletIdx = CreateObject(new BULLET(this));
    Satellite1Idx = CreateObject(new SATELLITE(this));
    Satellite2Idx = CreateObject(new SATELLITE(this));
    SnowManIdx = CreateObject(new SNOW_MAN(this));
    HumanIdx = CreateObject(new HUMAN(this));
    changeStateToMove();

    return 0;
}

OBJECT* GAME::cannon()
{
    return Objects.at(CannonIdx);
}

OBJECT* GAME::bullet()
{
    return Objects.at(BulletIdx);
}

OBJECT* GAME::satellite1()
{
    return Objects.at(Satellite1Idx);
}

OBJECT* GAME::satellite2()
{
    return Objects.at(Satellite2Idx);
}

OBJECT* GAME::snowMan()
{
    return Objects.at(SnowManIdx);
}

OBJECT* GAME::human()
{
    return Objects.at(HumanIdx);
}

//framework----------------------------------------------------------
GAME::GAME()
{
}

GAME::~GAME()
{
    for (OBJECT* object : Objects)delete object;
}

void GAME::run()
{
    while (notQuit) {
        clear(64,128,255);
        for (OBJECT* object : Objects)object->update();
        for (OBJECT* object : Objects)object->draw();
    }
}

int GAME::CreateObject(OBJECT* object)
{
    Objects.emplace_back(object);
    return (int)Objects.size() - 1;
}
