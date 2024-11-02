#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
  for (auto &e : table) {
    out << e << " ";
  }
  return out;
}

int main() {

  vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  cout << "v1: " << v1 << endl;
  vector<int> v2 = {2, 3, 12, 14, 24};
  cout << "v2: " << v2 << endl;

  // Swap v1 with v2
  swap(v1, v2);
  cout << "After swap:" << endl;
  cout << "v1: " << v1 << endl;
  cout << "v2: " << v2 << endl;

  // Copy v2 to back of v1
  auto old_size = v1.size();
  v1.resize(v1.size() + v2.size());
  copy(v2.begin(), v2.end(), v1.begin() + old_size);
  cout << "Now v1 is equal to v1 + v2: " << v1 << endl;

  // Switch elements [0, 5> and [5, 10>
  swap_ranges(v1.begin(), v1.begin() + 5, v1.begin() + 5);
  cout << "v1, swap elements [0, 5> [5, 10>: " << v1 << endl;

  // Add int 3 to the 5 first elements
  fill(v1.begin(), v1.begin() + 5, 3);
  cout << "v1 with the 5 first elements changed to 3: " << v1 << endl;

  // New vector where all the numbers 3 are switched with 300
  vector<int> copy;
  copy.resize(v1.size());
  replace_copy(v1.begin(), v1.end(), copy.begin(), 3, 300);
  cout << "Copy: " << copy << endl;

  // Reverse v1
  vector<int> v1_reversed(v1.size());
  reverse_copy(v1.begin(), v1.end(), v1_reversed.begin());
  cout << "V1 reversed: " << v1_reversed << endl;

  // Rotate v1 3 positions
  vector<int> table;
  table.emplace_back(1);
  table.emplace_back(2);
  table.emplace_back(3);
  for (size_t i = 0; i < 7; ++i) {
    next_permutation(table.begin(), table.end());
    cout << "Permutation: " << (i + 1) << ": ";
    cout << table << endl;
  }
}
