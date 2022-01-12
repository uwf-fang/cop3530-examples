#include <iostream>

using namespace std;

class List {
 private:
  int *array;
  int size;
 public:
  List();
  List(int value, int repeat);
  ~List();
  void setValue(int index, int value);
  void print();
};

List::List() {
  array = nullptr;
  size = 0;
}

List::List(int value, int repeat) {
  size = repeat;
  array = new int[size];
  for (int i = 0; i < repeat; i++)
    array[i] = value;
}

List::~List() {delete [] array;}

void List::setValue(int index, int value) {
  array[index] = value;
}

void List::print() {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int main() {
  List list(5, 10);  // the constructor taking two int values is triggered
  // default copy constructor is triggered, same as List list2(list);
  List list2 = list;
  List list3;  // the default constructor will be triggered

  list3 = list;  // default assignment operater will be triggered, shallow copy

  list.print();
  list2.print();
  list3.print();

  list.setValue(4, 1);

  list.print();
  list2.print();
  list3.print();

  // must add a \n or endl to flush the text to the screen before the crash
  cout << "Expect memory error after because of the double/triple free of the same data.\n";
  return 0;
}