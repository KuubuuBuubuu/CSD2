#include <iostream>

/* This example contains ...
 * TODO - add info
 * TODO - add HANDSON-TIPS
 * • remove the & in front of funciton addOne parameter 'aNumber'.
 *    What do you expect to happen?
 * • 
 */

void addOne(int &aNumber) {
  aNumber++;
}

int main() {
  int x = 0;

  std::cout << "Starting with integer x, value: " << x << std::endl;

  addOne(x);

  std::cout << "After calling the function 'addOne(x)' -> x, value: " <<
                x << std::endl;
}
