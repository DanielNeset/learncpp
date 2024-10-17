#include "set.hpp"

Set Set::operator+(const Set &other) const {
  Set result = *this;
  for (int value : other.elements) {
    if (!result.contains(value)) {
      result.elements.push_back(value);
    }
  }
  return result;
}

Set &Set::operator+=(int value) {
  if (!contains(value)) {
    elements.push_back(value);
  }
  return *this;
}

Set &Set::operator=(const Set &other) {
  if (this != &other) {
    elements = other.elements;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Set &set) {
  os << "{ ";
  for (int value : set.elements) {
    os << value << " ";
  }
  os << "}";
  return os;
}

bool Set::contains(int value) const {
  return std::find(elements.begin(), elements.end(), value) != elements.end();
}
