#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
  int birth_year = 1993;

  cout << "DECIMAL" << '\t' << "HEXADECIMAL" << '\t' << "OCTAL" << '\n';
  cout << showbase << birth_year << '\t' << hex << birth_year << '\t' << '\t' << oct << birth_year << '\n';

  cout << dec << 30 << '\n';

  // int a, b, c, d;

  // cout << "Enter 4 numbers: ";

  // Reading in `1234` AS an octal or hexadecimal figure
  // cin >> a >> oct >> b >> hex >> c >> d;
  // cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

  double num = 1234567.89;

  cout << num << '\n';
  cout << fixed << num << '\n';
  cout << scientific << num << '\n';

  struct PersonDetails {
    string last_name;
    string first_name;
    string telephone_number;
    string email;
    PersonDetails(string l, string f, string t, string e) : last_name(l), first_name(f), telephone_number(t), email(e) {}
  };

  PersonDetails p1("Dagys", "Brendan", "1234567890", "brendan@example.com");
  PersonDetails p2("Almond", "Frederick", "1234567890", "fred@example.com");
  PersonDetails p3("Chan", "Cameron", "1234567890", "cameronchan123@example.com");
  PersonDetails p4("Kennedy", "Beauregard", "1234567890", "beauregard@example.com");
  PersonDetails p5("Sutherland", "Karen", "1234567890", "bates@example.com");
  PersonDetails p6("Cheven", "Holly", "1234567890", "holly@example.com");

  cout << setw(15) << "LAST" << setw(15) << "FIRST" << setw(15) << "PHONE" << setw(30) << "EMAIL" << '\n'; 
  
  for (const PersonDetails& p : vector<PersonDetails> {p1, p2, p3, p4, p5, p6}) {
    cout << setw(15) << p.last_name << setw(15) << p.first_name << setw(15) << p.telephone_number << setw(30) << p.email << '\n';
  }

  return 0;
}
