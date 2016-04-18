//
// Created by Raphael Laubscher on 16/04/16.
//

#ifndef CPP_CRECTANGLE_H
#define CPP_CRECTANGLE_H

#include "CPoint.h"

class CRect
{
private:
    CPoint topLeft;
    CPoint bottomRight;
    static unsigned long ulCount;

public:
    CRect();
    CRect(CPoint tl, CPoint br);
    CRect(float x1, float y1, float x2, float y2);
    CRect(const CRect& rectangle);
    ~CRect();
    void set(CPoint tl, CPoint br);
    void set(float x1, float y1, float x2, float y2);
    void list();
    static unsigned long listCount();
};

#endif //CPP_CRECTANGLE_H
