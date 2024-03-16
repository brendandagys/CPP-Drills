#include <list>
#include <string>
#include <vector>
using namespace std;

template <class In, class T> In my_find(In first, In last, const T &val) {
  while (first != last && *first != val)
    ++first;
  return first;
}

template <class In, class Pred> In my_find_if(In first, In last, Pred pred) {
  while (first != last && !pred(*first))
    ++first;
  return first;
}

void f(vector<int> &v, int x) {
  vector<int>::iterator p = my_find(v.begin(), v.end(), x);
  if (p != v.end()) {
    // FOUND
  } else {
    // NOT FOUND
  }
}

bool odd(int x) { return x % 2; }

void f2(vector<int> &v) {
  vector<int>::iterator p = my_find_if(v.begin(), v.end(), odd);
  if (p != v.end()) {
    // FOUND FIRST ODD NUMBER
  }
}

class LargerThan {
  int v;

public:
  LargerThan(int _v) : v(_v) {}
  bool operator()(int x) const { return x > v; }
};

void f3(list<double> &v, int x) {
  list<double>::iterator p = my_find_if(v.begin(), v.end(), LargerThan(x));
  if (p != v.end()) {
    // FOUND A VALUE > X
  }
};

// GENERIC FUNCTION OBJECT
template <class S> class FunctionObject {
  S s;

public:
  FunctionObject(const S &ss) : s(ss) {}
  bool operator()(const S &ss) const {}
  const S &state() const { return s; }
  void reset(const S &ss) { s = ss; }
};

struct Record {
  string name;
  char addr[24];
};

struct CompareByName {
  bool operator()(const Record &a, const Record &b) const {
    return a.name < b.name;
  }
};

struct CompareByAddress {
  bool operator()(const Record &a, const Record &b) const {
    return strncmp(a.addr, b.addr, 24) < 0;
  }
};

bool compare_by_address(const Record &a, const Record &b) {
  return strncmp(a.addr, b.addr, 24) < 0;
}

int main() {
  vector<Record> vr;
  sort(vr.begin(), vr.end(), CompareByName());
  sort(vr.begin(), vr.end(), CompareByAddress());
  sort(vr.begin(), vr.end(), compare_by_address); // Regular function works, too
}
