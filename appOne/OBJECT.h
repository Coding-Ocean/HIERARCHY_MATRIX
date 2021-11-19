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

//各オブジェクトが個別に呼び出すメンバ----------------------------------------
    //回転制御。指定した方向にゆっくり向ける。向き終わったらフラグを立てる
    int rotate(VECTOR* angle, const VECTOR& dir, float speed, int endOfRotationFlag=0);
    //弾が最終ターゲットに当たった時に呼び出してフラグを立てる
    void completeState();

//全オブジェクトで共用するメンバ----------------------------------------------
public:
    //全オブジェクトのステートを管理する
    static void objStateManager();
    //ステート開始時に「ステート終了と判断するためのフラッグ」を渡してリセット
    static void resetEndFlags(int completedFlags);
    //ステートが終わったかどうか判断できる
    static int endOfState();
    //Getter
    static OBJ_STATE objState();
    static int formationId();
private:
    static OBJ_STATE ObjState;
    //EndOfStateFlagsがCompletedFlagsと等しくなったらそのステートは終了
    static int EndOfStateFlags;
    static int CompletedFlags;
    //ステート開始時、resetEndFlags()のパラメタに設定するフラグ
    //(ここが難解すぎるが、今のところこれしか思いつかない)
    static int RotationCompletedFlags;
    static int FlyingCompletedFlags;
    //フォーメーション切り替えId
    static int FormationId;
};
