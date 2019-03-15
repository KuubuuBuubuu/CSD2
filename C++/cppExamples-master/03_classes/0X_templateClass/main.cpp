#include <iostream>
using namespace std;

#include "Point.h"

int main() {
  int iX1 = 0;
  int iY1 = 0;
  Point <int> point1(iX1, iY1);

  int iX2 = 10;
  int iY2 = 5;
  Point <int> point2(iX2, iY2);

  cout <<  "\n\nThe distance between point1 (0,0) and point2 (10, 5) is: " <<
                point1.distance(point2) << endl;

  //end program
  return 0;
}
