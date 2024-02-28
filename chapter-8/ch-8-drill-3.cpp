namespace X {
  int var;
  void print() {};
}

namespace Y {
  int var;
  void print() {};
}

namespace Z {
  int var;
  void print() {};
}

int main() {
  X::var = 7;
  X::print();
  using namespace Y;
  var = 9;
  print();
  {
    using Z::print;
    using Z::var;
    var = 11;
    print();
  }
  print();
  X::print();
}
