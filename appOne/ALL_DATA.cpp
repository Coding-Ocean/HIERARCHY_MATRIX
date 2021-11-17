#include "ALL_DATA.h"
void setAllData(ALL_DATA& allData)
{
    allData.cameraData.angle.set(0.32f, 0, 0);
    allData.cameraData.targetIdx = 0;
    allData.cameraData.distance = 17;
    allData.cameraData.rotSpeed = 0.01f;
    allData.cameraData.zoomSpeed = 0.01f;

    allData.projectorData.fov = 0.785f;
    allData.projectorData.aspect = 1.7777777f;
    allData.projectorData.near_ = 0.1f;
    allData.projectorData.far_ = 100.0f;

    allData.lightData.pos.set(0, 1, 0);

    allData.floorData.pos.set(0,1,0);
    allData.floorData.color[0].set(0, 0, 0);
    allData.floorData.color[1].set(80, 128, 80);

    allData.cannonData.pos.set(-3, 0.8f, 0);
    allData.cannonData.advSpeed = 0.05f;
    allData.cannonData.advRotSpeed = 0.25f;
    allData.cannonData.rotSpeed = 0.05f;
    allData.cannonData.wheelColor.set(150, 0, 150);
    allData.cannonData.bodyColor.set(255, 150, 150);
    allData.cannonData.ambient = 0.3f;
    allData.cannonData.finishFlag = 0b0001;
    allData.cannonData.objId = OBJ_ID::SATELLITE2;

    allData.bulletData.advSpeed = 0.2f;
    allData.bulletData.color.set(255, 60, 60);
    allData.bulletData.ambient = 0.5f;
    allData.bulletData.numTargets = 3;//ç≈ëÂÇW
    allData.bulletData.objId[0] = allData.cannonData.objId;
    allData.bulletData.objId[1] = OBJ_ID::SATELLITE1;
    allData.bulletData.objId[2] = OBJ_ID::ENEMY;

    allData.satelliteData[0].pos.set(4, 5, 0);
    allData.satelliteData[0].moveRange = 5;
    allData.satelliteData[0].advSpeed = 0.01f;
    allData.satelliteData[0].rotSpeed = 0.05f;
    allData.satelliteData[0].preObjId = OBJ_ID::CANNON;
    allData.satelliteData[0].postObjId = allData.bulletData.objId[1];
    allData.satelliteData[0].bodyColor.set(255, 255, 0);
    allData.satelliteData[0].squareColor.set(255, 200, 60);
    allData.satelliteData[0].ambient = 0.4f;
    allData.satelliteData[0].refAmbient = 0.6f;
    allData.satelliteData[0].animSpeed = 0.017f;
    allData.satelliteData[0].finishFlag = 0b0010;

    allData.satelliteData[1].pos.set(-4, 6, 0);
    allData.satelliteData[1].moveRange = 5;
    allData.satelliteData[1].advSpeed = -0.01f;
    allData.satelliteData[1].rotSpeed = 0.05f;
    allData.satelliteData[1].preObjId = allData.bulletData.objId[1];
    allData.satelliteData[1].postObjId = allData.bulletData.objId[2];
    allData.satelliteData[1].bodyColor.set(255, 255, 0);
    allData.satelliteData[1].squareColor.set(255, 200, 60);
    allData.satelliteData[1].ambient = 0.4f;
    allData.satelliteData[1].refAmbient = 0.6f;
    allData.satelliteData[1].animSpeed = 0.017f;
    allData.satelliteData[1].finishFlag = 0b0100;

    allData.enemyData.pos.set(6, 1.4f, 6);
    allData.enemyData.animSpeed = 0.4f;
    allData.enemyData.headColor.set(90,90,90);
    
    allData.humanData.pos.set(9, 0, 9);
    allData.humanData.animSpeed = 0.06f;
    allData.humanData.c1 = COLOR(62, 66, 163);
    allData.humanData.c2 = COLOR(217, 169, 132);
    allData.humanData.c3 = COLOR(0, 0, 0);
    allData.humanData.c4 = COLOR(255, 100, 100);
    allData.humanData.c5 = COLOR(220, 0, 0);
    allData.humanData.ambient = 0.7f;

    allData.snowManData.pos.set(-9, 1.2f, 9);
    allData.snowManData.ambient = 0.5f;

#define TEST_
#ifdef TEST_A
    allData.cannonData.pos.set(-3, 0.8f, 6);
    allData.satelliteData[0].pos.set(-3, 0.8f, 0);
    allData.satelliteData[1].pos.set(3, 0.8f, 0);
    allData.enemyData.pos.set(3, 0.8f, 6);
    allData.satelliteData[0].advSpeed = 0;
    allData.satelliteData[1].advSpeed = 0;
    allData.bulletData.advSpeed = 0.1f;
#endif
#ifdef TEST_B
    allData.cannonData.pos.set(-3, 0.8f, 0);
    allData.satelliteData[0].pos.set(-3, 6.8f, 0);
    allData.satelliteData[1].pos.set(3, 6.8f, 0);
    allData.enemyData.pos.set(3, 1.4f, 0);
    allData.satelliteData[0].advSpeed = 0;
    allData.satelliteData[1].advSpeed = 0;
    allData.bulletData.advSpeed = 0.1f;
#endif
#ifdef TEST_C
    allData.cannonData.objId = OBJ_ID::SATELLITE2;
    allData.bulletData.objId[0] = allData.cannonData.objId;
    allData.bulletData.objId[1] = OBJ_ID::SATELLITE1;
    allData.bulletData.objId[2] = OBJ_ID::HUMAN;
    allData.satelliteData[0].postObjId = allData.bulletData.objId[1];
    allData.satelliteData[1].preObjId = allData.bulletData.objId[1];
    allData.satelliteData[1].postObjId = allData.bulletData.objId[2];
#endif
}