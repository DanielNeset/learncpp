#include <memory>
#include <mutex>

using namespace std;

class ReferenceCountedSingeltonCLass {
  ReferenceCountedSingeltonCLass() {}

public:
  // If a instance is already in use, return cached instance, otherwise return a new instance.
  static shared_ptr<ReferenceCountedSingeltonCLass> get() {
    static weak_ptr<ReferenceCountedSingeltonCLass> cache;
    static mutex cache_mutex;
    // Needed to make this get() method thread safe.
    lock_guard<mutex> lock(cache_mutex);
    auto instance = cache.lock();
    if (!instance) {
      cache = instance = shared_ptr<ReferenceCountedSingeltonCLass>(new ReferenceCountedSingeltonCLass());
    }
    return instance;
  }
};

int main() {
  {
    // Instance is created
    auto s1 = ReferenceCountedSingeltonCLass::get();
    // Instance already crated, return instance
    auto s2 = ReferenceCountedSingeltonCLass::get();
    // Instance is destroyed
  }
  // Instance is created
  auto s3 = ReferenceCountedSingeltonCLass::get();
}
