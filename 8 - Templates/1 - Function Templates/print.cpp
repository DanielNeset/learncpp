#include <iostream>

using namespace std;

template <typename Type1, typename Type2>
void print(const Type1 &first, const Type2 &secound) {
  cout << first << " " << secound << endl;
}

int main() {
  int number = 5;
  print("The answer is", number);
  print(100, 0.05);
  print('\n', "Hey");
}
