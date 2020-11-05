#ifndef ADTPQUEUE_H
#define ADTPQUEUE_H

class pQueue{
  
 public:
  virtual int top() = 0;
  virtual void pop() = 0;
  virtual void push(int) = 0;
  virtual int size() = 0;
  virtual bool empty() = 0;
};


#endif
