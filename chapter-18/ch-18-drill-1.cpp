#include <iostream>
using namespace std;

int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(const int (&arr)[10], int num) {
  int la[10];

  for (int i = 0; i < num; ++i) {
    la[i] = ga[i];
    cout << la[i] << ' ';
  }
  cout << '\n';

  int *p = new int[num];
  int *p2 = p;


  for (int i = 0; i < num; ++i) {
    *p = arr[i];
    cout << *p++ << ' ';
  }
  cout << '\n';

  delete[] p2;
}

int main() {
  f({1, 2, 4, 8, 16, 32, 64, 128, 256, 512}, 10);

  f(ga, 10);

  int aa[10] = {1};

  for (int fac=1, i=2; i < 11; ++i) {
    aa[i - 1] = fac *= i;
  }

  f(aa, 10);
}
