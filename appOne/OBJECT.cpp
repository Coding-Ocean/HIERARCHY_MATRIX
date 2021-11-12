#include"mathUtil.h"
#include "OBJECT.h"

OBJECT::~OBJECT()
{
}

void OBJECT::update()
{
}

void OBJECT::draw()
{
}

VECTOR OBJECT::pos()
{
    return Pos;
}

VECTOR OBJECT::angle()
{
    return Angle;
}

float OBJECT::angleBetweenX(const VECTOR& b)
{
    return -(acos(-b.y) - 1.57f) - Angle.x;
}

float OBJECT::angleBetweenY(const VECTOR& b)
{
    VECTOR a(sin(Angle.y), 0, cos(Angle.y));
    float dotProduct = a.x * b.x + a.z * b.z;
    float crossProduct = a.x * b.z - a.z * b.x;
    return atan2(-crossProduct, dotProduct);
}

int OBJECT::rotate(const VECTOR& dir, float speed)
{
    //‚wŽ²‰ñ“]
    VECTOR b = normalize(dir);
    Angle.x += angleBetweenX(b) * speed;
    //‚xŽ²‰ñ“]
    float angle_y = angleBetweenY(b);
    Angle.y += angle_y * speed;
    //return rotation finished
    if (absolute(angle_y) < 0.001f) {
        return 1;
    }
    return 0;
}

