#include <sstream>
#include <stdexcept>
using namespace std;

template <class T> string to_string(const T &t) {
  ostringstream os;
  os << t;
  return os.str();
}

struct bad_from_string : bad_cast {
  const char *what() const noexcept { return "Bad cast from string"; }
};

template <class T> T from_string(const string &s) {
  istringstream is(s);
  T t;
  if (!(is >> t))
    throw bad_from_string();
  return t;
}

struct bad_lexical_cast : bad_cast {
  const char *what() const noexcept { return "Bad cast"; }
};

template <typename Target, typename Source> Target lexical_cast(Source arg) {
  stringstream interpreter;
  Target result;

  if (!(interpreter << arg) || !(interpreter >> result) ||
      !(interpreter >> ws).eof()) {
    throw bad_lexical_cast();
  }

  return result;
}

int main() {
  from_string<double>("12.333");

  try {
    from_string<int>("23.0");
  } catch (bad_from_string e) {
    throw runtime_error("Bad input string");
  }
}
