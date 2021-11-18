#pragma once
#include"GAME_POINTER.h"
#include "OBJ_ID.h"
#include "OBJ_STATE.h"
#include"VECTOR.h"
class OBJECT
    :public GAME_POINTER
{
public:
    OBJECT(class GAME* game);
    virtual ~OBJECT();
    virtual int setup();
    virtual void update();
    virtual void draw();
    virtual VECTOR pos();
    virtual VECTOR angle();

    //OBJ_STATE�Ɋ֌W���郁���o-----------------------------------------------
    //��]����B�w�肵�������ɂ�����������B��������t���O�𗧂Ă�
    int rotate(VECTOR* angle, const VECTOR& dir, float speed, int endOfRotationFlag=0);
    //OBJ_STATE::FLY���I�������Ƃ��ɌĂяo��
    void completeState();

    //�����̃I�u�W�F�N�g���S�ĉ�]�I���������`�F�b�N������A
    //�e����яI��������ǂ����`�F�b�N����
    static void resetEndFlags(int completedFlags);
    static int endOfState();
private:
    static int EndOfStateFlags;
    static int CompletedFlags;
};

