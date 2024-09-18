#include "surface.hpp"
#include <iostream>
#include <string>

using namespace std;

Surface::Surface(const string &name_, double length_, double width_)
    : name(name_), length(length_), width(width_) {}

int main() {

  Surface floor("Daniels floor", 5.5, 3.2);

  string name = floor.get_name();
  double width = floor.get_width();
  double length = floor.get_length();
  double area = floor.get_area();
  double circumference = floor.get_circumference();

  cout << "Data about floor with name: " << name << ":" << endl;
  cout << "Width: " << width << endl;
  cout << "Length: " << length << endl;
  cout << "Area: " << area << endl;
  cout << "Circumference: " << circumference << endl;
}
