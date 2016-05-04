//
// Created by Raphael Laubscher on 16/04/16.
//

#ifndef CPP_CPOINT_H
#define CPP_CPOINT_H

class CPoint
{

  friend class CLine;
  friend class CRect;
  friend class CCircle;

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
  void draw( void );
  static unsigned long listCount();

  CPoint operator+(const CPoint& point);
  CPoint operator-(const CPoint& point);
};

#endif //CPP_CPOINT_H
