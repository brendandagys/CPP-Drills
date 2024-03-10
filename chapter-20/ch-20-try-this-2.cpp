#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

void print_char_array(char a[], size_t n) {
  cout << "\nprint_char_array()";
  cout << "\nSIZE: " << n;
  bool equals = true;
  char copy[]{'h', 'e', 'l', 'l', 'o'};
  for (size_t i = 0; i < n; ++i) {
    if (copy[i] != a[i])
      equals = false;
  }
  cout << "\nEQUALS: " << equals;
  cout << "\nLESS THAN: " << strcmp(a, "iello");

  for (int i = 0; i < n; ++i) {
    copy[i] = a[i];
  }
}

void print_char_vector(vector<char> v) {
  cout << "\n\nprint_char_vector()";
  cout << "\nSIZE: " << v.size();
  cout << "\nEQUALS: " << (v == vector<char>{'e', 'l', 'l', 'o', 'h'});
  cout << "\nLESS THAN: " << (v < vector<char>{'f', 'l', 'l', 'o', 'h'});
}

void print_char_list(list<char> l) {
  cout << "\n\nprint_char_list()";
  cout << "\nSIZE: " << l.size();
  cout << "\nEQUALS: " << (l == list<char>{'l', 'l', 'o', 'h', 'e'});
  cout << "\nLESS THAN: " << (l < list<char>{'m', 'l', 'o', 'h', 'e'});
  list<char> l2 = l;
}

void print_string(string s) {
  cout << "\n\nprint_string()";
  cout << "\nSIZE: " << s.size();
  cout << "\nEQUALS: " << (s == "lohel");
  cout << "\nLESS THAN: " << (s < "mohel");
  string s2 = s;
}

int main() {
  char ch_array[]{'h', 'e', 'l', 'l', 'o'};
  vector<char> ch_vec{'e', 'l', 'l', 'o', 'h'};
  list<char> ch_list{'l', 'l', 'o', 'h', 'e'};
  string str = "lohel";

  print_char_array(ch_array, 5);
  print_char_vector(ch_vec);
  print_char_list(ch_list);
  print_string(str);
}
