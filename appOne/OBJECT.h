#pragma once
#include"VECTOR.h"
class OBJECT
{
public:
    virtual ~OBJECT();
    virtual int setup();
    virtual void update();
    virtual void draw();
    virtual int finished();
    virtual VECTOR pos();
    virtual VECTOR angle();
    int rotate(VECTOR* angle, const VECTOR& dir, float speed, int endOfRotationFlag=0);
    static void resetEndOfRotationFlags();
    static int endOfRotation();
private:
    static int EndOfRotationFlags;
};

