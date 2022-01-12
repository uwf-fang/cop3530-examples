#include <iostream>
using namespace std;

class MyClass {
  int size;
  int* arr;

 public:
  MyClass() {
    size = 0;
    arr = nullptr;
  }

  MyClass(int size) {
    this->size = size;
    // dynamic data
    arr = new int[size];
  }

  MyClass(int size, int initVal) {
    this->size = size;
    // dynamic data
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = initVal;
  }

  // copy constructor
  MyClass(const MyClass& other);

  // destructor
  ~MyClass() { delete[] arr; }

  // Copy assignment operator overlooding
  // return MyClass & reference to allow assignment to be used in expressions
  // e.g. cout << (obj1 = obj2) << endl;
  MyClass& operator=(const MyClass& other) {
    size = other.size;
    if (arr != nullptr) delete[] arr;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = other.arr[i];
    return *this;
  }

  int at(int index) const { return arr[index]; }

  int getSize() const { return size; }
};

MyClass::MyClass(const MyClass& other) {
    size = other.size;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = other.arr[i];
  }

// use the reference parameter will avoid object copy
void print(const MyClass &obj) {
  // getSize must be const to allow this
  for (int i = 0; i < obj.getSize(); i++) {
    cout << obj.at(i) << " ";
  }
  cout << endl;
}

// will trigger implicit assignment during parameter passing
void print1(MyClass obj) {
  for (int i = 0; i < obj.getSize(); i++) {
    cout << obj.at(i) << " ";
  }
  cout << endl;
}

int main() {
  MyClass obj1(10, 1);
  MyClass obj2 = obj1;  // implicit call of the copy constructor
  MyClass obj3(obj1);   // explicit call of the copy constructor
  MyClass obj4;
  obj4 = obj1;  // = operator overloading triggered
  print(obj1);  // copy constructor triggered during the parameter passing
}