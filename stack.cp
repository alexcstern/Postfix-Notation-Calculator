// Alexander Stern
// acs4wq
// stack.cpp
// 2/6/19

#include <iostream>
#include <string>
#include "List.h"
#include "stack.h"
using namespace std;

stack::stack() {
  List sList = List();
}

void stack::push(int e) {
  sList.insertAtTail(e);
}

int stack::top() {
  ListItr topItr = sList.last();
  return topItr.retrieve();
}

void stack::pop() {
  ListItr topItr = sList.last();
  int popVal = topItr.retrieve();
  sList.remove(popVal);
}

void stack::empty() {
  sList.makeEmpty();
}

ListItr stack::first() {
  return sList.first();
}
