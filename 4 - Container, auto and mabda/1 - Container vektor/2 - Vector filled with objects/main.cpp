#include <iostream>
#include <vector>

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

  cout << "Number of surfaces: " << surfaces.size() << endl;

  for (size_t i = 0; i < surfaces.size(); ++i) {
    cout << surfaces[i].name << " areal: " << surfaces[i].get_area() << endl;
  }
  cout << endl;
  for (Surface &surface : surfaces) {
    cout << surface.name << " areal: " << surface.get_area() << endl;
  }
  cout << endl;
  for (auto &surface : surfaces) {
    cout << surface.name << " areal: " << surface.get_area() << endl;
  }
  cout << endl;
  for (auto it = surfaces.begin(); it != surfaces.end(); ++it)
    cout << (*it).name << " areal: " << (*it).get_area() << endl;
  cout << endl;
  for (auto it = surfaces.begin(); it != surfaces.end(); ++it)
    cout << it->name << " areal: " << it->get_area() << endl;
}
