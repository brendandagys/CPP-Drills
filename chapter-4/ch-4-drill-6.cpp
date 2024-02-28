#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
  double smallest = numeric_limits<double>::quiet_NaN(), largest = numeric_limits<double>::quiet_NaN(), current;

  while(true) {
    cout << "\nEnter a number: ";

    if (!(cin >> current)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string suffix = "";

    if (isnan(smallest)) {
      smallest = current;
      suffix = "smallest so far.";
    } else if (isnan(largest)) {
        if (current < smallest) {
          largest = smallest;
          smallest = current;
          suffix = "smallest so far.";
        } else {
          largest = current;
          suffix = "largest so far.";
        }
    } else if (current < smallest) {
      smallest = current;
      suffix = "smallest so far.";
    } else if (current > largest) {
      largest = current;
      suffix = "largest so far.";
    }

    cout << "\nSMALLEST: " << smallest << " LARGEST: " << largest << '\n';

    if (suffix != "") {
      cout << '\n' << current << " is the " << suffix << '\n';
    }

  }

  return 0;
}
