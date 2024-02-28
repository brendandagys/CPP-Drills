#include <iostream>
#include <ostream>

using namespace std;

class Year {
  static const int min = 1000;
  static const int max = 3000;

public:
  class Invalid {};
  Year(int y) : y(y) {
    if (y < min || y > max)
      throw Invalid();
  }
  int year() const { return y; }

private:
  int y;
};

struct Date {
  enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
  Date(Year y, Month m, int d) : y(y), m(m), d(d) {}
  void add_day(int n) { d += n; }
  Year year() const { return y; }
  int month() const { return m; }
  int day() const { return d; }

private:
  Year y;
  Month m;
  int d;
};

ostream &operator<<(ostream &os, const Year &year) { return os << year.year(); }

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

  return 0;
}
