#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<double> numbers;

  numbers.emplace_back(5.5);
  numbers.emplace_back(6.4);
  numbers.emplace_back(7.3);
  numbers.emplace_back(8.2);
  numbers.emplace_back(9.1);

  cout << "Numbers back: " << numbers.back() << " Numbers front: " << numbers.front() << endl;

  numbers.emplace(numbers.begin() + 1, 2.2);
  cout << "Numbers back: " << numbers.back() << " Numbers front: " << numbers.front() << endl;

  auto it = find(numbers.begin(), numbers.end(), 2.2);

  // Returns numbers.end() if it cannot find the value.

  if (it != numbers.end()) {
    cout << "Found value: " << *it << endl;
  } else {
    cout << "Value not found." << endl;
  }

  return 0;
}
