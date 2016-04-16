//
// Created by Raphael Laubscher on 16/04/16.
//

#include <iostream>
#include "../inc/CPoint.h"
#include "../inc/CCircle.h"

using namespace std;

unsigned long CCircle::ulCount = 0;

CCircle::CCircle() : center(), radius(0)
{
    ulCount++;
}

CCircle::CCircle(CPoint c, float r) : center(c), radius(r)
{
    ulCount++;
}

CCircle::CCircle(float x, float y, float r) : center(x, y), radius(r)
{
    ulCount++;
}

CCircle::CCircle(const CCircle& circle) : center(circle.center), radius(circle.radius)
{
    ulCount++;
}

CCircle::~CCircle()
{
    ulCount--;
}

void CCircle::set(CPoint c, float r)
{
    center = c;
    radius = r;
}

void CCircle::set(float x, float y, float r)
{
    center = CPoint(x, y);
    radius = r;
}

void CCircle::list()
{
    cout << "[" << endl << "  center: ";
    center.list();
    cout << "  radius: " << radius << endl << "]" << endl;
}

int CCircle::listCount()
{
    return ulCount;
}