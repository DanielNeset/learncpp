#pragma once
#include <string>

using namespace std;

class Surface {
public:
  Surface(const string &name_, double length_, double width_);
  double get_length() const { return length; }
  double get_width() const { return width; }
  double get_area() const;
  double get_circumference() const;

private:
  string name; // til identifikasjon
  double length;
  double width;
};
