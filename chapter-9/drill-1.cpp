#include <iostream>
#include <ostream>

using namespace std;

struct Date {
  int y;
  int m;
  int d;
};

ostream &operator<<(ostream &os, const Date &date) {
  return os << date.y << "-" << (date.m > 9 ? "" : "0") << date.m << "-"
            << (date.d > 9 ? "" : "0") << date.d;
}

void init_day(Date &dd, int y, int m, int d) {
  dd.y = y;
  dd.m = m;
  dd.d = d;
}

void add_day(Date &dd, int n) { dd.d += n; }

int main() {
  Date today;
  init_day(today, 1978, 6, 25);
  Date tomorrow = today;
  add_day(tomorrow, 1);

  cout << "Today: " << today << endl;
  cout << "Tomorrow: " << tomorrow << endl;

  return 0;
}
