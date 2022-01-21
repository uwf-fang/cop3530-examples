#include <iostream>
#include <string>

using namespace std;

class State {
 private:
  string name;
 public:
  State();
  State(const string &name);
  string getName() const;
  void setName(const string &name);
};

int main() {
  State *states1; // 1d array of object

  states1 = new State[100];
  for (int i = 0; i < 100; i++)
    states1[i] = State();  // make a temporary object (rvalue) and assign, = should be overloaded if State class has dynamic date
  cout << states1[0].getName();
  delete [] states1;

  // expect 1d array of pointers to the state object
  // can be also used as 2d array of objects
  State **states2;

  states2 = new State *[100];
  for (int i = 0; i < 100; i++)
    states2[i] = new State();

  cout << states2[0]->getName();

  for (int i = 0; i < 100; i++)
    delete states2[i];
  delete [] states2;
}