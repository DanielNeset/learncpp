

class SingeltonCLass {
  SingeltonCLass() {}

public:
  static SingeltonCLass &get() {
    static SingeltonCLass instance;
    return instance;
  }
};

int main() {
  // A instance of a SingeltonClass is created and returned
  SingeltonCLass::get();
  // Return the already created SingeltonClass
  SingeltonCLass::get();
}
