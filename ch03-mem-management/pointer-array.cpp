int main() {
  State **states;  // 1d array of pointers to the state object
  // State states[][]; // 2d array of object, logically correct
  // State *states[];  // 1d array of pointers to the state object

  State *states1; // 1d array of object
  // State state[];  // 1d array of object

  states1 = new State[100];
  for (int i = 0; i < 100; i++)
    states1[i] = State("Alabama");  // = should be overloaded if State class has dynamic date
  states[i].method1();
  delete [] states1;

  states = new State *[100];
  for (int i = 0; i < 100; i++)
    states[i] = new State("Alabama");

  states[i]->method1();

  for (int i = 0; i < 100; i++)
    delete states[i];
  delete [] states;
}