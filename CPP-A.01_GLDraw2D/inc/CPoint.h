//
// Created by Raphael Laubscher on 16/04/16.
//

#ifndef CPP_CPOINT_H
#define CPP_CPOINT_H

class CPoint
{
private:
    float x;
    float y;
    static unsigned long ulCount;

public:
    CPoint();
    CPoint(float x, float y);
    CPoint(const CPoint& point);
    ~CPoint();
    void set(float x, float y);
    void list();
    static unsigned long listCount();
};

#endif //CPP_CPOINT_H
