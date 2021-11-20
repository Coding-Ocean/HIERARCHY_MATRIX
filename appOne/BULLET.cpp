#include "GAME.h"
#include "BULLET.h"

BULLET::BULLET(GAME* game)
    :OBJECT(game)
{
}

BULLET::~BULLET()
{
    SAFE_DELETE(Cone);
    SAFE_DELETE_ARRAY(Targets);
}

int BULLET::setup()
{
    //Data
    Data = game()->allData()->bulletData;
    //���́u�|�C���^�z��v�̏��ɒe���΂�
    Targets = new OBJECT * [Data.numTargets];
    for (int i = 0; i < Data.numTargets; i++) {
        Targets[i] = game()->object(Data.objId[i]);
    }

    //Model
    Cone = new CONE(36, Data.radius, Data.length);

    return 0;
}

void BULLET::update()
{
    if (objState() == OBJ_STATE::MOVE) {
        if (isTrigger(KEY_X)) {
            int id = formationId();
            const FORMATION_DATA& fd = game()->allData()->formationData[id];
            Data.advSpeed = fd.bulletAdvSpeed;
        }
        //�L���m���̈ʒu�Ɗp�x���R�s�[
        Data.pos = game()->object(OBJ_ID::CANNON)->pos();
        Data.angle = game()->object(OBJ_ID::CANNON)->angle();
    }

    if (objState() == OBJ_STATE::ROTATE) {
        //�L���m���̊p�x���R�s�[
        Data.angle = game()->object(OBJ_ID::CANNON)->angle();
        TargetNo = 0;
    }

    if (objState() == OBJ_STATE::FLY) {
        if (TargetNo < Data.numTargets) {
            //���݂̃^�[�Q�b�g�Ɍ������ĉ�]���Ȃ���ړ�
            VECTOR dir = Targets[TargetNo]->pos() - Data.pos;
            float distance = dir.mag();
            Data.pos += dir.normalize() * Data.advSpeed;
            rotate(&Data.angle, dir, Data.rotSpeed);
            //���������̂Ŏ��̃^�[�Q�b�g��
            if (distance < Data.collisionDistance) {
                TargetNo++;
            }
        }
        else {
            completeState();
        }
    }

    Master.translate(Data.pos.x, Data.pos.y, Data.pos.z);
    Master.mulRotateY(Data.angle.y);
    Master.mulRotateX(Data.angle.x);
}

void BULLET::draw()
{
    Cone->draw(Master, Data.color, Data.ambient);
}

VECTOR BULLET::pos()
{
    return Data.pos;
}
