#include <iostream>
#include <memory>

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
    // Same as: unique_ptr<A> a(new A());
    auto a = make_unique<A>();

    a = make_unique<A>();
    a = nullptr;
    a = make_unique<A>();
  }

  cout << "Scope has ended" << endl;
}
