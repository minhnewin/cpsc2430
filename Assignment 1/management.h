// management.h

#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <iostream>
#include <string>
using namespace std;

class Queue {    
public:    
  Queue();
  Queue(const Queue &);
  Queue& operator=(const Queue &);
  ~Queue();
  void enqueue(string, string);
  void dequeue();
  string peekName() const;
  string peekType() const;
  bool empty() const;
  int size() const;
private:
  struct Node {
    string type; // animal type
    string name; // animal name
    Node *next; // helper node to go through linked list
  };
  Node *front; // helper node to mark front of queue
  Node *rear; // helper node to mark rear of queue
  int numAnimals; // integer value to keep track of elements in linked list
  void clear();
};

#endif
