template <class T, int N> struct array {
  typedef T value_type;
  typedef T *iterator;
  typedef const T *const_iterator;
  typedef unsigned int size_type; // Type of a subscript

  T elems[N];
  // No explicit construct/copy/destroy needed

  iterator begin() { return elems; }
  const_iterator begin() const { return elems; }
  iterator end() { return elems + N; }
  const_iterator end() const { return elems + N; }

  size_type size() const;

  T &operator[](int n) { return elems[n]; }
  const T &operator[](int n) const { return elems[n]; }

  T &at(int n);             // Range-checked access
  const T &at(int n) const; // Range-checked access

  T *data() { return elems; }
  const T *data() const { return elems; }
};

int main() {
  array<double, 6> a = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5};
}
