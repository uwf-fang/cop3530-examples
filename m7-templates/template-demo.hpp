#ifndef TEMPLATE_DEMO_HPP
#define TEMPLATE_DEMO_HPP

// function template
template<typename T>
T myMin(T, T);

template<typename T>
T myMin(T val1, T val2) {
  if (val1 > val2)
    return val2;
  else
    return val1;
}

// class template
template<typename T>
class Min {
  private:
  T val1;
  T val2;
  public:
  Min(T val1, T val2);
  T getMin();
};

// class methods implementations, not inline
template<typename T>
Min<T>::Min(T val1, T val2) {
  this->val1 = val1;
  this->val2 = val2;
}

template<typename T>
T Min<T>::getMin() {
  if (val1 > val2)
    return val2;
  else
    return val1;
}

#endif