#include <fstream>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
  ifstream ifs("ch-22-drill-data.txt");
  if (!ifs)
    cerr << "No file\n";

  string str_pattern = "\\w{2}\\s*\\d{5}(-\\d{4})?";
  regex pattern(str_pattern); // ZIP code pattern
  cout << "PATTERN: " << str_pattern << '\n';

  int lineno = 0;
  string line;

  while (getline(ifs, line)) {
    ++lineno;
    smatch matches;

    if (regex_search(line, matches, pattern)) {
      cout << lineno << ": " << matches[0] << '\n';

      if (1 < matches.size() && matches[1].matched)
        cout << "\t: " << matches[1] << '\n';
    }
  }
}
