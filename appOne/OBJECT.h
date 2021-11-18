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

    //OBJ_STATEに関係するメンバ-----------------------------------------------
    //回転制御。指定した方向にゆっくり向ける。向いたらフラグを立てる
    int rotate(VECTOR* angle, const VECTOR& dir, float speed, int endOfRotationFlag=0);
    //OBJ_STATE::FLYが終了したときに呼び出す
    void completeState();

    //複数のオブジェクトが全て回転終了したかチェックしたり、
    //弾が飛び終わったかどうかチェックする
    static void resetEndFlags(int completedFlags);
    static int endOfState();
private:
    static int EndOfStateFlags;
    static int CompletedFlags;
};

