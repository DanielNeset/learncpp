#include "surface.hpp"
#include <iostream>
#include <string>

using namespace std;

Surface::Surface(const string &name_, double length_, double width_) : name(name_), length(length_), width(width_) {}

double Surface::get_area() const {
  return width * length;
}

double Surface::get_circumference() const {
  return 2 * (length + width);
}
