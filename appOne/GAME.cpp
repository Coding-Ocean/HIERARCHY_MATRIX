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

    setState(GAME::STATE::MOVE);

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

void GAME::setState(STATE state)
{
    State = state;
}

void GAME::stateManager()
{
    if (this->state() == GAME::STATE::MOVE) {
        if (isTrigger(KEY_Z)) {
            this->setState(GAME::STATE::ROTATE);
        }
    }

    if (this->state() == GAME::STATE::ROTATE) {
        if (finished &&
            this->object(GAME::OBJ_ID::SATELLITE1)->finished() &&
            this->object(GAME::OBJ_ID::SATELLITE2)->finished()) {
            //if (isTrigger(KEY_Z)) 
                {
                    this->setState(GAME::STATE::FLY);
                }
        }
    }

    if (this->state() == GAME::STATE::FLY) {
        if (this->object(GAME::OBJ_ID::BULLET)->finished()) {
            if (isTrigger(KEY_Z)) {
                this->setState(GAME::STATE::ROTATE_BACK);
            }
        }
    }

    if (this->state() == GAME::STATE::ROTATE_BACK) {
        if (finished &&
            this->object(GAME::OBJ_ID::SATELLITE1)->finished() &&
            this->object(GAME::OBJ_ID::SATELLITE2)->finished()) {
            this->setState(GAME::STATE::MOVE);
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
        clear(64,128,255);
        for (OBJECT* object : Objects)object->update();
        for (OBJECT* object : Objects)object->draw();
    }
}

int GAME::addObject(OBJ_ID id,OBJECT* object)
{
    Objects[static_cast<int>(id)] = object;
    return static_cast<int>(id);
}
