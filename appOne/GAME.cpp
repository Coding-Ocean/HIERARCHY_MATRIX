#include "GAME.h"
#include "CAMERA.h"
#include "PROJECTOR.h"
#include "LIGHT.h"
#include "FLOOR.h"
#include "CANNON.h"
#include "BULLET.h"
#include "SATELLITE.h"
#include "ENEMY.h"
#include "SNOW_MAN.h"
#include "HUMAN.h"

OBJECT* GAME::object(OBJ id)
{
    return Objects[static_cast<int>(id)];
}

bool GAME::stateIsMove()
{
    return State == MOVE;
}

bool GAME::stateIsRotate()
{
    return State == ROTATE;
}

bool GAME::stateIsFly()
{
    return State == FLY;
}

bool GAME::stateIsRotateBack()
{
    return State == ROTATE_BACK;
}

void GAME::changeStateToMove()
{
    State = MOVE;
}

void GAME::changeStateToRotate()
{
    State = ROTATE;
}

void GAME::changeStateToFly()
{
    State = FLY;
}

void GAME::changeStateToRotateBack()
{
    State = ROTATE_BACK;
}

int GAME::create()
{
    setAllData(allData);

    window(1920, 1080, full);
    hideCursor();
    
    //Objects
    AddObject(OBJ::CAMERA, new CAMERA(this));
    AddObject(OBJ::PROJECTOR, new PROJECTOR(this));
    AddObject(OBJ::LIGHT, new LIGHT(this, 0, 1, 0.2f));
    AddObject(OBJ::FLOOR, new FLOOR(this));
    AddObject(OBJ::CANNON, new CANNON(this));
    AddObject(OBJ::BULLET, new BULLET(this));
    AddObject(OBJ::SATELLITE1, new SATELLITE(this));
    AddObject(OBJ::SATELLITE2, new SATELLITE(this));
    AddObject(OBJ::ENEMY, new ENEMY(this));
    AddObject(OBJ::SNOW_MAN, new SNOW_MAN(this));
    AddObject(OBJ::HUMAN, new HUMAN(this));

    object(GAME::OBJ::CAMERA)->create();

    changeStateToMove();
    return 0;
}

//framework----------------------------------------------------------
GAME::GAME()
    :Objects(static_cast<int>(OBJ::NUM_OBJECTS),nullptr)
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

int GAME::AddObject(OBJ id,OBJECT* object)
{
    //Objects.emplace_back(object);
    //return (int)Objects.size() - 1;
    Objects[static_cast<int>(id)] = object;
    return static_cast<int>(id);
}
