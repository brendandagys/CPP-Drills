#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
  cout << "\nPlease enter expression (we can handle +, -, *, and /): ";
  
  int lval = 0;
  int rval;
  char op;
  
  cin >> lval;
  if (!cin) throw runtime_error("No first operand");

  while (cin >> op) {
    if (op == '=') {
      cout << "RESULT: " << lval << '\n';
      return 0;
    }

    cin >> rval;
    if (!cin) throw runtime_error("No second operand");

    switch(op) {
      case '+':
        lval += rval;
        break;
      case '-':
        lval -= rval;
        break;
      case '*':
        lval *= rval;
        break;
      case '/':
        lval /= rval;
        break;
      default:
        cout << "Result: " << lval << '\n';
        return 0;
    }
  }

  throw runtime_error("Bad expression");
}
