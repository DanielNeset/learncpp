#include "circle.hpp"

// Remove public and switch radius_(radius)
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
