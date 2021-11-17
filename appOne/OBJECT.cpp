#include"mathUtil.h"
#include "OBJECT.h"

int OBJECT::EndOfRotationFlags = 0;

void OBJECT::resetEndOfRotationFlags() {
    EndOfRotationFlags = 0;
}

int OBJECT::endOfRotation()
{
    return EndOfRotationFlags == 0b0111;
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

int OBJECT::finished()
{
    return 0;
}

VECTOR OBJECT::pos()
{
    return VECTOR();
}

VECTOR OBJECT::angle()
{
    return VECTOR();
}

int OBJECT::rotate(VECTOR* angle, const VECTOR& dir, float speed)
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
        return 1;
    }
    return 0;
}
