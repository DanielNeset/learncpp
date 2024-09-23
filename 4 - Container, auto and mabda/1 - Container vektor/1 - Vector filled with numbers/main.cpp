#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> numbers;

  int number;
  cout << "Write a positive number (end with a 0): ";
  cin >> number;

  while (number > 0) {
    numbers.emplace_back(number);
    cin >> number;
  }

  cout << "You have written: " << numbers.size() << " number" << endl;
  for (size_t i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " ";
  }

  cout << endl;
}
