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

//�e�I�u�W�F�N�g���ʂɌĂяo�������o----------------------------------------
    //��]����B�w�肵�������ɂ�����������B�����I�������t���O�𗧂Ă�
    int rotate(VECTOR* angle, const VECTOR& dir, float speed, int endOfRotationFlag=0);
    //�e���ŏI�^�[�Q�b�g�ɓ����������ɌĂяo���ăt���O�𗧂Ă�
    void completeState();

//�S�I�u�W�F�N�g�ŋ��p���郁���o----------------------------------------------
public:
    //�S�I�u�W�F�N�g�̃X�e�[�g���Ǘ�����
    static void objStateManager();
    //�X�e�[�g�J�n���Ɂu�X�e�[�g�I���Ɣ��f���邽�߂̃t���b�O�v��n���ă��Z�b�g
    static void resetEndFlags(int completedFlags);
    //�X�e�[�g���I��������ǂ������f�ł���
    static int endOfState();
    //Getter
    static OBJ_STATE objState();
    static int formationId();
private:
    static OBJ_STATE ObjState;
    //EndOfStateFlags��CompletedFlags�Ɠ������Ȃ����炻�̃X�e�[�g�͏I��
    static int EndOfStateFlags;
    static int CompletedFlags;
    //�X�e�[�g�J�n���AresetEndFlags()�̃p�����^�ɐݒ肷��t���O
    //(��������������邪�A���̂Ƃ��낱�ꂵ���v�����Ȃ�)
    static int RotationCompletedFlags;
    static int FlyingCompletedFlags;
    //�t�H�[���[�V�����؂�ւ�Id
    static int FormationId;
};
