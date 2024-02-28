#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
  int one, two;

  while(true) {
    cout << "Enter two numbers: \n";

    if (!(cin >> one >> two)) {
      cin.clear();

      char invalid_char;
      cin >> invalid_char;

      if (invalid_char == '|') {
        break;
      }
      
      continue;
    }

    cout << "One: " << one << " Two: " << two << "\n";
  }

  return 0;
}
