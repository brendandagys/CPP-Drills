#include <iostream>
#include <list>
using namespace std;

typedef vector<char> Line;

class Text_iterator {
  list<Line>::iterator line;
  Line::iterator pos;

public:
  Text_iterator(list<Line>::iterator l, Line::iterator p) : line(l), pos(p) {}

  char &operator*() { return *pos; }
  Text_iterator &operator++();

  bool operator==(const Text_iterator &other) const {
    return line == other.line && pos == other.pos;
  }
  bool operator!=(const Text_iterator &other) const {
    return !(*this == other);
  }
};

Text_iterator &Text_iterator::operator++() {
  if (pos == (*line).end()) {
    ++line;
    pos = (*line).begin();
  }
  ++pos;
  return *this;
}

struct Document {
  list<Line> lines;

  Document() { lines.push_back(Line()); }

  Text_iterator begin() {
    return Text_iterator(lines.begin(), (*lines.begin()).begin());
  }
  Text_iterator end() {
    return Text_iterator(lines.end(), (*lines.end()).end());
  }
};

istream &operator>>(istream &is, Document &doc) {
  char ch;
  while (is >> ch) {
    doc.lines.back().push_back(ch);
    if (ch == '\n')
      doc.lines.push_back(Line());
  }
  return is;
}

void print(Document &doc) {
  for (Text_iterator p = doc.begin(); p != doc.end(); ++p)
    cout << *p;
}

void erase_line(Document &doc, int n) {
  if (n < 0 || doc.lines.size() <= n)
    return;
  doc.lines.erase(next(doc.lines.begin(), n));
}

bool match(Text_iterator cur, Text_iterator last, const string &s) {
  int i = 0;

  while (cur != last && i != s.size()) {
    if (*cur != s[i]) {
      return false;
    }

    ++cur;
    ++i;
  }

  return (i == s.size());
}

Text_iterator find_text(Text_iterator first, Text_iterator last,
                        const string &s) {
  if (s.size() == 0)
    return last;

  while (true) {
    while (first != last && *first != s[0])
      ++first;
    if (first == last || match(first, last, s))
      return first;
    ++first;
  }
  return last;
}

int main() {
  Document d;
  Text_iterator p = find_text(d.begin(), d.end(), "This is an example\nline.");
  if (p == d.end())
    cout << "NOT FOUND\n";
}
