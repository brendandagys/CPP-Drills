#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

static const int NUM_POINTS = 2;

struct Point {
  int x;
  int y;
  Point(int x, int y) : x(x), y(y) {}
  Point() : x(0), y(0) {}
};

istream &operator>>(istream &istream, Point &point) {
  int x, y;
  char separator;

  istream >> x;

  if (!istream || !istream.get(separator) ||
      (separator != ',' && separator != ' ' && separator != '\n')) {
    istream.clear(ios_base::failbit);
    return istream;
  }

  if (separator == '\n')
    cout << " ... > ";

  istream >> y;

  if (istream) {
    point.x = x;
    point.y = y;
  }

  return istream;
}

ifstream &operator>>(ifstream &ifstream, Point &point) {
  char c1, c2, c3;
  int x, y;

  if (!(ifstream >> c1 >> x >> c2 >> y >> c3))
    return ifstream;

  if (c1 != '(' || c2 != ',' || c3 != ')') {
    ifstream.clear(ios_base::failbit);
    return ifstream;
  }

  point.x = x;
  point.y = y;

  return ifstream;
}

ostream &operator<<(ostream &ostream, Point point) {
  return ostream << "(" << point.x << ", " << point.y << ")";
}

bool operator==(const Point &p1, const Point &p2) {
  cout << "P1: " << p1 << " P2: " << p2;
  return p1.x == p2.x && p1.y == p2.y;
}

int main() {
  vector<Point> original_points;

  cout << "Please input seven (x, y) points:\n"
       << " > ";

  while (original_points.size() < NUM_POINTS) {
    Point point;

    if (!(cin >> point)) {
      cout << "Invalid point!\n > ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    original_points.push_back(point);
    cout << " OK\n";
    if (original_points.size() < NUM_POINTS)
      cout << " > ";
  }

  cout << '\n';
  for (const Point &point : original_points) {
    cout << point << '\n';
  }

  // Step 4
  ofstream ofstream("mydata.txt");
  if (!ofstream)
    throw runtime_error("Can't open output file: mydata.txt");

  for (const Point &point : original_points) {
    ofstream << point;
  }

  ofstream.close();

  ifstream ifstream("mydata.txt");
  if (!ifstream)
    throw runtime_error("Can't open input file: mydata.txt");

  vector<Point> processed_points;

  while (true) {
    Point point;

    ifstream >> point;
    
    if (!ifstream && !ifstream.eof()) // EOF sets both the EOF and fail flags
      throw runtime_error("Could not read file!");

    if (ifstream.eof())
      break;

    processed_points.push_back(point);
  }

  if (original_points.size() != processed_points.size()) {
    cout << "Something's wrong!";
    return 1;
  }

  for (int i = 0; i < original_points.size(); ++i) {
    if (original_points[i].x != processed_points[i].x ||
        original_points[i].y != processed_points[i].y) {
      cout << "Something's wrong!\n";
      return 1;
    }
  }

  return 0;
}
