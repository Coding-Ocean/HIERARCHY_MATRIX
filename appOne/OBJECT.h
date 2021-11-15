#pragma once
#include"VECTOR.h"
class OBJECT
{
protected:
    VECTOR Pos;
    VECTOR Angle;
public:
    virtual ~OBJECT();
    virtual int create();
    virtual void update();
    virtual void draw();

    virtual int finished();
    int rotate(const VECTOR& b, float speed);
    VECTOR pos();
    VECTOR angle();
};

