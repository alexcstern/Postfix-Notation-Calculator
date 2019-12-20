// Alexander Stern
// acs4wq
// stack.h
// 2/6/19

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

class stack {

 public:
  stack();
  void push(int e);
  int top();
  void pop();
  void empty();
  ListItr first();

 private:
  List sList;




};

#endif
