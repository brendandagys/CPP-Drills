class Shape {
public:
  void draw() const;
  virtual void move(int dx, int dy);
  int number_of_ppoints() const;
  virtual ~Shape() {}

protected:
  Shape();
  virtual void draw_lines() const;

private:
  Shape(const Shape &); // prevent copying when initializing a new instance
  Shape &operator=(
      const Shape &); // prevent coping when assigning to an existing object
};

class Circle : Shape {
  int r;
};

class Smiley : Circle {
  bool left_eye;
  bool right_eye;
  bool mouth;
};

class Frowny : Circle {
  bool left_eye;
  bool right_eye;
  bool mouth;
};

class SmileyHat : Smiley {
  bool left_eye;
  bool right_eye;
  bool mouth;
  bool hat;
};

class FrownyHat : Frowny {
  bool left_eye;
  bool right_eye;
  bool mouth;
  bool hat;
};

int main() {
  Circle c1;
  Circle c2;

  // EXERCISE 2
  //  c2 = c1; // Copy assignment operator is private
  //  Circle c3 = c1; // Copy constructor is private

  // EXERCISE 3
  //  Shape s; // Calling a protected constructor of class `Shape`

  return 0;
}
