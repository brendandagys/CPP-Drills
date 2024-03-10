#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
using namespace std;

// 5
void increase_p(int *p, int n, int amount) {

  for (int i = 0; i < n; ++i) {
    *(p + i) += amount;
  }
}

template <class Iterator> void increase_i(Iterator b, Iterator e, int amount) {
  while (b != e) {
    *b += amount;
    b++;
  }
}

template <class Iterator> void print_i(Iterator b, Iterator e, string name) {
  cout << "\n" << name << ':';
  while (b != e) {
    cout << ' ' << *b++;
  }
}

template <class Container> void print(const Container &c, string name) {
  cout << "\n" << name << ':';
  for (const auto &el : c) { // Or `const typename Container::value_type`
    cout << ' ' << el;
  }
}

template <class Iterator1, class Iterator2>
void my_copy(Iterator1 f1, Iterator1 b1, Iterator2 f2) {
  while (f1 != b1) {
    *f2++ = *f1++;
  }
}

int main() {
  // 1 - 3
  int arr[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<int> l{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // 4
  int size = sizeof(arr) / sizeof(arr[0]);
  int arr2[sizeof(arr) / sizeof(arr[0])];
  for (int i = 0; i < size; ++i) {
    arr2[i] = arr[i];
  }

  vector<int> vec2 = vec;
  list<int> l2 = l;

  print(arr, "ARRAY");
  print(vec, "VECTOR");
  print(l, "LIST");

  // 5
  increase_p(arr2, size, 2);
  increase_p(vec2.data(), vec2.size(), 3);
  // Can't use pointer version for `list`; elements aren't contiguous

  cout << '\n';
  print(arr2, "ARRAY 2");
  print(vec2, "VECTOR 2");

  increase_i(arr2, arr2 + size, 2);
  increase_i(vec2.begin(), vec2.end(), 3);
  increase_i(l2.begin(), l2.end(), 5);

  cout << '\n';
  print(arr2, "ARRAY 2");
  print(vec2, "VECTOR 2");
  print(l2, "LIST 2");

  transform(begin(arr), end(arr), begin(arr), [](int x) { return x + 2; });
  transform(vec.begin(), vec.end(), vec.begin(), [](int x) { return x + 3; });
  transform(l.begin(), l.end(), l.begin(), [](int x) { return x + 5; });

  cout << '\n';
  print(arr, "ARRAY");
  print(vec, "VECTOR");
  print(l, "LIST");

  // 7
  cout << "\n\n=== 7 ===";
  // arr[0] = 99; // Confirm the vector and array were copied into
  my_copy(arr, arr + size, vec.begin());
  print(vec, "VECTOR");
  my_copy(l.begin(), l.end(), arr);
  print(arr, "ARRAY");
  print(l, "LIST");

  // 8
  cout << "\n\n=== 8 ===";
  auto res = find(vec.begin(), vec.end(), 3);
  bool found = res != vec.end();
  if (found) {
    cout << "\nVector has `3`: " << distance(vec.begin(), res) << '\n';
  } else {
    cout << "\nVector doesn't have the value 3.\n";
  }

  auto res2 = find(l.begin(), l.end(), 27);
  found = res2 != l.end();
  if (found) {
    cout << "\nList has `3` at index " << distance(l.begin(), res2) << '\n';
  } else {
    cout << "\nList doesn't have the value 27.\n";
  }
}
