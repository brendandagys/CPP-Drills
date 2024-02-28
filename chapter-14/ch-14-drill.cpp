
#include <iostream>
using namespace std;

class B1 {
public:
  virtual void vf() { cout << "B1::vf()\n"; };
  void f() { cout << "B1::f()\n"; };
  virtual void pvf() = 0; // 5)
};

class D1 : public B1 {
public:
  void vf() { cout << "D1::vf()\n"; };
  void f() {
    cout << "D1::f()\n";
  }; // 4) - Added this and re-ran 1) - 3)
     // B1 calls its own
     // D1 calls its own (one override, one local)
     // B1& calls first overridden virtual function; `f()` isn't overridden
  void pvf(){};
};

class D2 : public D1 {
public:
  void pvf() { cout << "D2::pvf()\n"; };
};

class B2 {
public:
  virtual void pvf() = 0;
};

class D21 : public B2 {
public:
  void pvf() { cout << "D21::pvf(): " << str << '\n'; };

private:
  string str = "D21 string";
};

class D22 : public B2 {
public:
  void pvf() { cout << "D22::pvf(): " << integer << '\n'; };

private:
  int integer = 7;
};

void f(B2 &b) { b.pvf(); }

int main() {
  // 1) - Calls `B1`'s member functions
  //  B1 b;
  //  cout << "\nCalling B1::vf():\n";
  //  b.vf();
  //
  //  cout << "\nCalling B1::f():\n";
  //  b.f();

  // 2) - The virtual function alone is overridden
  D1 d;

  cout << "\nCalling D1::vf():\n";
  d.vf();

  cout << "\nCalling D1::f():\n";
  d.f();

  // 3) - Prints the same as `d` because it's a reference to `d`
  B1 &b_ref = d;

  cout << "\nCalling &B1::vf():\n";
  b_ref.vf();

  cout << "\nCalling &B1::f():\n";
  b_ref.f();

  // 6)
  D2 d2;

  cout << "\nCalling D2::vf():\n";
  d2.vf();

  cout << "\nCalling D2::f():\n";
  d2.f();

  cout << "\nCalling D2::pvf():\n";
  d2.pvf();

  // 7)
  D21 d21;
  D22 d22;

  f(d21);
  f(d22);

  return 0;
}
