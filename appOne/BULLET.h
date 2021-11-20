#pragma once
#include "OBJECT.h"
#include "CONE.h"
class BULLET :
    public OBJECT
{
//Functions
public:
    BULLET(class GAME* game);
    ~BULLET();
    int setup();
    void update();
    void draw();
    VECTOR pos();
//DATA
public:
    struct DATA {
        VECTOR pos;
        VECTOR angle;
        float radius;
        float length;
        float advSpeed;
        float rotSpeed;
        int numTargets;
        OBJ_ID objId[8];//�R�����g���Ă��Ȃ�
        float collisionDistance;
        COLOR color;
        float ambient;
    };
private:
    //Data
    DATA Data;
    OBJECT** Targets;//�S�^�[�Q�b�g�̔z��
    int TargetNo = 0;//���������Ă���^�[�Q�b�g
    //Model
    CONE* Cone;
    //Matrix
    MATRIX Master;
};
