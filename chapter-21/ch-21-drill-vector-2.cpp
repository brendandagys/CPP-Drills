#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

static const string INPUT_FILE = "ch-21-drill-data-2.txt";

template <class T> void print_vec(vector<T> v, int num) {
  cout << "\n=== " << num << " ===\n";
  for (const auto &val : v) {
    cout << "Value: " << val << '\n';
  }
}

class Pred {
  double max;

public:
  Pred(double m) : max(m) {}
  bool operator()(const double d) { return d < max; }
};

int main() {
  // 1
  ifstream fis(INPUT_FILE);

  if (!fis.is_open()) {
    cerr << "Error opening file: " << INPUT_FILE << '\n';
    return 1;
  }

  vector<double> vd;

  double d;
  while (fis >> d) {
    vd.push_back(d);
  }

  if (!fis.eof()) {
    cerr << "Error parsing file: " << INPUT_FILE << '\n';
    return 1;
  }

  // 2
  print_vec(vd, 2);

  // 3
  vector<int> vi;
  for (const auto &val : vd) {
    vi.push_back(val);
  }
  print_vec(vi, 3);

  // 4
  cout << "\n=== 4 - vd-vi pairs ===\n";
  for (int i = 0; i < vd.size(); ++i) {
    cout << left << setw(10) << vd[i] << ' ' << vi[i] << '\n';
  }

  // 5
  cout << "\n=== 5 - vd sum ===\n";
  double vd_sum = accumulate(vd.begin(), vd.end(), 0.0);
  cout << vd_sum << '\n';

  // 6
  int vi_sum = accumulate(vi.begin(), vi.end(), 0);
  cout << "\n=== 6 - vd sum - vi sum ===\n" << vd_sum - vi_sum << '\n';

  // 7
  reverse(vd.begin(), vd.end());
  print_vec(vd, 7);

  // 8
  cout << "\n=== 8 - vd mean ===\n";
  double vd_mean = vd_sum / vd.size();
  cout << vd_mean << '\n';

  // 9
  vector<double> vd2(vd.size());
  copy_if(vd.begin(), vd.end(), vd2.begin(), Pred(vd_mean));
  print_vec(vd2, 9);

  // 10
  sort(vd2.begin(), vd2.end());
  print_vec(vd2, 10);
}
