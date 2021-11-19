#include "ALL_DATA.h"
void setAllData(ALL_DATA& ad)
{
    ad.w = 1600;
    ad.h = 900;
    ad.windowFlag = 0;

    ad.cameraData.angle.set(0.32f, 0, 0);
    ad.cameraData.targetIdx = 0;
    ad.cameraData.distance = 17;
    ad.cameraData.rotSpeed = 0.01f;
    ad.cameraData.zoomSpeed = 0.01f;

    ad.projectorData.fov = 0.785f;
    ad.projectorData.aspect = 1.7777777f;
    ad.projectorData.near_ = 0.1f;
    ad.projectorData.far_ = 100.0f;

    ad.lightData.pos.set(0, 1, 0);

    ad.floorData.pos.set(0,1,0);//床の位置ではない。カメラルックアット座標。
    ad.floorData.color[0].set(0, 0, 0);
    ad.floorData.color[1].set(80, 128, 80);

    ad.cannonData.pos.set(-6, 0.8f, 6);
    ad.cannonData.advSpeed = 0.05f;
    ad.cannonData.advRotSpeed = 0.25f;
    ad.cannonData.rotSpeed = 0.05f;
    ad.cannonData.rotBackSpeed = 0.025f;
    ad.cannonData.wheelColor.set(150, 0, 150);
    ad.cannonData.bodyColor.set(255, 150, 150);
    ad.cannonData.ambient = 0.3f;
    ad.cannonData.endOfRotationFlag = 0b0001;
    ad.cannonData.objId = OBJ_ID::SATELLITE1;

    ad.bulletData.advSpeed = 0.2f;
    ad.bulletData.rotSpeed = 0.25f;
    ad.bulletData.collisionDistance = 0.3f;
    ad.bulletData.color.set(255, 60, 60);
    ad.bulletData.ambient = 0.5f;
    ad.bulletData.numTargets = 3;//最大８
    ad.bulletData.objId[0] = OBJ_ID::SATELLITE1;
    ad.bulletData.objId[1] = OBJ_ID::SATELLITE2;
    ad.bulletData.objId[2] = OBJ_ID::ENEMY;//最後のターゲットは変更できる
    //ad.bulletData.objId[3] = OBJ_ID::SNOW_MAN;//最後のターゲットは変更できる
    //ad.bulletData.objId[4] = OBJ_ID::HUMAN;//最後のターゲットは変更できる

    ad.satelliteData[0].pos.set(4, 5, 0);
    ad.satelliteData[0].moveRange = 5;
    ad.satelliteData[0].advSpeed = 0.01f;
    ad.satelliteData[0].rotSpeed = 0.05f;
    ad.satelliteData[0].rotBackSpeed = 0.025f;
    ad.satelliteData[0].preObjId = OBJ_ID::CANNON;
    ad.satelliteData[0].postObjId = OBJ_ID::SATELLITE2;
    ad.satelliteData[0].bodyColor.set(255, 255, 0);
    ad.satelliteData[0].squareColor.set(255, 200, 60);
    ad.satelliteData[0].ambient = 0.4f;
    ad.satelliteData[0].refAmbient = 0.6f;
    ad.satelliteData[0].animSpeed = 0.017f;
    ad.satelliteData[0].endOfRotationFlag = 0b0010;

    ad.satelliteData[1].pos.set(-4, 6, 0);
    ad.satelliteData[1].moveRange = 5;
    ad.satelliteData[1].advSpeed = -0.01f;
    ad.satelliteData[1].rotSpeed = 0.05f;
    ad.satelliteData[1].rotBackSpeed = 0.025f;
    ad.satelliteData[1].preObjId = OBJ_ID::SATELLITE1;
    ad.satelliteData[1].postObjId = ad.bulletData.objId[2];
    ad.satelliteData[1].bodyColor.set(255, 255, 0);
    ad.satelliteData[1].squareColor.set(255, 200, 60);
    ad.satelliteData[1].ambient = 0.4f;
    ad.satelliteData[1].refAmbient = 0.6f;
    ad.satelliteData[1].animSpeed = 0.017f;
    ad.satelliteData[1].endOfRotationFlag = 0b0100;

    ad.enemyData.pos.set(6, 1.4f, 6);
    ad.enemyData.animSpeed = 0.4f;
    ad.enemyData.headColor.set(90, 90, 90);
    ad.enemyData.stickColor.set(255,255,255);
    ad.enemyData.ambient = 0.4f;

    ad.humanData.pos.set(9, 0, 9);
    ad.humanData.animSpeed = 0.06f;
    ad.humanData.c1 = COLOR(62, 66, 163);
    ad.humanData.c2 = COLOR(217, 169, 132);
    ad.humanData.c3 = COLOR(0, 0, 0);
    ad.humanData.c4 = COLOR(255, 100, 100);
    ad.humanData.c5 = COLOR(220, 0, 0);
    ad.humanData.ambient = 0.7f;

    ad.snowManData.pos.set(-9, 1.2f, 9);
    ad.snowManData.ambient = 0.5f;

    //OBJECTのstaticメンバーに渡す
    ad.rotationCompletedFlags = 
        ad.cannonData.endOfRotationFlag |
        ad.satelliteData[0].endOfRotationFlag |
        ad.satelliteData[1].endOfRotationFlag;
    ad.flyingCompletedFlags = 1;

    //フォーメーション変更データ
    ad.formationData[0].cannonPos = ad.cannonData.pos;
    ad.formationData[0].satellitePos[0] = ad.satelliteData[0].pos;
    ad.formationData[0].satelliteAdvSpeed[0] = ad.satelliteData[0].advSpeed;
    ad.formationData[0].satellitePos[1] = ad.satelliteData[1].pos;
    ad.formationData[0].satelliteAdvSpeed[1] = ad.satelliteData[1].advSpeed;
    ad.formationData[0].enemyPos = ad.enemyData.pos;
    ad.formationData[0].bulletAdvSpeed = ad.bulletData.advSpeed;

    ad.formationData[1].cannonPos.set(-3, 0.8f, 6);
    ad.formationData[1].satellitePos[0].set(-3, 0.8f, 0);
    ad.formationData[1].satelliteAdvSpeed[0] = 0;
    ad.formationData[1].satellitePos[1].set(3, 0.8f, 0);
    ad.formationData[1].satelliteAdvSpeed[1] = 0;
    ad.formationData[1].enemyPos.set(3, 0.8f, 6);
    ad.formationData[1].bulletAdvSpeed = 0.1f;

    ad.formationData[2].cannonPos.set(-3, 0.8f, 0);
    ad.formationData[2].satellitePos[0].set(-3, 6.8f, 0);
    ad.formationData[2].satelliteAdvSpeed[0] = 0;
    ad.formationData[2].satellitePos[1].set(3, 6.8f, 0);
    ad.formationData[2].satelliteAdvSpeed[1] = 0;
    ad.formationData[2].enemyPos.set(3, 1.4f, 0);
    ad.formationData[2].bulletAdvSpeed = 0.1f;

#define TEST_
#ifdef TEST_A
    ad.cannonData.pos.set(-3, 0.8f, 6);
    ad.satelliteData[0].pos.set(-3, 0.8f, 0);
    ad.satelliteData[1].pos.set(3, 0.8f, 0);
    ad.enemyData.pos.set(3, 0.8f, 6);
    ad.satelliteData[0].advSpeed = 0;
    ad.satelliteData[1].advSpeed = 0;
    ad.bulletData.advSpeed = 0.1f;
#endif
#ifdef TEST_B
    ad.cannonData.pos.set(-3, 0.8f, 0);
    ad.satelliteData[0].pos.set(-3, 6.8f, 0);
    ad.satelliteData[1].pos.set(3, 6.8f, 0);
    ad.enemyData.pos.set(3, 1.4f, 0);
    ad.satelliteData[0].advSpeed = 0;
    ad.satelliteData[1].advSpeed = 0;
    ad.bulletData.advSpeed = 0.1f;
#endif
}