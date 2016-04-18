//
// Created by Raphael Laubscher on 16/04/16.
//

#ifndef CPP_CLINE_H
#define CPP_CLINE_H

class CLine
{
private:
    CPoint p1;
    CPoint p2;
    static unsigned long ulCount;

public:
    CLine();
    CLine(CPoint start, CPoint end);
    CLine(float x1, float y1, float x2, float y2);
    CLine(const CLine& line);
    ~CLine();
    void set(CPoint, CPoint);
    void set(float x1, float y1, float x2, float y2);
    void list();
    static unsigned long listCount();
};

#endif //CPP_CLINE_H
