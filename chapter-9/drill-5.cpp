#include <iostream>
#include <ostream>

using namespace std;

struct Date {
  enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
  Date(int y, Month m, int d) : y(y), m(m), d(d) {}
  void add_year(int n) { y += n; }
  void add_month(int n) {
    m = (m + n > dec) ? Month(m + n - 12) : Month(m + n);
  }
  void add_day(int n) { d += n; }
  int year() const { return y; }
  int month() const { return m; }
  int day() const { return d; }

private:
  int y;
  Month m;
  int d;
};

ostream &operator<<(ostream &os, const Date &date) {
  return os << date.year() << "-" << (date.month() > 9 ? "" : "0")
            << date.month() << "-" << (date.day() > 9 ? "" : "0") << date.day();
}

int main() {
  Date today(1978, Date::dec, 25);
  Date tomorrow = today;
  tomorrow.add_day(1);

  cout << "Today: " << today << endl;
  cout << "Tomorrow: " << tomorrow << endl;

  tomorrow.add_month(4);
  cout << "Tomorrow: " << tomorrow << endl;

  tomorrow.add_month(1);
  cout << "Tomorrow: " << tomorrow << endl;

  return 0;
}
