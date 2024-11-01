#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}

int main() {
  vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  cout << "v1: " << v1 << endl;

  vector<int> v2 = {2, 3, 12, 14, 24};
  cout << "v2: " << v2 << endl;

  // Part a
  auto it = find_if(v1.begin(), v1.end(), [](int x) { return x > 15; });
  if (it != v1.end()) {
    cout << "First element in v1 that is greater than 15: " << *it << endl;
  } else {
    cout << "No element in v1 is greater than 15." << endl;
  }

  // Part b
  bool approx_equal_5 = equal(v1.begin(), v1.begin() + 5, v2.begin(), [](int a, int b) {
    return abs(a - b) <= 2;
  });
  cout << "Interval [v1.begin(), v1.begin() + 5> is approximately equal to v2: " << boolalpha << approx_equal_5 << endl;

  bool approx_equal_4 = equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int a, int b) {
    return abs(a - b) <= 2;
  });
  cout << "Interval [v1.begin(), v1.begin() + 4> is approximately equal to v2: " << boolalpha << approx_equal_4 << endl;

  // Part c
  vector<int> v1_modified(v1.size());
  replace_copy_if(v1.begin(), v1.end(), v1_modified.begin(), [](int x) { return x % 2 != 0; }, 100);
  cout << "v1 after replacing odd numbers with 100" << endl;
  cout << v1_modified << endl;
}
