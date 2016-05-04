//
// Created by Raphael Laubscher on 16/04/16.
//

#include <iostream>
#include <cmath>
#include "../inc/CPoint.h"
#include "../inc/CCircle.h"

#include <GL/glew.h>
#include <FL/glut.H>

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

  // shift center of new circle on line between centers of the original circles
  float offsetX = (deltaX + abs(radius - circle.radius) * (deltaX/distance)) / 2;
  float offsetY = (deltaY + abs(radius - circle.radius) * (deltaY/distance)) / 2;
  float centerX = center.x - offsetX;
  float centerY = center.y - offsetY;
  tmp.center.set(centerX, centerY);

  return tmp;
}

void CCircle::draw()
{
  glPushMatrix();
  glTranslatef((GLfloat)center.x, (GLfloat)center.y, 0.0);
  gluDisk(gluNewQuadric(), radius, radius, 100, 1);
  glPopMatrix();
}