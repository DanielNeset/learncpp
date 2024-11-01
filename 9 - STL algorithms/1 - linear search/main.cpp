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

  auto pos = find(v1.begin(), v1.end(), 25);
  if (pos != v1.end()) {
    cout << "25 do exist in v1 at index: " << (pos - v1.begin()) << endl;
  } else {
    cout << "25 do not exist in v1" << endl;
  }

  auto start = v1.begin() + 2;
  auto end = v1.end() - 2;
  cout << "Searching in a section of the table: ";
  for (auto it = start; it != end; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  pos = find(start, end, 14);
  if (pos != end) {
    cout << "14 do exist in v1 at index " << (pos - v1.begin()) << endl;
  } else {
    cout << "14 do not exist in v1" << endl;
  }

  pos = find_first_of(v1.begin(), v1.end(), v2.begin() + 2, v2.end());
  cout << "First at index " << (pos - v1.begin()) << endl;

  pos = adjacent_find(v1.begin(), v1.end());
  cout << "Find to equal in index " << (pos - v1.begin()) << endl;

  cout << "v1 contains " << count(v1.begin(), v1.end(), 3) << " 3-numbers" << endl;
  cout << "Biggest value in v1 is " << *max_element(v1.begin(), v1.end()) << endl;
}
