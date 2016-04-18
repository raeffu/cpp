//
// Created by Raphael Laubscher on 08/04/16.
//

#include <iostream>

using namespace std;

#include "../inc/CPoint.h"
#include "../inc/CLine.h"
#include "../inc/CRect.h"
#include "../inc/CCircle.h"

CPoint p0;

int main()
{
    cout << CPoint::listCount();
    cin.get();
    // static instantiation of objects
    CPoint   P1;
    CLine    L1;
    CRect    R1;
    CCircle  C1;

    // definition of pointer to dynamic instantiated objects
    CPoint*   pP2;
    CLine*    pL2;
    CRect*    pR2;
    CCircle*  pC2;

    // dynamic instantiation of objects
    pP2 = new CPoint;
    pL2 = new CLine;
    pR2 = new CRect;
    pC2 = new CCircle;

    // set coordinates of objects
    P1.set( 1, 2 );
    pP2->set( 3, 4 );
    L1.set( 10, 10, 20, 20 );
    pL2->set( 30, 30, 40, 40 );
    R1.set( 100, 100, 200, 200 );
    pR2->set( 300, 300, 400, 400 );
    C1.set( 1000, 1000, 200 );
    pC2->set( 3000, 3000, 400 );

    // list coordinates of objects
    cout << "point object, defined with" << endl;
    cout << "   P at ";  P1.list(); cout << endl << endl;

    cout << "point object, defined with" << endl;
    cout << "   P at ";  pP2->list(); cout << endl << endl;

    cout << "line object, defined with" << endl;
    cout << "   P1, P2 at "; L1.list(); cout << endl << endl;

    cout << "line object, defined with" << endl;
    cout << "   P1, P2 at "; pL2->list(); cout << endl << endl;

    cout << "rectangle object, defined with" << endl;
    cout << "   P1, P2 at "; R1.list(); cout << endl << endl;

    cout << "rectangle object, defined with" << endl;
    cout << "   P1, P2 at "; pR2->list(); cout << endl << endl;

    cout << "circle object, defined with" << endl;
    cout << "   P1 at "; C1.list(); cout << endl << endl;

    cout << "circle object, defined with" << endl;
    cout << "   P1 at "; pC2->list(); cout << endl << endl;

    // explicit destroy of dynamic objects
    cout << "Deleting dynamic objects ..." << endl << endl;
    delete pP2;
    delete pL2;
    delete pR2;
    delete pC2;

    cout << endl << endl;

    CPoint p1;
    p1.list();
    p1.set(1.1, 2.2);
    p1.list();

    CPoint p2(2, 3);
    p2.list();

    CPoint p3(p2);
    p3.list();

    CPoint* p4 = new CPoint(1.5, 2.54);
    (*p4).list();

    cout << "CPoint count: " << CPoint::listCount() << endl;

    delete p4;

    cout << "deleted p4" << endl;
    cout << "CPoint count: " << CPoint::listCount() << endl;
    cout << endl;

    CLine l1;
    l1.list();
    l1.set(CPoint(111, 222), CPoint(333, 444));
    l1.list();
    l1.set(1.11, 2.22, 3.33, 4.44);
    l1.list();

    CLine l2(p1, p2);
    l2.list();

    CLine l3(1, 2, 3, 4);
    l3.list();

    CLine l4(l3);
    l4.list();

    CLine* l5 = new CLine(p3, (*p4));
    l5->list();

    cout << "CLine count: " << CLine::listCount() << endl;

    delete l5;
    cout << "deleted l5" << endl;
    cout << "CLine count: " << CLine::listCount() << endl;
    cout << endl;

    CRect r1;
    r1.list();
    CRect r2(r1);
    r2.list();
    r1.set(CPoint(1, 1), CPoint(2,2));
    r1.list();
    r1.set(3, 3, 4, 4);
    r1.list();

    cout << "CPoint counter: " << CPoint::listCount() << endl;

    cout << endl << endl;

    CCircle c1;
    c1.list();

    c1.set(CPoint(1, 1), 1.1);
    c1.list();

    CCircle c2(c1);
    c2.list();
    CCircle c3 = CCircle(CPoint(2, 2), 2.2);
    c3.list();

    return 0;
}