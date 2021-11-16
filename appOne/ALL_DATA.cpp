#include "ALL_DATA.h"
void setAllData(ALL_DATA& allData)
{
    allData.cameraData.objAngle.set(0.32f, 0, 0);
    allData.cameraData.targetIdx = 0;
    allData.cameraData.distance = 17;
    allData.cameraData.rotSpeed = 0.01f;
    allData.cameraData.zoomSpeed = 0.01f;

    allData.projectorData.fov = 0.785f;
    allData.projectorData.aspect = 1.7777777f;
    allData.projectorData.near_ = 0.1f;
    allData.projectorData.far_ = 100.0f;

    allData.lightData.objPos.set(0, 1, 0);

    allData.cannonData.objPos.set(-3, 0.8f, 0);
    allData.cannonData.advSpeed = 0.05f;
    allData.cannonData.advRotSpeed = 0.25f;
    allData.cannonData.rotSpeed = 0.05f;
    allData.cannonData.wheelColor.set(150, 0, 150);
    allData.cannonData.bodyColor.set(255, 150, 150);
    allData.cannonData.ambient = 0.3f;
}