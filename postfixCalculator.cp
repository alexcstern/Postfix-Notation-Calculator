// Alexander Stern
// acs4wq
// 2/4/19
// postfixCalculator.cpp

#include "postfixCalculator.h"
#include <iostream>
#include <string>
#include "List.h"
using namespace std;

postfixCalculator::postfixCalculator() {

}

void postfixCalculator::pushNum(int e) {
  myStack.push(e);
}

int postfixCalculator::getTopValue() {
  return myStack.top();
}

void postfixCalculator::add() {
  int temp1 = myStack.top();
  myStack.pop();
  int temp2 = myStack.top();
  myStack.pop();
  int result = temp1 + temp2;
  myStack.push(result);
}

void postfixCalculator::subtract() {
  int temp1 = myStack.top();
  myStack.pop();
  int temp2 = myStack.top();
  myStack.pop();
  int result = temp2 - temp1;
  myStack.push(result);
}

void postfixCalculator::multiply() {
  int temp1 = myStack.top();
  myStack.pop();
  int temp2 = myStack.top();
  myStack.pop();
  int result = temp1 * temp2;
  myStack.push(result);
}

void postfixCalculator::divide() {
  int temp1 = myStack.top();
  myStack.pop();
  int temp2 = myStack.top();
  myStack.pop();
  int result = temp2 / temp1;
  myStack.push(result);
}

void postfixCalculator::negate() {
  myStack.push(-1);
  this->multiply();
}

void postfixCalculator::remove() {
  myStack.pop();
}

void postfixCalculator::print() {
  string toPrint = "";
  ListItr printItr = myStack.first();
  while (!printItr.isPastEnd()) {
    int temp = printItr.retrieve();
    toPrint += to_string(temp) + " ";
    printItr.moveForward();
  }
  cout << toPrint << endl;
}
