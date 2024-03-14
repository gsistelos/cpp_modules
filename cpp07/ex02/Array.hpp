#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T> class Array {
public:
  Array(void);
  Array(unsigned int size);
  ~Array();

  Array(const Array<T> &rhs);
  Array<T> &operator=(const Array<T> &rhs);

  T &operator[](unsigned int index);

  unsigned int size(void) const;

private:
  T *_array;
  unsigned int _size;
};

template <class T> Array<T>::Array(void) : _array(NULL), _size(0) {}

template <class T>
Array<T>::Array(unsigned int size) : _array(new T[size]), _size(size) {}

template <class T> Array<T>::~Array() { delete[] _array; }

template <class T>
Array<T>::Array(const Array<T> &rhs)
    : _array(new T[rhs._size]), _size(rhs._size) {
  for (unsigned int i = 0; i < _size; i++) {
    _array[i] = rhs._array[i];
  }
}

template <class T> Array<T> &Array<T>::operator=(const Array<T> &rhs) {
  if (this != &rhs) {
    delete[] _array;
    _array = new T[rhs._size];
    _size = rhs._size;
    for (unsigned int i = 0; i < _size; i++) {
      _array[i] = rhs._array[i];
    }
  }
  return *this;
}

template <class T> T &Array<T>::operator[](unsigned int index) {
  if (index >= _size) {
    throw std::out_of_range("Index out of range");
  }
  return _array[index];
}

template <class T> unsigned int Array<T>::size(void) const { return _size; }

template <class T> std::ostream &operator<<(std::ostream &out, Array<T> &rhs) {
  for (unsigned int i = 0; i < rhs.size(); i++) {
    out << rhs[i] << " ";
  }
  return out;
}

#endif // ARRAY_HPP
