#ifndef TEMPLATE_DEMO_HPP
#define TEMPLATE_DEMO_HPP

// Header only module

// function templates
template<typename T>
T myMin(T, T);

template<typename T>
T myMin(T val1, T val2) {
  if (val1 > val2)
    return val2;
  else
    return val1;
}

// class templates
template<typename T>
class Min {
  T val1;
  T val2;
 public:
  // Inline constructor
  // do not need a template clause
  Min(T val1, T val2): val1(val1), val2(val2) {}

  // method declaration
  T getMin();
};

// class methods implementations, not inline
// must have a template clause
template<typename T>
T Min<T>::getMin() {
  if (val1 > val2)
    return val2;
  else
    return val1;
}

#endif