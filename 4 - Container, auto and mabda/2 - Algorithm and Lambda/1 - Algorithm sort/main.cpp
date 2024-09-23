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

bool compare(const Surface &a, const Surface &b) {
  return a.get_area() < b.get_area();
}

int main() {
  vector<int> numbers;
  vector<Surface> surfaces;

  numbers.emplace_back(3);
  numbers.emplace_back(1);
  numbers.emplace_back(2);

  sort(numbers.begin(), numbers.end());

  for (auto &number : numbers) {
    cout << number << endl;
  }

  surfaces.emplace_back("aaa", 3, 3);
  surfaces.emplace_back("bbb", 1, 1);
  surfaces.emplace_back("ccc", 2, 2);

  sort(surfaces.begin(), surfaces.end(), compare);

  for (auto &surface : surfaces)
    cout << surface.name << " Area: " << surface.get_area() << endl;
  ;
}
