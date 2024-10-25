#include <iostream>

using namespace std;

template <typename Type>
class Point {
public:
  Type x, y, z;
  Point(Type x, Type y, Type z) : x(x), y(y), z(z) {}

  Point operator+(const Point &other) {
    Point point = *this;
    point.x += other.x;
    point.y += other.y;
    point.z += other.z;
    return point;
  }

  friend ostream &operator<<(ostream &os, const Point &point) {
    return os << "(" << point.x << ", " << point.y << ", " << point.z << ")";
  }
};

int main() {
  {
    Point<int> p1(1, 2, 3), p2(2, 2, 2);

    cout << (p1 + p2) << endl;
  }
  {
    Point<double> p1(1.5, 2.5, 3.5), p2(2.0, 2.0, 2.0);

    cout << (p1 + p2) << endl;
  }
}
