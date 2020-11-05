#ifndef STACK_F
#define STACK_F

class Stack{
 public:
  virtual void push(int) = 0;
  virtual int pop() = 0;
  virtual bool isEmpty() = 0;
};

#endif
