#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
  double smallest = numeric_limits<double>::quiet_NaN(), largest = numeric_limits<double>::quiet_NaN();
  double cm;
  string unit;

  while(true) {
    cout << "\nEnter a number with a unit: ";

    while (!(cin >> cm >> unit)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (unit == "m") {
      cm = cm * 100;
    } else if (unit == "in") {
      cm = cm * 2.54;
    } else if (unit == "ft") {
      cm = cm * 12;
    } else if (unit != "cm") {
      continue;
    }

    string suffix = "";

    if (isnan(smallest)) {
      smallest = cm;
      suffix = "smallest so far.";
    } else if (isnan(largest)) {
        if (cm < smallest) {
          largest = smallest;
          smallest = cm;
          suffix = "smallest so far.";
        } else {
          largest = cm;
          suffix = "largest so far.";
        }
    } else if (cm < smallest) {
      smallest = cm;
      suffix = "smallest so far.";
    } else if (cm > largest) {
      largest = cm;
      suffix = "largest so far.";
    }

    cout << "\nSMALLEST: " << smallest << " LARGEST: " << largest << '\n';

    if (suffix != "") {
      cout << '\n' << cm << " is the " << suffix << '\n';
    }

  }

  return 0;
}
