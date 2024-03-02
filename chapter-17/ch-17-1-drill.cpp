#include <iostream>
using namespace std;

ostream &print_array10(ostream &os, int *a) {
  int *a2 = a;
  for (int i = 0; i < 10; ++i) {
    os << *a++ << '|' << a2[i]
       << ' '; // Pointer arithmetic and indexing, respectively
  }

  return os;
}

ostream &print_array(ostream &os, int *a, int n) {
  while (n--) {
    os << *a++ << ' ';
  }

  return os;
}

ostream &print_vec(ostream &os, vector<int> vec) {
  for (const auto num : vec) {
    os << num << ' ';
  } 

  return os;
}

int main() {
  // Preamble...regular/static array
  int arr[4] = {5, 6, 7, 8};
  *arr = 0;
  *(arr + 1) = 1; // Static array with some pointer arithmetic

  // This works...for static arrays only
  for (const auto element : arr) {
    cout << element << '\n';
  }

  // 1)
  const int arr_len = 10;
  int *arr_dyn = new int[arr_len];
  arr_dyn[1] = 111;
  arr_dyn[2] = 222;

  // 2)
  cout << "=== 2 ===\n";
  // int array_size = sizeof(arr_dyn) / sizeof(arr_dyn[0]); // ERROR: this only
  // works on static arrays

  for (int i = 0; i < arr_len; ++i) {
    cout << arr_dyn[i] << '\n';
  }

  // 3)
  delete[] arr_dyn;

  // 4)
  cout << "=== 4 ===\n";
  int *arr10 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  arr10[2] = 22;
  print_array10(cout, arr10);
  delete[] arr10;

  // 5)
  cout << "\n=== 5 ===\n";
  int *arr_ten = new int[10]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
  print_array10(cout, arr_ten);
  delete[] arr_ten;

  // 6)
  int *arr11 =
      new int[11]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};

  // 7)
  cout << "\n=== 7 ===\n";
  print_array(cout, arr11, 11);
  delete[] arr11;

  // 8)
  cout << "\n=== 8 ===\n";
  int *arr20 = new int[20]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
  print_array(cout, arr20, 20);
  delete[] arr20;

  // 10) VECTOR
  cout << "\n=== 10 ===\n";
  vector<int> vec_10 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  print_vec(cout, vec_10);

  cout << '\n';
  vector<int> vec_11 {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
  print_vec(cout, vec_11);

  cout << '\n';
  vector<int> vec_20 {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119};
  print_vec(cout, vec_20);

  return 0;
} 
