#include <iostream>
#include <memory>

using namespace std;

int main() {
  // p1 points to 2 on the heap
  unique_ptr<int> p1(new int(2));
  // p2 points to nullptr on the heap
  unique_ptr<int> p2;

  // p2 = p1 // Not allowed unique_ptr
  p2 = std::move(p1); // Move the pointer from p1 to p2. p1 contains nullptr

  if (!p1) {
    cout << "p1 cointains nullptr" << endl;
  }

  if (p2) {
    cout << "p2 has the address: " << p2.get() << " that contains the value: " << *p2 << endl;
  }
}
