#include <memory>
#include <utility>
using namespace std;
// template <class T> class allocator {
// public:
//   T *allocate(int n);           // Allocate space for `n` objects of type `T`
//   void deallocate(T *p, int n); // Deallocate `n` objects of `T` starting at
//   `p`
//
//   void construct(T *p, const T &v); // Construct a `T` with the value `v` in
//   `p` void destroy(T *p);               // Destroy the `T` in `p`
// };

template <class T, class A> struct vector_base {
  A alloc;

  T *elem;
  int _size;
  int space;

  vector_base(const A &a, int n)
      : alloc(a), elem(a.allocate(n)), _size(n), space(n) {}
  ~vector_base() { alloc.deallocate(elem, space); }
};

template <class T, class A = allocator<T>>
class my_vector : private vector_base<T, A> {
  A alloc;

  int _size;
  int space;
  T *elem; // Pointer to the elements (or 0)

public:
  typedef unsigned long size_type;
  typedef T value_type;
  typedef T *iterator;
  typedef const T *const_iterator;

  my_vector() : _size(0), space(0), elem(0) {}
  my_vector(int s) : _size(s), space(s), elem(alloc.allocate(s)) {
    for (size_type i = 0; i < _size; ++i)
      elem[i] = 0; // Initialize elements
  }
  my_vector(const my_vector &);            // Copy constructor
  my_vector &operator=(const my_vector &); // Copy assignment operator
  ~my_vector() { delete[] elem; }

  size_type size() const { return _size; }
  size_type capacity() const { return space; }

  void reserve(size_type);
  void resize(size_type, T def = T());
  void push_back(const T);

  iterator begin();
  const_iterator begin() const;
  iterator end();
  const_iterator end() const;

  value_type &front() const { return *begin(); }
  value_type &back() const { return *(end() - 1); }

  iterator insert(iterator p, const T &val);
  iterator erase(iterator p);

  T &operator[](size_type n) { return elem[n]; }
  const T &operator[](size_type n) const { return elem[n]; }

  struct out_of_range {};

  T &at(int n);

  const T &at(size_type n) const {
    if (n < 0 || _size <= n)
      throw out_of_range();
    return elem[n];
  }
};

// Doesn't initialize elements of reserved space past `_size`
template <class T, class A> void my_vector<T, A>::reserve(size_type new_count) {
  if (new_count <= space) // Never decrease allocation
    return;
  vector_base<T, A> b(alloc, new_count);
  //  T *p = alloc.allocate( // Allocate new space
  //      new_count);        // double *p = new double[new_count];
  for (size_type i = 0; i < _size; ++i)
    alloc.construct(&b.elem[i], elem[i]); // p[i] = elem[i];
  for (size_type i = 0; i < _size; ++i)
    alloc.destroy(&elem[i]);
  // alloc.deallocate(elem, space); // delete[] elem; // Deallocate old space
  // elem = p;
  // space = new_count;
  swap<vector_base<T, A>>(*this, b);
}

// Makes my_vector have `new_size` elements; initializes new elements (if any
// exist)
template <class T, class A>
void my_vector<T, A>::resize(size_type new_size, T val) {
  reserve(new_size);
  for (size_type i = _size; i < new_size; ++i)
    alloc.construct(&elem[i], val); // elem[i] = 0; // Initialize new elements
  for (size_type i = new_size; i < _size; ++i)
    alloc.destroy(&elem[i]); // May need to destroy surplus elements
  _size = new_size;
}

template <class T, class A> void my_vector<T, A>::push_back(const T val) {
  if (space == 0)
    reserve(8);
  else if (_size == space)
    reserve(2 * space);
  alloc.construct(&elem[_size++], val); // elem[_size++] = val;
}

template <class T, class A>
my_vector<T, A> &my_vector<T, A>::operator=(const my_vector &other) {
  if (this == &other)
    return *this; // Self-reference

  if (other._size <= space) { // No need to reallocate
    for (int i = 0; i < other._size; ++i)
      elem[i] = other.elem[i];
    _size = other._size;
    return *this;
  }

  reserve(other._size);
  for (size_type i = 0; i < other._size; ++i)
    alloc.construct(&elem[i], other.elem[i]);
  space = _size = other._size;
  return *this;
  //  double *p = new double[other._size];
  //  for (int i = 0; i < other._size; ++i)
  //    p[i] = other.elem[i];
  //  delete[] elem;
  //  elem = p;
  //  space = _size = other._size;
  //  return *this;
}

template <class T, class A>
typename my_vector<T, A>::iterator my_vector<T, A>::erase(iterator p) {
  if (p == end())
    return p;
  iterator pos;
  for (pos = p + 1; pos != end(); ++pos)
    *(pos - 1) = *pos;
  alloc.destroy(&*pos);
  --_size;
  return p;
}

template <class T, class A>
typename my_vector<T, A>::iterator my_vector<T, A>::insert(iterator p,
                                                           const T &val) {
  int index = p - begin();
  if (size() == capacity())
    reserve(2 * size());
  alloc.construct(elem + size(), back());
  ++_size;
  iterator pp = begin() + index;
  for (iterator pos = end() - 1; pos != pp; --pos)
    *pos = *(pos - 1);
  *pp = val;
  return pp;
}

int main() {}
