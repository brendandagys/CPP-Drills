#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
  try {
    // 1) cout << "Success!\n";
    // 2) cout << "Success!\n";
    // 3) cout << "Success" << "!\n";
    
    // 4) string success = "Success!";
    // 4) cout << success << endl;
    
    // 5) int res = 7;
    // 5) vector<int> v(10);
    // 5) v[5] = res;
    // 5) cout << "Success!\n";
    
    // 6) vector<int> v(10);
    // 6) v[5] = 7;
    // 6) if (v[5] == 7) cout << "Success!\n";

    // 7) bool cond = true;
    // 7) if (cond) cout << "Success!\n"; else cout << "Fail!\n";
    
    // 8) bool c = true; if (c) cout << "Success!\n"; else cout << "Fail!\n";

    // 9) string s = "ape"; bool c = "fool" >= s; if (c) cout << "Success!\n";

    // 10) string s = "ape"; if (s != "fool") cout << "Success!\n";
    
    // 11) string s = "ape"; if (s != "fool") cout << "Success!\n";
    
    // 12) string s = "ape"; if (s != "fool") cout << "Success!\n";
    
    // 13) vector<char> v(5); for (int i=0; i <= v.size(); ++i) {}; cout << "Success!\n";
    
    // 14) vector<char> v(5); for (int i = 0; i < v.size(); ++i) {}; cout << "Success!\n";

    // 15) string s = "Success!\n"; for (int i = 0; i < s.length(); ++i) cout << s[i];

    // 16) if (true) cout << "Success!\n"; else cout << "Fail!\n";

    // 17) int x = 2000; int c = x; if (c == 2000) cout << "Success!\n";

    // 18) string s = "Success!\n"; for (int i = 0; i<s.length(); ++i) cout << s[i];
    
    // 19) vector<int> v(5); for (int i=0; i <= v.size(); ++i) {}; cout << "Success!\n";

    // 20) int i=0; int j=9; while (i < 10) ++i; if (j < i) cout << "Success!\n";

    // 21) int x = 2; double d = 5.0/(x+2); if (d == 2*x + 0.5) cout << "Success!\n";

    // 22) string s = "Success!\n"; for (int i=0; i<=s.size(); ++i) cout << s[i];

    // 23) int i = 0, j = 0; while (i<10) ++i; if (j<i) cout << "Success!\n";

    // 24) int x = 4; double d = 5.0/(x-2); if (d==x/2.0+0.5) cout << "Success!\n";

    // 25) cout << "Success!\n";

  } catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
  } catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
  }
}
