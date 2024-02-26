#ifndef VECTOR_HPP
#define VECTOR_HPP

// Header only module
template <class T>
class Vector {
  int size;
  int capacity;
  T *arr;
  void re_allocate() {
    capacity *= 2;
    T *newArr = new T[capacity];
    for (int i = 0; i < size; ++i) newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
  }

 public:
  Vector() : size(0), capacity(10), arr(new T[capacity]) {}
  Vector(int size) : size(size), capacity(2 * size), arr(new T[capacity]) {}
  Vector(int size, T value)
      : size(size), capacity(2 * size), arr(new T[capacity]) {
    for (int i = 0; i < size; ++i) arr[i] = value;
  }
  ~Vector() { delete[] arr; }
  Vector(const Vector &other) {
    size = other.size;
    capacity = other.capacity;
    arr = new T[capacity];
    for (int i = 0; i < size; ++i) arr[i] = other.arr[i];
  }
  Vector &operator=(const Vector &other);
  void push_back(T value) {
    if (size == capacity) re_allocate();
    arr[size] = value;
    ++size;
  }
  void pop_back() { --size; }
  T &at(int index) { return arr[index]; }
  int getSize() const { return size; }
  T back() { return arr[size - 1]; }
};

template <class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
  size = other.size;
  capacity = other.capacity;
  delete[] arr;
  arr = new T[capacity];
  for (int i = 0; i < size; ++i) arr[i] = other.arr[i];
  return *this;
}

#endif  // VECTOR_HPP
