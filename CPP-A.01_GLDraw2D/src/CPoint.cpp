//
// Created by Raphael Laubscher on 16/04/16.
//
#include <iostream>
#include "../inc/CPoint.h"

using namespace std;

unsigned long CPoint::ulCount = 0;

CPoint::CPoint(void) : x(0), y(0)
{
    ulCount++;
}

CPoint::CPoint(float x1, float y1) : x(x1), y(y1)
{
    ulCount++;
}

CPoint::CPoint(const CPoint& point) : x(point.x), y(point.y)
{
    ulCount++;
}

CPoint::~CPoint()
{
    ulCount--;
}

void CPoint::set(float x1, float y1)
{
    x = x1;
    y = y1;
}

void CPoint::list()
{
    cout << "(x: " << x << ", y: " << y << ")" << endl;
}

unsigned long CPoint::listCount()
{
    return ulCount;
}
