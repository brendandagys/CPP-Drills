#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <vector>
using namespace std;

template <class In, class Out> Out my_copy(In first, In last, Out res) {
  while (first != last) {
    *res = *first;
    ++res;
    ++first;
  }
  return res;
}

void f(vector<double> &vd, list<int> &li) {
  if (vd.size() < li.size())
    throw runtime_error("Target container too small");
  my_copy(li.begin(), li.end(), vd.begin());
}

template <class In, class Out, class Pred>
Out my_copy_if(In first, In last, Out res, Pred p) {
  while (first != last) {
    if (p(*first))
      *res++ = *first;
    ++first;
  }
  return res;
}

class LargerThan {
  int v;

public:
  LargerThan(int _v) : v(_v) {}
  bool operator()(int x) const { return x > v; }
};

void f2(const vector<int> &v) {
  vector<int> v2(v.size());
  my_copy_if(v.begin(), v.end(), v2.begin(), LargerThan(6));
}

int main() {
  ostream_iterator<string> oo(cout);
  *oo = "Hello, ";
  ++oo;
  *oo = "World!\n";

  istream_iterator<string> ii(cin);
  string s1 = *ii;
  ++ii;
  string s2 = *ii;

  // Making a dictionary
  string from, to;
  cin >> from >> to;

  ifstream is(from.c_str());
  ofstream os(to.c_str());

  istream_iterator<string> ii2(is);
  istream_iterator<string> eos;
  ostream_iterator<string> oo2(os, "\n");

  // vector<string> b(ii2, eos);
  set<string> b2(ii2, eos); // Better than a vector since we don't need to sort
  // sort(b.begin(), b.end());
  copy(b2.begin(), b2.end(), oo2);
}
