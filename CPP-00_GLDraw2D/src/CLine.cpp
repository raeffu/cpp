//
// Created by Raphael Laubscher on 16/04/16.
//

#include <iostream>
#include "../inc/CPoint.h"
#include "../inc/CLine.h"

#include <GL/glew.h>
#include <FL/glut.H>

using namespace std;

unsigned long CLine::ulCount = 0;

CLine::CLine() : p1(), p2()
{
  ulCount++;
}

CLine::CLine(CPoint start, CPoint end) : p1(start), p2(end)
{
  ulCount++;
}

CLine::CLine(float x1, float y1, float x2, float y2) : p1(x1, y1), p2(x2, y2)
{
  ulCount++;
}

CLine::CLine(const CLine& line) : p1(line.p1), p2(line.p2)
{
  ulCount++;
}

CLine::~CLine()
{
  ulCount--;
}

void CLine::set(CPoint start, CPoint end)
{
  p1 = start;
  p2 = end;
}

void CLine::set(float x1, float y1, float x2, float y2)
{
  p1 = CPoint(x1, y1);
  p2 = CPoint(x2, y2);
}

void CLine::list()
{
  cout << "[" << endl << "  A: ";
  p1.list();
  cout << "  B: ";
  p2.list();
  cout << "]" << endl;
}

unsigned long CLine::listCount()
{
  return ulCount;
}

CLine& CLine::operator=(const CLine& line)
{
  p1 = line.p1;
  p2 = line.p2;
  return *this;
}

CLine CLine::operator+(const CLine& line)
{
  CLine tmp;
  tmp.p1 = p1;
  tmp.p2 = p2 + line.p2 - line.p1;
  return tmp;
}

void CLine::draw()
{
  glBegin(GL_LINES);
  glVertex2f(p1.x, p1.y);
  glVertex2f(p2.x, p2.y);
  glEnd();
}

