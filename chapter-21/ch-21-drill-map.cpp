#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <utility>
using namespace std;

template <class K, class V> void print_map(map<K, V> m, int num) {
  cout << "\n=== " << num << " ===\n";
  for (const auto &pair : m) {
    cout << "Key: " << pair.first << ", Value: " << pair.second << '\n';
  }
}

template <class K, class V>
void fill_map(istream &is, map<K, V> &m, int max_size = 1000) {
  string key;
  int value;

  while (is >> key >> value && !is.fail()) {
    m[key] = value;

    if (m.size() == max_size)
      break;
  }
}

int my_sum(int a, pair<string, int> p) { return a + p.second; }

int main() {
  // 1
  map<string, int> msi;

  // 2
  msi.insert({"one", 1});
  msi.insert({"two", 2});
  msi.insert(make_pair("three", 3));
  msi["four"] = 4;
  msi["five"] = 5;
  msi.insert({"six", 6});
  msi.insert({"seven", 7});
  msi.insert({"eight", 8});
  msi.insert({"nine", 9});
  msi.insert({"ten", 10});

  // 3
  print_map(msi, 3);

  // 4
  msi.clear();
  print_map(msi, 4);

  // 5 & 6
  const int MAX_KEYS = 3;
  cout << "Please enter " << MAX_KEYS
       << " space-separated K-V (string-int) pairs:\n";
  fill_map(cin, msi, MAX_KEYS);

  // 7
  print_map(msi, 5);

  // 8
  cout << "\nSum: " << accumulate(msi.begin(), msi.end(), 0, my_sum) << '\n';

  // 9
  map<int, string> mis;
  // 10
  for (const auto &pair : msi) {
    mis[pair.second] = pair.first;
  }
  // 11
  print_map(mis, 11);
}
