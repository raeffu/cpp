//
// Created by Raphael Laubscher on 16/04/16.
//

#ifndef CPP_CCIRCLE_H
#define CPP_CCIRCLE_H

class CCircle
{
private:
    CPoint center;
    float radius;
    static unsigned long ulCount;

public:
    CCircle();
    CCircle(CPoint c, float r);
    CCircle(float x, float y, float r);
    CCircle(const CCircle& circle);
    ~CCircle();
    void set(CPoint c, float r);
    void set(float x, float y, float r);
    void list();
    static unsigned long listCount();
};

#endif //CPP_CCIRCLE_H
