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
GAME::GAME()
    :Objects(static_cast<int>(OBJ_ID::NUM_OBJECTS), nullptr)
{
}

GAME::~GAME()
{
    for (OBJECT* object : Objects)SAFE_DELETE(object);
}

int GAME::setup()
{
    setAllData(AllData);

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
    //addObject(OBJ_ID::HUMAN, new HUMAN(this));
    new HUMAN(this, OBJ_ID::HUMAN);

    for (OBJECT* object : Objects)object->setup();

    return 0;
}

int GAME::addObject(OBJ_ID id, OBJECT* object)
{
    Objects[static_cast<int>(id)] = object;
    return static_cast<int>(id);
}

void GAME::run()
{
    while (notQuit) {
        clear(0, 0, 40);
        OBJECT::objStateManager();
        for (OBJECT* object : Objects)object->update();
        for (OBJECT* object : Objects)object->draw();
    }
}

const ALL_DATA* GAME::allData()
{
    return &AllData;
}

OBJECT* GAME::object(OBJ_ID id)
{
    return Objects[static_cast<int>(id)];
}
