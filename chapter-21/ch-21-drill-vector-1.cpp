#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

static const char INPUT_FILE[] = "ch-21-drill-data.txt";

struct Item {
  string name;
  int id;
  double value;

  Item(string n, int i, double v) : name(n), id(i), value(v) {}
  Item() {}
};

bool compare_by_name(const Item &a, const Item &b) { return a.name < b.name; }
bool compare_by_id(const Item &a, const Item &b) { return a.id < b.id; }
bool compare_by_value_desc(const Item &a, const Item &b) {
  return a.value > b.value;
}

template <class T> void print_vec(vector<T> v, int num) {
  cout << "\n=== " << num << " ===\n";
  for (const auto &item : v) {
    cout << "Name: " << item.name << ", ID: " << item.id
         << ", Value: " << item.value << '\n';
  }
}

int main() {
  // 1
  ifstream input_file(INPUT_FILE);

  if (!input_file.is_open()) {
    cerr << "Error opening file: " << INPUT_FILE << '\n';
    return 1;
  }

  vector<Item> vec;
  string line;

  while (getline(input_file, line)) {
    istringstream iss(line);
    Item item;
    if (!(iss >> item.name >> item.id >> item.value)) {
      cerr << "Error parsing line: " << line << '\n';
      continue;
    }
    vec.push_back(item);
  }

  input_file.close();

  print_vec(vec, 1);

  // 2
  sort(vec.begin(), vec.end(), compare_by_name);
  print_vec(vec, 2);

  // 3
  sort(vec.begin(), vec.end(), compare_by_id);
  print_vec(vec, 3);

  // 4
  sort(vec.begin(), vec.end(), compare_by_value_desc);
  print_vec(vec, 4);

  // 5
  vec.insert(vec.end(), Item("horse shoe", 99, 12.34));
  vec.insert(vec.end(), Item("Canon S400", 9988, 499.95));
  print_vec(vec, 5);

  // 6
  vec.erase(remove_if(vec.begin(), vec.end(),
                      [&](const Item &item) { return item.name == "Kite"; }),
            vec.end());
  print_vec(vec, 6);

  // 7
  vec.erase(remove_if(vec.begin(), vec.end(),
                      [&](const Item &item) { return item.id == 4; }),
            vec.end());
  print_vec(vec, 7);
}
