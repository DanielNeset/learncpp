#include <iostream>

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
    A *a = new A(); // Create a anonymous object on the heapen that a points to
    cout << "The object is not destroyed since the pointer exits the scope" << endl;
    delete a;
  }
  cout << "The Scope has ended" << endl;
}
