#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
using namespace std;

static const string INPUT_FILE = "ch-21-drill-data.txt";

struct Item {
  string name;
  int id;
  double value;
};

bool compare_by_name(const Item &a, const Item &b) { return a.name < b.name; }
bool compare_by_id(const Item &a, const Item &b) { return a.id < b.id; }
bool compare_by_value_desc(const Item &a, const Item &b) {
  return a.value > b.value;
}

template <class T> void print_list(list<T> l, int num) {
  cout << "\n=== " << num << " ===\n";
  for (const auto &item : l) {
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

  list<Item> l;
  string line;

  while (getline(input_file, line)) {
    istringstream iss(line);
    Item item;

    if (!(iss >> item.name >> item.id >> item.value)) {
      cerr << "Error parsing line: " << line << '\n';
      continue;
    }
    l.push_back(item);
  }

  input_file.close();

  print_list(l, 1);

  // 2
  vector<Item> temp_vec(l.begin(), l.end());

  sort(temp_vec.begin(), temp_vec.end(), compare_by_name);
  l.assign(temp_vec.begin(), temp_vec.end());
  print_list(l, 2);

  // 3
  sort(temp_vec.begin(), temp_vec.end(), compare_by_id);
  l.assign(temp_vec.begin(), temp_vec.end());
  print_list(l, 3);

  // 4
  sort(temp_vec.begin(), temp_vec.end(), compare_by_value_desc);
  l.assign(temp_vec.begin(), temp_vec.end());
  print_list(l, 4);

  // 5
  l.insert(l.end(), {"horse shoe", 99, 12.34});
  l.insert(l.end(), {"Canon S400", 9988, 499.95});
  print_list(l, 5);

  // 6
  l.erase(remove_if(l.begin(), l.end(),
                    [&](const Item &item) { return item.name == "Kite"; }),
          l.end());
  print_list(l, 6);

  // 7
  l.erase(remove_if(l.begin(), l.end(),
                    [&](const Item &item) { return item.id == 4; }),
          l.end());
  print_list(l, 7);
}
