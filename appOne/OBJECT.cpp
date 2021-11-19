#include "..\libOne\inc\input.h"
#include "mathUtil.h"
#include "GAME.h"
#include "OBJECT.h"

OBJECT::OBJECT(GAME* game)
    :GAME_POINTER(game)
{
    RotationCompletedFlags = game->allData()->rotationCompletedFlags;
    FlyingCompletedFlags = game->allData()->flyingCompletedFlags;;
}

OBJECT::~OBJECT()
{
}

int OBJECT::setup()
{
    return 0;
}

void OBJECT::update()
{
}

void OBJECT::draw()
{
}

VECTOR OBJECT::pos()
{
    return VECTOR();
}

VECTOR OBJECT::angle()
{
    return VECTOR();
}

//以下ステート変更関係------------------------------------------------------

//回転制御。指定した方向にゆっくり向ける。向き終わったら個別にフラグを立てる。
int OBJECT::rotate(
    VECTOR* angle, const VECTOR& dir, float rotSpeed, int endOfRotationFlag)
{
    //Ｘ軸回転
    VECTOR b = normalize(dir);
    float angleBetweenX = -(acos(-b.y) - 1.57f) - angle->x;
    angle->x += angleBetweenX * rotSpeed;
    //Ｙ軸回転
    VECTOR a(sin(angle->y), 0, cos(angle->y));
    float dotProduct = a.x * b.x + a.z * b.z;
    float crossProduct = a.x * b.z - a.z * b.x;
    float angleBetweenY = atan2(-crossProduct, dotProduct);
    angle->y += angleBetweenY * rotSpeed;
    //回転終了
    if (-0.02f < angleBetweenY && angleBetweenY <0.02f) {
        EndOfStateFlags |= endOfRotationFlag;
        return 1;
    }
    return 0;
}

//OBJ_STATE::FLYが終了したときに使う
void OBJECT::completeState()
{
    EndOfStateFlags = CompletedFlags;
}

//以下スタティックメンバ--------------------------------------------------
int OBJECT::EndOfStateFlags = 0;
int OBJECT::CompletedFlags = 0;

void OBJECT::resetEndFlags(int completedFlags)
{
    EndOfStateFlags = 0;
    CompletedFlags = completedFlags;
}

int OBJECT::endOfState()
{
    return EndOfStateFlags == CompletedFlags;
}

int OBJECT::RotationCompletedFlags = 0b111;
int OBJECT::FlyingCompletedFlags = 0b1;
OBJ_STATE OBJECT::ObjState = OBJ_STATE::MOVE;

void OBJECT::objStateManager()
{
    if (ObjState == OBJ_STATE::MOVE) {
        if (isTrigger(KEY_Z)) {
            OBJECT::resetEndFlags(RotationCompletedFlags);
            ObjState = OBJ_STATE::ROTATE;
        }
    }
    else if (ObjState == OBJ_STATE::ROTATE) {
        //全オブジェクトの回転が終了したら
        if (OBJECT::endOfState()) {
            OBJECT::resetEndFlags(FlyingCompletedFlags);
            ObjState = OBJ_STATE::FLY;
        }
    }
    else if (ObjState == OBJ_STATE::FLY) {
        //弾が最終ターゲットに到達したら
        if (OBJECT::endOfState()) {
            OBJECT::resetEndFlags(RotationCompletedFlags);
            ObjState = OBJ_STATE::ROTATE_BACK;
        }
    }
    else if (ObjState == OBJ_STATE::ROTATE_BACK) {
        //全オブジェクトの回転が終了したら
        if (OBJECT::endOfState()) {
            ObjState = OBJ_STATE::MOVE;
        }
    }
}

OBJ_STATE OBJECT::objState()
{
    return ObjState;
}