#pragma once
#include "CAMERA.h"
#include "PROJECTOR.h"
#include "LIGHT.h"
#include "CANNON.h"
#include "BULLET.h"
struct ALL_DATA {
    CAMERA::DATA cameraData;
    PROJECTOR::DATA projectorData;
    LIGHT::DATA lightData;
    CANNON::DATA cannonData;
    BULLET::DATA bulletData;
};
void setAllData(ALL_DATA& allData);