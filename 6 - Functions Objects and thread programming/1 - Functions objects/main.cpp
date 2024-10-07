#include <iostream>

using namespace std;

int main() {
  auto add = [](int a, int b) {
    return a + b;
  };
  function<int(int, uint)> addFucntion = [](int a, int b) {
    return a + b;
  };
  cout << add(2, 2) << endl;
  cout << add(3, 3) << endl;
}
