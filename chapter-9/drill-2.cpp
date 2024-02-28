#include <iostream>
#include <ostream>

using namespace std;

struct Date {
  int y, m, d;
  Date(int y, int m, int d) : y(y), m(m), d(d) {}
  void add_day(int n) { d += n; }
};

ostream &operator<<(ostream &os, const Date &date) {
  return os << date.y << "-" << (date.m > 9 ? "" : "0") << date.m << "-"
            << (date.d > 9 ? "" : "0") << date.d;
}

int main() {
  Date today(1978, 06, 25);
  Date tomorrow = today;
  tomorrow.add_day(1);

  cout << "Today: " << today << endl;
  cout << "Tomorrow: " << tomorrow << endl;

  return 0;
}
