#include <iostream>

using namespace std;

const double pi = 3.141592;

class Circle {
public:
  // Constructor need to be named the same as the class, big C.
  Circle(double radius_);
  int get_area() const;
  double get_circumference() const;

private:
  double radius;
};

// Remove public and switch radius_(radius) to radius(radius_)
Circle::Circle(double radius_) : radius(radius_) {}

int Circle::get_area() const {
  return pi * radius * radius;
}

// Change to double
double Circle::get_circumference() const {
  // Use double instead of int.
  double circumference = 2.0 * pi * radius;
  return circumference;
}

int main() {

  Circle circle(10.5);

  cout << "Circle area: " << circle.get_area() << ", circumference: " << circle.get_circumference() << endl;
}
