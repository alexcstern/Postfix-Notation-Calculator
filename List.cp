// Alexander Stern
// acs4wq
// 1/25/19
// List.cpp

#include <iostream>
#include <string>
#include "List.h"
using namespace std;

List::List() {
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
  count = 0;
  
}


List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

bool List::isEmpty() const {
  if (count == 0)
    return true;
  return false;
}

void List::makeEmpty() {
  ListItr remover(head->next);
  while (!remover.isPastEnd()) {
    remover.moveForward();
    delete remover.current->previous;
  }
  head->next = tail;
  tail->previous = head;
  count = 0;
}

ListItr List::first() {
  ListItr firstItr(head->next);
  return firstItr;
}

ListItr List::last() {
  ListItr lastItr(tail->previous);
  return lastItr;
}

void List::insertAfter(int x, ListItr position) {
  ListNode *newNode = new ListNode();
  newNode->value = x;
  position.current->next->previous = newNode;
  newNode->next = position.current->next;
  position.current->next = newNode;
  newNode->previous = position.current;
  count++;
}

void List::insertBefore(int x, ListItr position) {
  ListNode *newNode = new ListNode();
  newNode->value = x;
  position.current->previous->next = newNode;
  newNode->previous = position.current->previous;
  newNode->next = position.current;
  position.current->previous = newNode; 
  count++;
}

void List::insertAtTail(int x) {
  ListNode *newNode = new ListNode();
  newNode->value = x;
  tail->previous->next = newNode;
  newNode->previous = tail->previous;
  newNode->next = tail;
  tail->previous = newNode;
  count++;
  
}

void List::remove(int x) {
  ListItr foundItr = find(x);
  foundItr.current->previous->next = foundItr.current->next;
  foundItr.current->next->previous = foundItr.current->previous;
  count--;
  delete foundItr.current;
}

ListItr List::find(int x) {
  ListItr findItr(head->next);
  while (findItr.retrieve() != x && !(findItr.isPastEnd())) {
    findItr.moveForward();
  }
  return findItr;
}

int List::size() const {
  return count;
}
