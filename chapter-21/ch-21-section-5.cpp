#include <array>
#include <functional>
#include <vector>
// #include <numeric> // For built-in `accumulate`
using namespace std;

template <class In, class T> T accumulate(In first, In last, T init) {
  while (first != last) {
    init += *first;
    ++first;
  }
  return init;
}

template <class In, class T, class Op> // `Op` here is a 'binary operator'
T accumulate(In first, In last, T init, Op op) {
  while (first != last) {
    init = op(init, *first);
    ++first;
  }
  return init;
}

void f(vector<double> &vd, int *p, int n) {
  double sum_with_vector = accumulate(vd.begin(), vd.end(), 0.0);
  int sum_with_array = accumulate(p, p + n, 0);
}

struct Record {
  double unit_price;
  int units;
};

double price(double v, const Record &r) { return v + r.unit_price * r.units; }

// Use a function unless: you must store a value between calls, or the function
// object is so short that inlining makes a difference
void f2(const vector<Record> &vr) {
  double total = accumulate(vr.begin(), vr.end(), 0.0, price);
}

template <class In, class In2,
          class T> // The 2 sequences need not be of the same type
T inner_product(In first, In last, In2 first2, T init) {
  while (first != last) {
    init += (*first) * (*first2);
    ++first;
    ++first2;
  }
  return init;
}

template <class In, class In2, class T, class Op, class Op2>
T inner_product(In first, In last, In2 first2, T init, Op op, Op2 op2) {
  while (first != last) {
    init = op(init, op2(*first, *first2));
    ++first;
    ++first2;
  }
  return init;
}

int main() {
  int a[] = {1, 2, 3, 4, 5};
  int res = accumulate<int *, int>(a, a + sizeof(a) / sizeof(int), 0);

  array<double, 4> a2 = {1.1, 2.2, 3.3, 4.4};
  res = accumulate(a2.begin(), a2.end(), 1.0, multiplies<double>());
}
