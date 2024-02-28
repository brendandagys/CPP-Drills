#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
  int one, two;

  while(true) {
    cout << "\nEnter two numbers: \n";

    if (!(cin >> one >> two)) {
      cin.clear();

      char invalid_char;
      cin >> invalid_char;

      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      if (invalid_char == '|') {
        break;
      }
      
      continue;
    }

    int smaller = one < two ? one : two;
    int larger = one > two ? one : two;
    
    cout << "\nThe smaller value is: " << smaller << '\n';
    cout << "The larger value is: " << larger << '\n';
  }

  return 0;
}
