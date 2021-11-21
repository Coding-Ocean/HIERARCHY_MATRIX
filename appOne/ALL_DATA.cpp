#include "ALL_DATA.h"
void setAllData(ALL_DATA& ad)
{
    //window
    {
        ad.w = 1600;
        ad.h = 900;
        ad.fullScreenFlag = 1;
    }
    //camera
    {
        ad.cameraData.angle.set(0.32f, 0, 0);
        ad.cameraData.distance = 17;
        ad.cameraData.rotSpeed = 0.01f;
        ad.cameraData.zoomSpeed = 0.01f;
        ad.cameraData.targetIdx = 0;
        ad.cameraData.numTargets = 7;
        ad.cameraData.objId[0] = OBJ_ID::FLOOR;
        ad.cameraData.objId[1] = OBJ_ID::BULLET;
        ad.cameraData.objId[2] = OBJ_ID::SATELLITE1;
        ad.cameraData.objId[3] = OBJ_ID::SATELLITE2;
        ad.cameraData.objId[4] = OBJ_ID::ENEMY;
        ad.cameraData.objId[5] = OBJ_ID::SNOW_MAN;
        ad.cameraData.objId[6] = OBJ_ID::HUMAN;
    }
    //projector
    {
        ad.projectorData.fov = 0.785f;
        ad.projectorData.aspect = 1.7777777f;
        ad.projectorData.near_ = 0.1f;
        ad.projectorData.far_ = 100.0f;
    }
    //light
    {
        ad.lightData.pos.set(0, 1, 0);
    }
    //floor
    {
        ad.floorData.pos.set(0, 1, 0);//床の位置ではない。カメラルックアット座標。
        ad.floorData.range = 3;
        ad.floorData.scale = 3;
        ad.floorData.color[0].set(0, 0, 0);
        ad.floorData.color[1].set(80, 128, 80);
    }
    //cannon
    {
        ad.cannonData.pos.set(-6, 0, 6);
        ad.cannonData.offsetPos.set(0, 0.8f, 0);
        ad.cannonData.advSpeed = 0.05f;
        ad.cannonData.advRotSpeed = 0.25f;
        ad.cannonData.rotSpeed = 0.05f;
        ad.cannonData.rotBackSpeed = 0.025f;
        ad.cannonData.wheelColor.set(150, 0, 150);
        ad.cannonData.bodyColor.set(255, 150, 150);
        ad.cannonData.ambient = 0.3f;
        ad.cannonData.endOfRotationFlag = 0b0001;
        ad.cannonData.objId = OBJ_ID::SATELLITE1;
    }
    //bullet
    {
        ad.bulletData.radius = 0.3f;
        ad.bulletData.length = 1.1f;
        ad.bulletData.advSpeed = 0.2f;
        ad.bulletData.rotSpeed = 0.25f;
        ad.bulletData.collisionDistance = 0.6f;
        ad.bulletData.color.set(255, 0, 0);
        ad.bulletData.ambient = 0.5f;
        ad.bulletData.objId[0] = OBJ_ID::SATELLITE1;
        ad.bulletData.objId[1] = OBJ_ID::SATELLITE2;
        ad.bulletData.objId[2] = OBJ_ID::ENEMY;//最後のターゲットは変更できる
        ad.bulletData.objId[3] = OBJ_ID::SNOW_MAN;//最後のターゲットは変更できる
        ad.bulletData.objId[4] = OBJ_ID::HUMAN;//最後のターゲットは変更できる
        ad.bulletData.numTargets = 3;//最大８
    }
    //satellite
    {
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
        ad.satelliteData[1].bodyColor.set(0, 200,0);
        ad.satelliteData[1].squareColor.set(255, 200, 60);
        ad.satelliteData[1].ambient = 0.4f;
        ad.satelliteData[1].refAmbient = 0.6f;
        ad.satelliteData[1].animSpeed = 0.017f;
        ad.satelliteData[1].endOfRotationFlag = 0b0100;
    }
    //enemy
    {
        ad.enemyData.pos.set(6, 0, 6);
        ad.enemyData.offsetPosY = 1.2f;
        ad.enemyData.animSpeed = 0.017f;
        ad.enemyData.headColor.set(90, 90, 90);
        ad.enemyData.stickColor.set(255, 255, 255);
        ad.enemyData.ambient = 0.4f;
    }
    //snowman
    {
        ad.snowManData.pos.set(-9, 1.2f, 9);
        ad.snowManData.ambient = 0.5f;
    }
    //human
    {
        ad.humanData.pos.set(9, 0, 9);
        ad.humanData.animSpeed = 0.06f;
        ad.humanData.c1 = COLOR(62, 66, 163);
        ad.humanData.c2 = COLOR(217, 169, 132);
        ad.humanData.c3 = COLOR(0, 0, 0);
        ad.humanData.c4 = COLOR(255, 100, 100);
        ad.humanData.c5 = COLOR(220, 0, 0);
        ad.humanData.ambient = 0.7f;
    }
    //object
    {
        //OBJECTのstaticメンバーに渡す、ステート終了時状態のフラッグス
        ad.rotationCompletedFlags =
            ad.cannonData.endOfRotationFlag |
            ad.satelliteData[0].endOfRotationFlag |
            ad.satelliteData[1].endOfRotationFlag;
        ad.flyingCompletedFlags = 1;
    }
    //formation data
    {
        ad.formationData[0].cannonPos = ad.cannonData.pos;
        ad.formationData[0].satellitePos[0] = ad.satelliteData[0].pos;
        ad.formationData[0].satellitePos[1] = ad.satelliteData[1].pos;
        ad.formationData[0].enemyPos = ad.enemyData.pos;
        ad.formationData[0].bulletAdvSpeed = ad.bulletData.advSpeed;

        ad.formationData[1].cannonPos.set(-3, 0, 3);
        ad.formationData[1].satellitePos[0].set(-3, 0.8f, -3);
        ad.formationData[1].satellitePos[1].set(3, 0.8f, -3);
        ad.formationData[1].enemyPos.set(3, -0.4f, 3);
        ad.formationData[1].bulletAdvSpeed = 0.1f;

        ad.formationData[2].cannonPos.set(-3, 0, 0);
        ad.formationData[2].satellitePos[0].set(-3, 6.8f, 0);
        ad.formationData[2].satellitePos[1].set(3, 6.8f, 0);
        ad.formationData[2].enemyPos.set(3, 0, 0);
        ad.formationData[2].bulletAdvSpeed = 0.1f;
    }
}
