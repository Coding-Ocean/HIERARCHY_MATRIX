#pragma once
#include "CAMERA.h"
#include "PROJECTOR.h"
#include "LIGHT.h"
#include "CANNON.h"
struct ALL_DATA {
    CAMERA::DATA cameraData;
    PROJECTOR::DATA projectorData;
    LIGHT::DATA lightData;
    CANNON::DATA cannonData;
};
void setAllData(ALL_DATA& allData);