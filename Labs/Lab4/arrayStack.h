#include "StackADT.h"

class arrayStack: public Stack{

 public:
  arrayStack();
  void push(int);
  int pop();
  bool isEmpty();

 private:
  int *start;
  int top;
  int max;
};
