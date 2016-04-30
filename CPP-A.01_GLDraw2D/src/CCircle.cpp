//
// Created by Raphael Laubscher on 16/04/16.
//

#include <iostream>
#include <cmath>
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

unsigned long CCircle::listCount()
{
  return ulCount;
}

CCircle CCircle::operator+(const CCircle& circle)
{
  CCircle tmp;
  // get new radius
  float deltaX = center.x - circle.center.x;
  float deltaY = center.y - circle.center.y;
  float distance = (float) sqrt(pow(deltaX, 2) + pow(deltaY, 2));
  tmp.radius = (radius + distance + circle.radius) / 2;

  // get new center
  float centerX = center.x - deltaX;
  float centerY = center.y - deltaY;
  tmp.center.set(centerX, centerY);

  return tmp;
}