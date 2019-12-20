// Alexander Stern
// acs4wq
// 2/4/19
// postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <string>
#include "List.h"
#include "stack.h"
using namespace std;

class postfixCalculator {
 public:
  postfixCalculator();
  void pushNum(int e);
  int getTopValue();
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
  void remove();
  void print();


 private:
  stack myStack;


};

#endif
