#pragma once

const double pi = 3.141592;

class Circle {
public:
  // Constructor need to be names the same as the class.
  Circle(double radius_);
  int get_area() const;
  double get_circumference() const;

private:
  double radius;
};
