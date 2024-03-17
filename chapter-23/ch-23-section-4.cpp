#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef vector<string>::const_iterator LineIter;

class Message {
  LineIter first;
  LineIter last;

public:
  Message(LineIter p1, LineIter p2) : first(p1), last(p2) {}
  LineIter begin() const { return first; }
  LineIter end() const { return last; }
};

typedef vector<Message>::const_iterator MessageIter;

struct MailFile {
  string file_name;
  vector<string> lines;
  vector<Message> messages;

  MailFile(const string &);

  MessageIter begin() const { return messages.begin(); }
  MessageIter end() const { return messages.end(); }
};

MailFile::MailFile(const string &file) {
  ifstream ifs(file.c_str());

  if (!ifs) {
    cerr << "No " << file << '\n';
    exit(1);
  }

  string s;
  while (getline(ifs, s))
    lines.push_back(s);

  LineIter first = lines.begin();
  for (LineIter p = first; p != lines.end(); ++p) {
    if (*p == "----") {
      messages.push_back(Message(first, p));
      first = p + 1;
    }
  }
}

int is_prefix(const string &s, const string &p) {
  int n = p.size();
  if (string(s, 0, n) == p)
    return n;
  return 0;
}

// If found, return `true` and put sender name in `s`
bool find_from_address(const Message *m, string &s) {
  for (LineIter p = m->begin(); p != m->end(); ++p)
    if (int n = is_prefix(*p, "From: ")) {
      s = string(*p, n);
      return true;
    }
  return false;
}

// Return subject if exists, otherwise ""
string find_subject(const Message &m) {
  for (LineIter p = m.begin(); p != m.end(); ++p)
    if (int n = is_prefix(*p, "Subject: "))
      return string(*p, n); // s[n]...s[s.size()-1]
  return "";
}

int main() {
  MailFile mail_file("ch-22-section-4-data.txt");

  // Gather messages from each sender together in a multimap
  multimap<string, const Message *> sender;

  for (MessageIter p = mail_file.begin(); p != mail_file.end(); ++p) {
    const Message &m = *p;
    string s;
    if (find_from_address(&m, s))
      sender.insert(make_pair(s, &m));
    cout << "s: " << s << '\n';
  }

  // Iterate through multimap and get subjects of John Doe's messages
  typedef multimap<string, const Message *>::const_iterator MultimapConstIter;
  pair<MultimapConstIter, MultimapConstIter> range =
      sender.equal_range("John Doe <jdoe@machine.example>");

  cout << "\nMultimap keys:\n";
  for (const auto &pair : sender) {
    cout << pair.first << '\n';
  }
  cout << '\n';

  for (MultimapConstIter p = range.first; p != range.second; ++p) {
    const Message &m = *(p->second);
    cout << find_subject(m) << '\n';
  }
}
