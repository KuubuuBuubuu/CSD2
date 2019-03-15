#include <cmath>

template <class T>
class Point {
public:
  Point(T x, T y);
  T distance(Point<T> point);
  T x;
  T y;
};

template <class T>
Point<T>::Point(T x, T y){
  this->x = x;
  this->y = y;
}

template <class T>
T Point<T>::distance(Point<T> point){
  T deltaX = point.x - x;
  T deltaY = point.y - y;
  T delta = sqrt((deltaX * deltaX) + (deltaY * deltaY));
  return delta;
}
