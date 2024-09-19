#include <iostream>

using namespace std;

class Surface {
public:
  Surface(double length_, double width_) : length(length_), width(width_) {}
  double length;
  double width;

  double area() {
    return length * width;
  }
};

class ColoredSurface : public Surface {
public:
  ColoredSurface(double length, double width, double red_, double green_, double blue_) : Surface(length, width), red(red_), green(green_), blue(blue_) {}
  double red;
  double green;
  double blue;
};

int main() {
  Surface surface(2.0, 3.0);
  cout << "Width: " << surface.width << endl;
  cout << "Area: " << surface.area() << endl;

  ColoredSurface colored_surface(2.0, 3.0, 0.0, 0.0, 1.0);
  cout << "Width: " << colored_surface.width << endl;
  cout << "Blue: " << colored_surface.blue << endl;
  cout << "Area: " << colored_surface.area() << endl;
}
