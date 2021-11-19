#pragma once
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
#include "FORMATION_DATA.h"

struct ALL_DATA {
    float w, h;
    int windowFlag;
    CAMERA::DATA cameraData;
    PROJECTOR::DATA projectorData;
    LIGHT::DATA lightData;
    FLOOR::DATA floorData;
    CANNON::DATA cannonData;
    BULLET::DATA bulletData;
    SATELLITE::DATA satelliteData[2];
    ENEMY::DATA enemyData;
    SNOW_MAN::DATA snowManData;
    HUMAN::DATA humanData;
    //OBJECTのstaticメンバーに渡すデータ
    int rotationCompletedFlags;
    int flyingCompletedFlags;
    //フォーメーションデータ
    FORMATION_DATA formationData[3];
};

void setAllData(ALL_DATA& allData);