#include <iostream>
using namespace std;

class List {
  int size;
  int* arr;

 public:
  List() {
    size = 0;
    arr = nullptr;
  }

  List(int count) {
    this->size = count;
    // dynamic data
    arr = new int[count];
  }

  List(int count, int value = 0) {
    this->size = count;
    arr = new int[count];
    for (int i = 0; i < count; ++i) arr[i] = value;
  }

  // copy constructor
  List(const List& other) {
    size = other.size;
    arr = new int[size];
    for (int i = 0; i < size; ++i) arr[i] = other.arr[i];
  }

  // destructor
  ~List() { delete[] arr; }

  // Copy assignment operator overloading
  // return List & reference to allow assignment to be used in expressions
  // e.g. cout << (obj1 = obj2) << endl;
  List& operator=(const List& other) {
    size = other.size;
    delete[] arr;
    arr = new int[size];
    for (int i = 0; i < size; ++i) arr[i] = other.arr[i];
    return *this;
  }

  int &at(int index) const { return arr[index]; }

  int getSize() const { return size; }

  void print() const {
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;
  }
};

// Helper functions
// use the reference parameter will avoid object copy
void print(const List &obj) {
  // getSize must be const to allow this
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
  List list(5, 10);  // the constructor taking two int values is triggered

  List list2(list);  // copy constructor is triggered
  List list3;  // the default constructor will be triggered

  list3 = list;  // default assignment operator is triggered

  list.print(); // 10 10 10 10 10
  list2.print(); // 10 10 10 10 10
  list3.print(); // 10 10 10 10 10

  list.at(4) = 1; // modify the 5th value

  list.print();  // 10 10 10 10 1
  list2.print(); // 10 10 10 10 10
  list3.print(); // 10 10 10 10 10

  return EXIT_SUCCESS;
}