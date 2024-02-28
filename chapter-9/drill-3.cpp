#include <iostream>
#include <ostream>

using namespace std;

struct Date {
  Date(int y, int m, int d) : y(y), m(m), d(d) {}
  void add_day(int n) { d += n; }
  int year() const { return y; }
  int month() const { return m; }
  int day() const { return d; }

private:
  int y, m, d;
};

ostream &operator<<(ostream &os, const Date &date) {
  return os << date.year() << "-" << (date.month() > 9 ? "" : "0")
            << date.month() << "-" << (date.day() > 9 ? "" : "0") << date.day();
}

int main() {
  Date today(1978, 06, 25);
  Date tomorrow = today;
  tomorrow.add_day(1);

  cout << "Today: " << today << endl;
  cout << "Tomorrow: " << tomorrow << endl;

  return 0;
}
