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

//OBJ_STATEに関係するメンバ-----------------------------------------------
public:
    //各オブジェクトが個別に呼び出す回転ルーチン。
    //指定した方向にゆっくり向ける。
    //向き終わったらフラグを立てる。
    int rotate(
        VECTOR* angle, const VECTOR& dir, float speed, int endOfRotationFlag=0);
    //弾が最終ターゲットに当たった時に呼び出すルーチン。
    void completeState();

    //ステート開始時に「ステート終了と判断するためのフラッグ」を渡してリセット
    static void resetEndFlags(int completedFlags);
    //ステートが終わったかどうか判断できる
    static int endOfState();
private:
    //EndOfStateFlagsがCompletedFlagsと等しくなったらそのステートは終了
    static int EndOfStateFlags;
    static int CompletedFlags;
    //CompletedFlagsにステート開始時に設定する。
    //(ここが難解すぎるが、今のところこれしか思いつかない)
    static int RotationCompletedFlags;
    static int FlyingCompletedFlags;
};
