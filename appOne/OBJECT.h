#pragma once
#include"VECTOR.h"
class OBJECT
{
protected:
    VECTOR Pos;
    VECTOR Angle;
public:
    virtual ~OBJECT();
    virtual void update();
    virtual void draw();
    VECTOR pos();
    VECTOR angle();
    float angleBetweenX(const VECTOR& b);
    float angleBetweenY(const VECTOR& b);
    int rotate(const VECTOR& b, float speed);
};

