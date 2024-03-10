#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T> struct S {
  explicit S(T t) : val(t) {}

  void set(const T &);

  T &get();
  const T &get() const;

  T &operator[](size_t index) { return val; }
  const T &operator[](size_t index) const { return val; }

  T &operator=(const T &other) { return val = other; }

private:
  T val;
};

template <class T> T &S<T>::get() { return val; };
template <class T> const T &S<T>::get() const { return val; };
template <class T> void S<T>::set(const T &new_val) { val = new_val; };

template <class T> void read_val(T &t) { cin >> t; }

template <class T> ostream &operator<<(ostream &os, const vector<T> &d) {
  os << "{ ";
  for (int i = 0; i < d.size(); ++i) {
    os << d[i];
    if (i < d.size() - 1)
      os << ',';
    os << ' ';
  }
  return os << "}";
}

template <class U> istream &operator>>(istream &is, vector<U> &d) {
  char ch1, ch2;
  U temp;
  vector<U> v_temp;

  is >> ch1;
  if (!is)
    return is;
  if (ch1 != '{') {
    is.clear(ios_base::failbit);
    return is;
  }
  while (cin >> temp >> ch2 && ch2 == ',') {
    v_temp.push_back(temp);
  }
  if (ch2 != '}') {
    is.clear(ios_base::failbit);
    return is;
  }
  v_temp.push_back(temp); // ch2=='}', read last value

  d = v_temp; // Only copy if no failure
  return is;
}

template <class T> istream &operator>>(istream &is, S<T> &s) {
  T incoming;
  is >> incoming;
  if (!is)
    return is;
  s = incoming;
  return is;
}

int main() {
  S<int> s_int(7);
  S<char> s_char('5');
  S<double> s_double(10.0);
  S<string> s_string(string("example"));
  S<vector<int>> s_vec_int({1, 2, 3, 4, 5});

  cout << "s_int: " << s_int.get() << '\n';
  cout << "s_char: " << s_char.get() << '\n';
  cout << "s_double: " << s_double.get() << '\n';
  cout << "s_string: " << s_string.get() << '\n' << '\n';

  cout << "s_int: " << s_int[0] << '\n';
  cout << "s_char: " << s_char[12] << '\n';
  cout << "s_double: " << s_double[-20] << '\n';
  cout << "s_string: " << s_string[0] << '\n' << '\n';

  cout << "s_vec_int: ";
  for (const auto &el : s_vec_int[0]) {
    cout << el << ' ';
  }
  cout << '\n';

  s_int[23] = 6;
  s_char[2] = 'c';
  s_double[0] = 2;
  s_string[0] = string("foo");
  s_vec_int[0] = {5, 4, 3, 2, 1};

  cout << "\n=== STEP 11 ===\n";
  cout << "s_int: " << s_int[0] << '\n';
  cout << "s_char: " << s_char[12] << '\n';
  cout << "s_double: " << s_double[-20] << '\n';
  cout << "s_string: " << s_string[0] << '\n' << '\n';

  cout << "s_vec_int: ";
  for (const auto &el : s_vec_int[0]) {
    cout << el << ' ';
  }
  cout << '\n';

  cout << "\n=== STEP 13 ===\n";
  cout << "s_int: ";
  read_val(s_int);
  cout << "s_char: ";
  read_val(s_char);
  cout << "s_double: ";
  read_val(s_double);
  cout << "s_string: ";
  read_val(s_string);
  cout << "\ns_vec_int: ";
  read_val(s_vec_int);

  cout << "\ns_int: " << s_int.get() << '\n';
  cout << "s_char: " << s_char.get() << '\n';
  cout << "s_double: " << s_double.get() << '\n';
  cout << "s_string: " << s_string.get() << '\n';
  cout << "s_vec_int: " << s_vec_int.get() << '\n' << '\n';
}
