#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

template <typename Type>
bool equal(Type a, Type b) {
  cout << "Using generic template version" << endl;
  return a == b;
}

bool equal(double a, double b) {
  cout << "Using specialized version for double" << endl;
  return fabs(a - b) < 0.00001;
}

int main() {
  int x = 5, y = 5;
  double a = 3.141592, b = 3.141593;

  cout << boolalpha << "equal(x, y): " << equal(x, y) << endl;
  cout << boolalpha << "equal(a, b): " << equal(a, b) << endl;

  return 0;
}
