#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class Ran> void my_sort(Ran first, Ran last);
template <class Ran, class Compare>
void my_sort(Ran first, Ran last, Compare compare);

struct NoCase {
  bool operator()(const string &x, const string &y) const {
    for (int i = 0; i < x.length(); ++i) {
      if (i == y.length())
        return false;
      char xx = tolower(x[i]);
      char yy = tolower(y[i]);
      if (xx < yy)
        return true;
      if (yy < xx)
        return false;
    }
    return true;
  }
};

void sort_and_print(vector<string> &v) {
  my_sort(v.begin(), v.end(), NoCase());

  for (vector<string>::const_iterator p = v.begin(); p != v.end(); ++p)
    cout << *p << '\n';
}

// If we care about the element found, can use `lower_bound()`, `upper_bound()`,
// or `equal_range()`
template <class Ran, class T>
bool my_binary_search(Ran first, Ran last, const T &val);
template <class Ran, class T, class Compare>
bool my_binary_search(Ran first, Ran last, const T &val, Compare compare);

void f(vector<string> &vs) {
  if (my_binary_search(vs.begin(), vs.end(), "starfruit")) {
    // We found a starfruit
  }
}

int main() {}
