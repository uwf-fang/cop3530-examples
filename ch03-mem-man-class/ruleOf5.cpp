#include <iostream>
using namespace std;

class MyClass {
 private:
  int size;
  int* arr;

 public:
  MyClass() {
    size = 0;
    arr = nullptr;
  }

  MyClass(int size) {
    this->size = size;
    // dynamic data here
    arr = new int[size];
  }

  MyClass(int size, int initVal) {
    this->size = size;
    // dynamic data here
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = initVal;
  }

  MyClass(const MyClass& other) {  // deep copy
    size = other.size;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = other.arr[i];
  }

  MyClass(MyClass&& other) {  // move constructor, shallow copy
    size = other.size;
    arr = other.arr;      // shallow copy
    other.arr = nullptr;  // disconnect the data from the original object
    other.size = 0;
  }

  ~MyClass() {
    if (arr != nullptr) delete[] arr;
  }

  MyClass& operator=(const MyClass& other) {
    size = other.size;
    if (arr != nullptr) delete[] arr;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = other.arr[i];
    return *this;
  }

  MyClass& operator=(MyClass&& other) {  // move = operator
    size = other.size;
    if (arr != nullptr) delete[] arr;
    arr = other.arr;
    other.arr = nullptr;  // disconnect the data from the original object
    other.size = 0;
    return *this;
  }

  int at(int index) const { return arr[index]; }

  int getSize() const { return size; }
};

// use the reference parameter will avoid object copy
void print(const MyClass &obj) {
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
  obj4 = obj1;  // = operator overloading
  print(obj1);

  // Why rule of 5
  // limitation of rule of 3
  // clone constructor with deep copy is done on a disposable object, it is a
  // waste because you can reuse the array from the disposable object
  MyClass obj5 = MyClass(10, 1);

  // use of 'new' will create an object in heap
  // the pointer is duplicated, object is not, this is a good way
  MyClass* obj6 = new MyClass(10, 1);

  // introduce the move constructor and move = operator overloading
  // with the move constructor defined, it will be triggered here
  cout << "Trigger move constructor\n";
  MyClass obj8 = MyClass(10, 1);
  print(obj8);
  cout << "Trigger move assignment operator\n";
  MyClass obj9;
  // with the move = operator overloading defined, it will be triggered here
  obj9 = MyClass(10, 1);
  print(obj9);

  // implicit assignment happened during parameter passing
  // implicitly obj = obj1, triggering the = operator overloading because obj1
  // is not temporary
  cout << "Trigger copy = during parameter passing\n";
  print1(obj1);

  // implicitly obj = MyClass(10, 10), triggering the move = operator
  // overloading
  cout << "Trigger move = during parameter passing\n";
  print1(MyClass(10, 10));
}