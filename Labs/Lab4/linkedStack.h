#include "StackADT.h"

typedef  struct node{
  int n;
  node *next;
}nodo;

class linkedStack: public Stack{
 public:
  linkedStack();
  void push(int);
  int pop();
  bool isEmpty();

 private:
  nodo *head;
  int tam;

};
