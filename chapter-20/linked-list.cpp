#include <iostream>
using namespace std;

// GET HIGHEST ELEMENT USING AN ITERATOR
template <class Iterator> Iterator high(Iterator first, Iterator last) {
  Iterator high = first;
  for (Iterator p = first; p != last; ++p)
    if (*high < *p)
      high = p;
  return high;
}

template <class Elem> class list {

public:
  struct Link;

  typedef unsigned long size_type;
  typedef Elem value_type;

  class iterator;
  class const_iterator;

  iterator begin() { return first; };
  const_iterator begin() const { return first; };
  iterator end() { return last; }; // One beyond last element
  const_iterator end() const { return last; };

  iterator insert(iterator p, const Elem &v); // Insert `v` after `p`
  iterator erase(iterator p);

  void push_front(const Elem &v){}; // TODO: implement
  void push_back(const Elem &v);

  void pop_front();
  void pop_back();

  Elem &front();
  Elem &back();

private:
  Link *first;
  Link *last;
};

template <class Elem> struct list<Elem>::Link {
  Link *prev;
  Link *succ;
  Elem val;
};

template <class Elem> class list<Elem>::iterator {
  Link *curr;

public:
  iterator(Link *p) : curr(p) {}

  iterator &operator++() {
    curr = curr->succ;
    return *this;
  }
  iterator &operator--() {
    curr = curr->prev;
    return *this;
  }
  Elem &operator*() { return curr->val; }

  bool operator==(const iterator &b) const { return curr == b.curr; }
  bool operator!=(const iterator &b) const { return curr != b.curr; }
};

void f() {
  list<int> my_list;
  int x;
  while (cin >> x)
    my_list.push_front(x);

  list<int>::iterator p = high(my_list.begin(), my_list.end());
  if (p == my_list.end())
    cout << "The list is empty\n";
  else
    cout << "The highest value was " << *p << '\n';
}

int main() {}
