#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T> class Array {
public:
  Array(void) : _array(new T[0]), _size(0) {}

  Array(unsigned int size) : _array(new T[size]), _size(size) {
    for (unsigned int i = 0; i < _size; i++) {
      _array[i] = T();
    }
  }

  ~Array() { delete[] _array; }

  Array(const Array<T> &rhs) : _array(new T[rhs._size]), _size(rhs._size) {
    for (unsigned int i = 0; i < _size; i++) {
      _array[i] = rhs._array[i];
    }
  }

  Array<T> &operator=(const Array<T> &rhs) {
    if (this != &rhs) {
      _size = rhs._size;

      delete[] _array;
      _array = new T[_size];

      for (unsigned int i = 0; i < _size; i++) {
        _array[i] = rhs._array[i];
      }
    }

    return *this;
  }

  T &operator[](unsigned int index) const {
    if (index >= _size) {
      throw std::out_of_range("Index out of range");
    }

    return _array[index];
  }

  unsigned int size(void) const { return _size; }

private:
  T *_array;
  unsigned int _size;
};

template <class T> std::ostream &operator<<(std::ostream &out, Array<T> &rhs) {
  for (unsigned int i = 0; i < rhs.size(); i++) {
    out << rhs[i] << " ";
  }

  return out;
}

#endif /* ARRAY_HPP */
