#include <iostream>
#include <memory> // For unique_ptr

using namespace std;

class A {
public:
  A() {
    cout << "Object is created" << endl;
  }
  ~A() {
    cout << "Object is removed" << endl;
  }
};

int main() {
  {
    // Object created on the heap, when a is removed it releases the anonymous object.
    unique_ptr<A> a(new A());
  }
  cout << "Scope has ended" << endl;
}
