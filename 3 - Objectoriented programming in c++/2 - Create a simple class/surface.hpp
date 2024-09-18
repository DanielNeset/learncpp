#pragma once

#include <string>

using namespace std;

class Surface {
public:
  Surface(const string &name_, double length_, double width_);
  const string &get_name() const;
  double get_length() const;
  double get_width() const;
  double get_area() const;
  double get_circumference() const;

private:
  string name;
  double length;
  double width;
};

const string &Surface::get_name() const {
  return name;
}

double Surface::get_length() const {
  return length;
}

double Surface::get_width() const {
  return width;
}

double Surface::get_area() const {
  return width * length;
}

double Surface::get_circumference() const {
  return 2 * (length + width);
}
