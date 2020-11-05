#ifndef ADTQUEUE_H
#define ADTQUEUE_H

class Queue{
 public:
  virtual void push(int) = 0;
  virtual void pop() = 0;
  virtual int front() = 0;
  virtual int back() = 0;
  virtual int size() = 0;
  virtual bool isEmpty() = 0;
};

#endif
