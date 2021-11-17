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

int GAME::setup()
{
    setAllData(allData);

    window(1920, 1080, full);
    hideCursor();
    
    //Objects
    addObject(OBJ_ID::CAMERA, new CAMERA(this));
    addObject(OBJ_ID::PROJECTOR, new PROJECTOR(this));
    addObject(OBJ_ID::LIGHT, new LIGHT(this));
    addObject(OBJ_ID::FLOOR, new FLOOR(this));
    addObject(OBJ_ID::CANNON, new CANNON(this));
    addObject(OBJ_ID::BULLET, new BULLET(this));
    addObject(OBJ_ID::SATELLITE1, new SATELLITE(this));
    addObject(OBJ_ID::SATELLITE2, new SATELLITE(this));
    addObject(OBJ_ID::ENEMY, new ENEMY(this));
    addObject(OBJ_ID::SNOW_MAN, new SNOW_MAN(this));
    addObject(OBJ_ID::HUMAN, new HUMAN(this));

    for (OBJECT* object : Objects)object->setup();

    State = GAME::STATE::MOVE;

    return 0;
}

OBJECT* GAME::object(OBJ_ID id)
{
    return Objects[static_cast<int>(id)];
}

GAME::STATE GAME::state()
{
    return State;
}

void GAME::stateManager()
{
    if (State == GAME::STATE::MOVE) {
        if (isTrigger(KEY_Z)) {
            State = GAME::STATE::ROTATE;
        }
    }

    else if (State == GAME::STATE::ROTATE) {
        if (object(OBJ_ID::CANNON)->finished() &&
            object(OBJ_ID::SATELLITE1)->finished() &&
            object(OBJ_ID::SATELLITE2)->finished()) {
            //if (isTrigger(KEY_Z)) 
            {
                State = GAME::STATE::FLY;
                Count = 0;
            }
        }
    }

    else if (State == GAME::STATE::FLY) {
        if (object(OBJ_ID::BULLET)->finished()) {
            if (++Count > 90) {
                State = GAME::STATE::ROTATE_BACK;
            }
        }
    }

    else if (State == GAME::STATE::ROTATE_BACK) {
        if (object(OBJ_ID::CANNON)->finished() &&
            object(OBJ_ID::SATELLITE1)->finished() &&
            object(OBJ_ID::SATELLITE2)->finished()) {
            State = GAME::STATE::MOVE;
        }
    }
}

GAME::GAME()
    :Objects(static_cast<int>(OBJ_ID::NUM_OBJECTS),nullptr)
{
}

GAME::~GAME()
{
    for (OBJECT* object : Objects)delete object;
}

void GAME::run()
{
    while (notQuit) {
        clear(0,0,40);
        for (OBJECT* object : Objects)object->update();
        for (OBJECT* object : Objects)object->draw();
        stateManager();
    }
}

int GAME::addObject(OBJ_ID id,OBJECT* object)
{
    Objects[static_cast<int>(id)] = object;
    return static_cast<int>(id);
}
