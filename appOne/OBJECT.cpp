#include"mathUtil.h"
#include "OBJECT.h"

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
    return Pos;
}

VECTOR OBJECT::angle()
{
    return Angle;
}

int OBJECT::rotate(const VECTOR& dir, float speed)
{
    //Çwé≤âÒì]
    VECTOR b = normalize(dir);
    float angleBetweenX = -(acos(-b.y) - 1.57f) - Angle.x;
    Angle.x += angleBetweenX * speed;
    //Çxé≤âÒì]
    VECTOR a(sin(Angle.y), 0, cos(Angle.y));
    float dotProduct = a.x * b.x + a.z * b.z;
    float crossProduct = a.x * b.z - a.z * b.x;
    float angleBetweenY = atan2(-crossProduct, dotProduct);
    Angle.y += angleBetweenY * speed;
    //âÒì]èIóπ
    if (-0.02f < angleBetweenY && angleBetweenY <0.02f) {
        return 1;
    }
    return 0;
}
