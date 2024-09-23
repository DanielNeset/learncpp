#include <algorithm>
#include <iostream>

using namespace std;

class Surface {
public:
  string name;
  double length;
  double width;

  Surface(const string &name_, double length_, double width_) : name(name_), length(length_), width(width_) {}

  double get_area() const {
    return length * width;
  }
};

int main() {
  vector<Surface> surfaces;
  surfaces.emplace_back("aaa", 3, 3);
  surfaces.emplace_back("bbb", 1, 1);
  surfaces.emplace_back("ccc", 2, 2);

  // [] means capture list.
  sort(surfaces.begin(), surfaces.end(), [](const Surface &a, Surface &b) { return a.get_area() < b.get_area(); });
  for (Surface surface : surfaces)
    cout << surface.name << " Area: " << surface.get_area() << endl;
  cout << endl;

  sort(surfaces.begin(), surfaces.end(), [](const Surface &a, Surface &b) -> bool { return a.get_area() < b.get_area(); });
  for (Surface surface : surfaces)
    cout << surface.name << " Area: " << surface.get_area() << endl;
  cout << endl;
}
