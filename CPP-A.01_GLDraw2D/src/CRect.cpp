//
// Created by Raphael Laubscher on 16/04/16.
//

#include <iostream>
#include "../inc/CPoint.h"
#include "../inc/CRect.h"

using namespace std;

unsigned long CRect::ulCount = 0;

CRect::CRect() : topLeft(), bottomRight()
{
    ulCount++;
}

CRect::CRect(CPoint tl, CPoint br) : topLeft(tl), bottomRight(br)
{
    ulCount++;
}

CRect::CRect(float x1, float y1, float x2, float y2) : topLeft(x1, y1), bottomRight(x2, y2)
{
    ulCount++;
}

CRect::CRect(const CRect& rectangle)
        : topLeft(rectangle.topLeft), bottomRight(rectangle.bottomRight)
{
    ulCount++;
}

CRect::~CRect()
{
    ulCount--;
}

void CRect::set(CPoint tl, CPoint br)
{
    topLeft = tl;
    bottomRight = br;
}

void CRect::set(float x1, float y1, float x2, float y2)
{
    topLeft = CPoint(x1, y1);
    bottomRight = CPoint(x2, y2);
}

void CRect::list()
{
    cout << "[" << endl << "  topLeft: ";
    topLeft.list();
    cout << "  bottomRight: ";
    bottomRight.list();
    cout << "]" << endl;
}

int CRect::listCount()
{
    return ulCount;
}