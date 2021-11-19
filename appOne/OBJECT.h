#pragma once
#include"VECTOR.h"
#include"GAME_POINTER.h"
#include "OBJ_ID.h"
#include "OBJ_STATE.h"
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

//Object state control----------------------------------------------------
public:
    static OBJ_STATE objState();
    static void objStateManager();
private:
    static OBJ_STATE ObjState;

//OBJ_STATE�Ɋ֌W���郁���o-----------------------------------------------
public:
    //�e�I�u�W�F�N�g���ʂɌĂяo����]���[�`���B
    //�w�肵�������ɂ�����������B
    //�����I�������t���O�𗧂Ă�B
    int rotate(
        VECTOR* angle, const VECTOR& dir, float speed, int endOfRotationFlag=0);
    //�e���ŏI�^�[�Q�b�g�ɓ����������ɌĂяo�����[�`���B
    void completeState();

    //�X�e�[�g�J�n���Ɂu�X�e�[�g�I���Ɣ��f���邽�߂̃t���b�O�v��n���ă��Z�b�g
    static void resetEndFlags(int completedFlags);
    //�X�e�[�g���I��������ǂ������f�ł���
    static int endOfState();
private:
    //EndOfStateFlags��CompletedFlags�Ɠ������Ȃ����炻�̃X�e�[�g�͏I��
    static int EndOfStateFlags;
    static int CompletedFlags;
    //CompletedFlags�ɃX�e�[�g�J�n���ɐݒ肷��B
    //(��������������邪�A���̂Ƃ��낱�ꂵ���v�����Ȃ�)
    static int RotationCompletedFlags;
    static int FlyingCompletedFlags;
};
