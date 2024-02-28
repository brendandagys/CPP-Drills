#include "my.h"
#include <iostream>
using namespace std;

int foo = 7;

int main() {
  //   print_foo();
  //   print(99);
  
  int x = 7;
  int y = 9;
  swap_r(x, y);
  //swap_r(7, 9);
  cout << "X: " << x << "\nY: " << y << '\n';
  
  const int cx = 7;
  const int cy = 9;
  //swap_r(cx, cy);
  //swap_r(7.7, 9.9);
  cout << "X: " << x << "\nY: " << y << '\n';

  return 0;
}
