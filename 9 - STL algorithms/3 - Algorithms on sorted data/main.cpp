#include <algorithm>
#include <iostream>
#include <string>
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

  // Binary search
  if (binary_search(v1.begin(), v1.end(), 17)) {
    cout << "17 exist in v1" << endl;
  } else {
    cout << "17 do exist in v1" << endl;
  }

  // Find index
  auto pos = lower_bound(v1.begin(), v1.end(), 17);
  cout << "17 is located at index: " << (pos - v1.begin()) << " in v1" << endl;

  // Insert
  auto v3 = v2;
  pos = lower_bound(v3.begin(), v3.end(), 25);
  cout << "25 should be placed at index: " << (pos - v3.begin()) << endl;
  v3.insert(pos, 25);
  cout << "v3 is equal to v2 with 25 inserted: " << v3 << endl;

  // Includes
  if (includes(v1.begin(), v1.end(), v2.begin() + 1, v2.begin() + 3)) {
    cout << "V2 index 1 to 3 is in v1" << endl;
  } else {
    cout << "V2 index 1 to 3 is not in v1" << endl;
  }

  // Merging
  vector<int> result;
  result.resize(v1.size() + v2.size());
  merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
  cout << "v1 and v2 merged, without duplicates: " << result << endl;

  // Remove duplicates from merged results
  auto end = unique(result.begin(), result.end());
  result.erase(end, result.end());
  cout << "v1 and v2 merged, without duplicates: " << result << endl;

  // Amount of operations
  result.resize(v1.size() + v2.size());
  end = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
  result.erase(end, result.end());
  cout << "v1 union v2: " << result << endl;

  result.resize(v1.size() + v2.size());
  end = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());
  result.erase(end, result.end());
  cout << "v1 intersection v2: " << result << endl;
}
