#include"mathUtil.h"
#include "OBJECT.h"



OBJECT::OBJECT(GAME* game)
    :GAME_POINTER(game)
{
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

int OBJECT::rotate(VECTOR* angle, const VECTOR& dir, float speed, int endOfRotationFlag)
{
    //‚w²‰ñ“]
    VECTOR b = normalize(dir);
    float angleBetweenX = -(acos(-b.y) - 1.57f) - angle->x;
    angle->x += angleBetweenX * speed;
    //‚x²‰ñ“]
    VECTOR a(sin(angle->y), 0, cos(angle->y));
    float dotProduct = a.x * b.x + a.z * b.z;
    float crossProduct = a.x * b.z - a.z * b.x;
    float angleBetweenY = atan2(-crossProduct, dotProduct);
    angle->y += angleBetweenY * speed;
    //‰ñ“]I—¹
    if (-0.02f < angleBetweenY && angleBetweenY <0.02f) {
        EndOfStateFlags |= endOfRotationFlag;
        return 1;
    }
    return 0;
}

//
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

//OBJ_STATE::FLY‚ªI—¹‚µ‚½‚Æ‚«‚Ég‚¤
void OBJECT::completeState()
{
    EndOfStateFlags = CompletedFlags;
}