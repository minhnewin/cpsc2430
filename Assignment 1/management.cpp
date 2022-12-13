// management.cpp

#include "management.h"
#include <assert.h>
#include <string>
using namespace std;

Queue::Queue() {
  front = nullptr;
  rear = nullptr;
  numAnimals = 0;
}

Queue::~Queue() {
  clear();
}

Queue::Queue(const Queue &obj) {
  numAnimals = 0;
  front = nullptr;
  rear = nullptr;
  Node * temp;
  temp = obj.front;
  while (temp != nullptr){
    enqueue(temp->type, temp->name);
    temp = temp->next;
  }
}

Queue& Queue::operator=(const Queue &obj) {
  if (this != &obj) {
    clear();
    numAnimals = 0;
    front = nullptr;
    rear = nullptr;
    Node * temp;
    temp = obj.front;
    while (temp != nullptr){
      enqueue(temp->type, temp->name);
      temp = temp->next;
    }
  }
  return *this;
}

void Queue::enqueue(string type, string name) {
  Node * newNode = new Node;
  newNode->type = type;
  newNode->name = name;
  newNode->next = nullptr;
  if (empty()) {
    front = newNode;
    rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
  numAnimals++;
}

void Queue::dequeue() {
  assert(!empty());
  Node * temp = front;
  front = front->next;
  delete temp;
  numAnimals--;
}

string Queue::peekName() const {
  assert(!empty());
  return front->name;
}

string Queue::peekType() const {
  assert(!empty());
  return front->type;
}

bool Queue::empty() const {
  return numAnimals == 0;
}

int Queue::size() const {
  return numAnimals;
}

void Queue::clear() {
  while (!empty())
    dequeue();
}
