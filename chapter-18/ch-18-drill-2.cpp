#include <iostream>
#include <vector>
using namespace std;

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> vec) {
  vector<int> lv(vec.size());
  lv = gv;

  for (int el : lv) {
    cout << el << ' ';
  }
  cout << '\n';

  vector<int> lv2 = vec;

  for (int el : lv2) {
    cout << el << ' ';
  }
  cout << '\n';
}

int main() {
  // f(vector<int>(10));
  cout << "=== GLOBAL ===\n";
  f(gv);

  cout << "=== VECTOR ===\n";
  vector<int> vv(10);

  for (int fact = 1, i = 1; i <= vv.size(); ++i) {
    vv[i - 1] = fact *= i;
  }

  f(vv);
}
