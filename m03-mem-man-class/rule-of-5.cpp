#include <iostream>
using namespace std;

class List {
 private:
  int size;
  int* arr;

 public:
  List() {
    size = 0;
    arr = nullptr;
  }

  List(int count) {
    this->size = count;
    // dynamic data here
    arr = new int[count];
  }

  List(int count, int value) {
    this->size = count;
    arr = new int[count];
    for (int i = 0; i < count; ++i) arr[i] = value;
  }

  List(const List& other) {  // deep copy
    size = other.size;
    arr = new int[size];
    for (int i = 0; i < size; ++i) arr[i] = other.arr[i];
  }

  List(List&& other) {  // move constructor, shallow copy
    size = other.size;
    arr = other.arr;      // shallow copy
    other.arr = nullptr;  // disconnect the data from the original object
    other.size = 0;
  }

  ~List() {
    delete[] arr;
  }

  List& operator=(const List& other) {
    size = other.size;
    delete[] arr;
    arr = new int[size];
    for (int i = 0; i < size; ++i) arr[i] = other.arr[i];
    return *this;
  }

  List& operator=(List&& other) {  // move = operator
    size = other.size;
    delete[] arr;
    arr = other.arr;
    other.arr = nullptr;  // disconnect the data from the original object
    other.size = 0;
    return *this;
  }

  int &at(int index) const { return arr[index]; }

  int getSize() const { return size; }
};

// Helper functions
// use the reference parameter will avoid object copy
void print(const List &obj) {
  for (int i = 0; i < obj.getSize(); ++i) {
    cout << obj.at(i) << " ";
  }
  cout << endl;
}

// will trigger implicit assignment during parameter passing
void print1(List obj) {
  for (int i = 0; i < obj.getSize(); ++i) {
    cout << obj.at(i) << " ";
  }
  cout << endl;
}

int main() {
  List obj1(10, 1);
  List obj2 = obj1;  // implicit call of the copy constructor
  List obj3(obj1);   // explicit call of the copy constructor
  List obj4;
  obj4 = obj1;  // = operator overloading
  print(obj1);

  // Why rule of 5
  // limitation of rule of 3
  // clone constructor with deep copy is done on a disposable object, it is a
  // waste because you can reuse the array from the disposable object
  List obj5 = List(10, 1);

  // use of 'new' will create an object in heap
  // the pointer is duplicated, object is not, this is a good way
  List* obj6 = new List(10, 1);

  // introduce the move constructor and move = operator overloading
  // with the move constructor defined, it will be triggered here
  cout << "Trigger move constructor\n";
  List obj8 = List(10, 1);
  print(obj8);
  cout << "Trigger move assignment operator\n";
  List obj9;
  // with the move = operator overloading defined, it will be triggered here
  obj9 = List(10, 1);
  print(obj9);

  // implicit assignment happened during parameter passing
  // implicitly obj = obj1, triggering the = operator overloading because obj1
  // is not temporary
  cout << "Trigger copy = during parameter passing\n";
  print1(obj1);

  // implicitly obj = List(10, 10), triggering the move = operator
  // overloading
  cout << "Trigger move = during parameter passing\n";
  print1(List(10, 10));
}