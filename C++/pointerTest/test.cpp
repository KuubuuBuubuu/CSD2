#include <iostream>
#include <math.h>
using namespace std;

int ans;
void pwr(int *x, int *y) {
  ans = pow(*x , *y);
};

int main() {
  int a;
  cout << "What's your starting number?" << endl;
  cin >> a;
  int b;
  cout << "What is the power-number?" << endl;
  cin >> b;

  pwr(&a, &b);
  cout << a << " ^ " << b << " = " << ans << endl;
}
