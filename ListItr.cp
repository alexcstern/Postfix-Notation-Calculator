// Alexander Stern
// acs4wq
// 1/25/19
// ListItr.cpp

#include <iostream>
#include <string>
#include "ListItr.h"
using namespace std;


ListItr::ListItr() {
  current = NULL;
}

ListItr::ListItr(ListNode *theNode) {
  current = theNode;

}

bool ListItr::isPastEnd() const {
  if (current->next)
    return false;
  return true;
}

bool ListItr::isPastBeginning() const {
  if (current->previous)
    return false;
  return true;
}

void ListItr::moveForward() {
  if (!(isPastEnd()))
    current = current->next;
}

void ListItr::moveBackward() {
  if (!isPastBeginning())
    current = current->previous;
}

int ListItr::retrieve() const {
  return current->value;
}



