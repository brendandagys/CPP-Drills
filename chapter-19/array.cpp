template <class T, int N> struct array {
  T elem[N];

  // Rely on the default constructors, destructor, and assignment

  T &operator[](int n);
  const T &operator[](int n) const;

  T *data() { return elem; }
  const T *data() const { return elem; }

  int size() const { return N; }
};
