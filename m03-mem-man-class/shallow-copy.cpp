#include <iostream>

using namespace std;

// List class
//   Only has a destructor
//   Missing copy constructor and copy assignment operator overloading
class List {
 private:
  int *array;
  int size;
 public:
  List();
  List(int count, int value = 0);
  ~List();
  int &at(int index);
  void print();
};

List::List() {
  array = nullptr;
  size = 0;
}

List::List(int count, int value) {
  size = count;
  array = new int[size];
  for (int i = 0; i < count; ++i)
    array[i] = value;
}

List::~List() {delete [] array;}

int &List::at(int index) {
  return array[index];
}

void List::print() {
  for (int i = 0; i < size; ++i)
    cout << array[i] << " ";
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

  // Three outputs will be the same with the 5th value modified
  list.print();  // 10 10 10 10 1
  list2.print(); // 10 10 10 10 1
  list3.print(); // 10 10 10 10 1

  // must add a \n or endl to flush the text to the screen before the crash
  cout << "Expect memory error after because of the double/triple free of the same data.\n";
  return EXIT_SUCCESS;
}