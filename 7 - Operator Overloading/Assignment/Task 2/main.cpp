#include "set.hpp"
#include <iostream>

using namespace std;

int main() {

  Set set1;
  set1 += 1;
  set1 += 4;
  set1 += 3;

  Set set2;
  set2 += 4;
  set2 += 7;

  cout << "Set 1: " << set1 << endl;
  cout << "Set 2: " << set2 << endl;

  Set unionSet = set1 + set2;
  cout << "Union of Set 1 and Set 2: " << unionSet << endl;

  unionSet += 10;
  cout << "After adding 10 of the union set: " << unionSet << endl;

  set1 = set2;
  cout << "Set 1 after assignment from Set2: " << set1 << endl;

  return 0;
}
