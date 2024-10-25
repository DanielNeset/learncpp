#include <iostream>
#include <random>
#include <vector>

using namespace std;

template <typename Type>
size_t
search(const vector<Type> &table, Type search_element) {
  size_t pos = 0;
  while (pos < table.size() && table[pos] != search_element) {
    ++pos;
  }
  if (pos < table.size()) {
    return pos;
  } else {
    return -1;
  }
}

int main() {
  vector<double> table;
  for (size_t i = 0; i < 10; ++i) {
    table.emplace_back(static_cast<double>(i) / 2);
  }
  cout << search(table, 0.5) << endl;
  cout << search(table, 1.0) << endl;
  cout << search(table, static_cast<double>(1.0)) << endl;
}
