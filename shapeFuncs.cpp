#include <iostream>
#include <string>
#include <sstream>  // for ostringstream
#include <iomanip> // for setprecision
#include <cmath>
#include "utility.h"

using namespace std;


#include "shapes.h"
#include "shapeFuncs.h"
#include "utility.h"


// Compute distance between two points

double distanceBetween(Point p, Point q) {
  return sqrt(pow(p.x - q.x, 2.0) + pow(p.y - q.y, 2.0));
  // HINTS: The distance formula is something you hopefully remember
  //   from H.S. algebra, but if not, Wikipedia is your friend.
  //   The sqrt function is available when you use #include <cmath>, 
  //   and pow(expresssion,2.0) will return expression squared.
  // You can access p.x, p.y, q.x and q.y and use those in your formula.

}

// The function initPoint below illustrates passing a struct by pointer.
// Inside this function:
//  p   is the address of the struct Point
// (*p) refers to the struct Point itself (we dereference the pointer)
// (*p).x refers to the x member of the point
// (*p).y refers to the y member of the point
// p->x is a shortcut for (*p).x ( -> means deference AND THEN go inside the struct)
// p->y is a shortcut for (*p).y ( -> means deference AND THEN go inside the struct)


void initPoint(struct Point *p, double xVal, double yVal) {
  p->x = xVal;
  p->y = yVal;
}


string pointToString(Point p, int precision) {
  ostringstream oss;
  oss << setprecision(precision); // set precision to 3 decimal places
  oss << "(" << p.x << "," << p.y << ")";
  return oss.str();
}

string boxToString(Box b, int precision) {
  ostringstream oss;
  oss << setprecision(precision);
  oss << "ul=";
  oss <<  pointToString(b.ul, precision);
  oss << ",w=";
  oss << b.width;
  oss << ",h=";
  oss << b.height;
  // SAMPLE FORMAT: [ul=(3.4,-5),w=5,h=7] (without the []s)
  return oss.str();
}
 


bool pointsApproxEqual(Point p1, 
		       Point p2, 
		       double tolerance) {
  // Two points are approximately equal if the distance between them
  // is less than our tolerance.  (If we want to test for 
  // exact equality, we can pass in a value of zero.)

  return distanceBetween(p1,p2) < tolerance;

}

bool boxesApproxEqual(Box b1, Box b2, double tolerance) {
  // Two boxes are approximately equal if their upper left corners are approximately 
  // equal, and if their corresponding widths and height are approx equal.

  // Remember: to test whether double values a and b are approximately equal, you need:
  //   fabs(a - b) < tol
  return pointsApproxEqual(b1.ul, b2.ul, tolerance)
    && approx_equal(b1.width, b2.width, tolerance)
    && approx_equal(b1.height, b2.height, tolerance);
}


// Now write a function to initialize a box.
// You'll need to initialize the upper left x and y,
// the width and the height.
// Note: there is a struct Point inside the struct Box.
// So here's a clue: For the x value, use (*b).ul.x or (b->ul).x 
//  The y value is similar.
// There is also a way to "reuse" initPoint, if you are feeling 
//  confident in your understanding of pointers and structs.

void initBox(struct Box *b, double ulx, double uly, double w, double h)
{
  Point p;
  initPoint(&p, ulx, uly);
  b->ul = p;
  b->width = w;
  b->height = h;
}


double areaOfBox(Box b) {
  return b.width * b.height;  /* stub---make sure all tests fail initially */
  // you can use b.width to access width, and b.height to access height
}
