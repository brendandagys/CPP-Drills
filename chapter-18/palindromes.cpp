#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(const string &s) {
  int first = 0;
  int last = s.length() - 1;
  while (first < last) {
    if (s[first++] != s[last--])
      return false;
  }
  return true;
}

istream &read_word(istream &is, char *buffer, int max) {
  is.width(max);
  return is >> buffer;
}

bool is_palindrome(const char s[], int n) {
  int first = 0;
  int last = n - 1;

  while (first < last) {
    if (s[first++] != s[last--])
      return false;
  }
  return true;
}

bool is_palindrome(const char *first, const char *last) {
  while (first < last) {
    if (*first != *last) {
      return false;
    }

    return is_palindrome(++first, --last);
  }
  return true;
}

int main() {
  // STRING
  string s;
  while (cin >> s) {
    cout << s << " is" << (is_palindrome(s) ? "" : " not")
         << " a palindrome.\n";
  }

  // ARRAY
  const int max = 5;
  char s2[max];
  while (read_word(cin, s2, max)) {
    for (int i = 0; i < max; ++i) {
      cout << i << ": " << s2[i] << " | ";
    }

    cout << s2 << " is" << (is_palindrome(s2, strlen(s2)) ? "" : " not")
         << " a palindrome.\n";
  }

  // POINTERS
  char s3[max];
  while (read_word(cin, s3, max)) {
    cout << s3 << " is"
         << (is_palindrome(s3, &s3[strlen(s3) - 1]) ? "" : " not")
         << " a palindrome.\n";
  }

  return 0;
}
