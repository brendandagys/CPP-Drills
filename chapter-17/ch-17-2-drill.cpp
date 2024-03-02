#include <iostream>

using namespace std;

ostream &print_array(ostream &os, int *a, int n) {
  while (n--) {
    os << *a++ << ' ';
  }

  return os;
}

int main() {
  // 1)
  int* i1 = new int(7);
  int *p1 = i1;

  // 2)
  cout << "=== 2 ===\n";
  cout << "Pointer address: " << p1 << " | Address value: " << *p1 << '\n';

  // 3)
  int* arr = new int[] {1, 2, 4, 8, 16, 32, 64};
  int *p2 = arr;

  // 4)
  cout << "=== 4 ===\n";
  cout << "Pointer address: " << p2 << " | Address values: ";
  print_array(cout, p2, 7);

  // 5)
  int *p3 = p2;

  // 6)
  p2 = p1;

  // 7)
  p2 = p3;

  // 8)
  cout << "\n=== 8 ===\n";
  cout << "P1 address: " << p1 << " | P1 value: " << *p1 << '\n';
  cout << "P2 address: " << p2 << " | P2 value: " << *p2;

  // 9)
  delete i1;
  delete[] arr;

  // 10)
  int* arr10 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
  p1 = arr10;

  // 11)
  int* arr10_2 = new int[10];
  p2 = arr10_2;

  // 12)
  int *p2_copy = p2;

  for (int i=0; i < 10; ++i) {
    *p2++ = *p1++;
  }
  
  cout << "\n=== 12 ===\n";
  print_array(cout, p2_copy, 10);

  // 13)
  vector<int> v1 {1, 2, 4, 8, 16, 32, 64, 128, 256, 512}; 
  vector<int> v2(10);

  for (int i=0; i < v2.size(); ++i) {
    v2[i] = v1[i];
  }

  cout << '\n';
  for (const auto el : v2) {
    cout << el << ' ';
  }

  return 0;
}
