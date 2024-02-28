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

  int num_entered = 0;
  double sum = 0;

  vector<double> values;

  while(true) {
    cout << "\nEnter a number with a unit: ";

    if (!(cin >> cm >> unit)) {
      cin.clear();

      char invalid_char;
      cin >> invalid_char;

      if (invalid_char == '|') {
        cout << "Values entered: ";

        sort(values.begin(), values.end());

        for (int i = 0; i < values.size(); i++) {
          cout << values[i] << " ";
        }

        cout << "\n\nLARGEST: " << largest << " SMALLEST: " << smallest << " COUNT: " << num_entered << " SUM: " << sum << '\n';
        return 0;
      }

      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    ++num_entered;

    if (unit == "m") {
      cm = cm * 100;
    } else if (unit == "in") {
      cm = cm * 2.54;
    } else if (unit == "ft") {
      cm = cm * 12;
    } else if (unit != "cm") {
      continue;
    }

    sum += cm / 100;
    values.push_back(cm / 100);

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
