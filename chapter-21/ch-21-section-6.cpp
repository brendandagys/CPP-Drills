#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <utility>
using namespace std;

template <class T1, class T2> struct my_pair {
  T1 first;
  T2 second;

  my_pair() : first(T1()), second(T2()) {}
  my_pair(const T1 &x, const T2 &y) : first(x), second(y) {}
  template <class U, class V>
  my_pair(const pair<U, V> &p) : first(p.first), second(p.second) {}
};

class TreeNode {};

template <class Key, class Value, class Compare = less<Key>> class my_map {
  typedef pair<Key, Value> value_type;

  typedef TreeNode *iterator;
  typedef TreeNode *const_iterator;

  iterator begin();
  iterator end();

  Value &operator[](const Key &k);
  iterator find(const Key &k);
  void erase(iterator p);
  pair<iterator, bool> insert(const value_type &);
};

template <class T1, class T2> pair<T1, T2> my_make_pair(T1 x, T2 y) {
  return pair<T1, T2>(x, y);
}

double weighted_value(const pair<string, double> &a,
                      const pair<string, double> &b) {
  return a.second * b.second;
}

struct Fruit {
  string name;
  int count;
  double unit_price;
  string last_sale_date;
};

ostream &operator<<(ostream &os, const Fruit &f) { return os << f.name; }

struct FruitOrder {
  bool operator()(const Fruit &a, const Fruit &b) const {
    return a.name < b.name;
  }
};

int main() {
  map<string, int> words; // K: word, V: count

  string s;

  while (cin >> s)
    ++words[s];

  typedef map<string, int>::const_iterator Iter;

  for (Iter p = words.begin(); p != words.end(); ++p)
    cout << p->first << ": " << p->second << '\n';

  map<string, double> dow_price;
  dow_price["MMM"] = 81.86;
  dow_price["AA"] = 34.69;
  dow_price["MO"] = 54.45;

  map<string, double> dow_weight;
  dow_weight.insert(make_pair("MMM", 5.8549));
  dow_weight.insert(make_pair("AA", 2.4808));
  dow_weight.insert(make_pair("MO", 3.8940));

  map<string, string> dow_name;
  dow_name["MMM"] = "3M Co.";
  dow_name["AA"] = "Alcoa Inc.";
  dow_name["MO"] = "Altria Group Inc.";

  double alcoa_price = dow_price["AAA"];
  double boeing_price = dow_price["BA"];

  if (dow_price.find("INTC") != dow_price.end())
    cout << "Intel is in the Dow\n";

  typedef map<string, double>::const_iterator Dow_iterator;

  for (Dow_iterator p = dow_price.begin(); p != dow_price.end(); ++p) {
    const string &symbol = p->first;
    cout << symbol << '\t' << p->second << '\t' << dow_name[symbol] << '\n';
  }

  double dji_index =
      inner_product(dow_price.begin(), dow_price.end(), dow_weight.begin(), 0.0,
                    plus<double>(), weighted_value);

  set<Fruit, FruitOrder> inventory;
  inventory.insert(Fruit());
  inventory.insert(Fruit());
  typedef set<Fruit>::const_iterator SI;
  for (SI p = inventory.begin(); p != inventory.end(); ++p)
    cout << *p << '\n';
}
