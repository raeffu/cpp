//
// Created by Raphael Laubscher on 16/04/16.
//
#include <iostream>
#include "../inc/CPoint.h"

#include <GL/glew.h>
#include <FL/glut.H>

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

CPoint CPoint::operator+(const CPoint& point)
{
  return CPoint(x + point.x, y + point.y);
}

CPoint CPoint::operator-(const CPoint& point)
{
  return CPoint(x - point.x, y - point.y);
}

void CPoint::draw()
{
  // cout << "DEBUG: CPoint::draw() x=" << x << " y=" << y << endl;

  // define the size of cross
  static const float crosslength = 5;

  // draw the cross using two lines
  glBegin(GL_LINES);
  glVertex2f(x - crosslength, y);
  glVertex2f(x + crosslength+1, y );
  glVertex2f(x, y - (crosslength+1));
  glVertex2f(x, y + crosslength);
  glEnd();
}