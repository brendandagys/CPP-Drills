#include <iostream>
#include <string>
using namespace std;

struct X {
  int val;

  void out(const string &s) {
    cerr << this << "-> " << s << ": " << val << '\n';
  }

  X() {
    out("X()");
    val = 0;
  } // Default constructor

  explicit X(int v) {
    out("X(int)");
    val = v;
  }

  X(const X &x) {
    out("X(X&)");
    val = x.val;
  } // Copy constructor

  X &operator=(const X &a) {
    out("X::operator=()");
    val = a.val;
    return *this;
  } // Copy assignment

  ~X() { out("~X()"); }
};

X glob(2);

X copy(X a) { return a; }

X copy2(X a) {
  X aa = a;
  return aa;
}

X &ref_to(X &a) { return a; }

X *make(int i) {
  X a(i);
  return new X(a);
}

struct XX {
  X a;
  X b;
};

int main() {
  cout << "\n=== 1 ===\n";
  X loc(4);
  cout << "\n=== 2 ===\n";
  X loc2 = loc;
  cout << "\n=== 3 ===\n";
  loc = X(5);
  cout << "\n=== 4 ===\n";
  loc2 = copy(loc);
  cout << "\n=== 5 ===\n";
  loc2 = copy2(loc);
  cout << "\n=== 6 ===\n";
  X loc3(6);
  cout << "\n=== 7 ===\n";
  X &r = ref_to(loc);
  cout << "\n=== 8 ===\n";
  delete make(7);
  cout << "\n=== 9 ===\n";
  delete make(8);
  cout << "\n=== 10 ===\n";
  vector<X> v(4);
  cout << "\n=== 11 ===\n";
  XX loc4;
  cout << "\n=== 12 ===\n";
  X* p = new X(9);
  cout << "\n=== 13 ===\n";
  delete p;
  cout << "\n=== 14 ===\n";
  X* pp = new X[5];
  cout << "\n=== 15 ===\n";
  delete[] pp;
  cout << "\n=== OWN TEST ===\n";
  X loc5;
  loc5 = X(loc3);
  cout << "\n=== OWN TEST with `new` ===\n";
  X loc6;
  loc6 = X(loc3);
  cout << "\n=== PROGRAM END ===\n";

  return 0;
}
