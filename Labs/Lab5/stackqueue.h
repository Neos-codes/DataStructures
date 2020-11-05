#include <stack>
#include "queueADT.h"

using namespace std;

class stackqueue: public Queue{

 private:
  stack <int> s;
  stack <int> aux;
  
 public:
  stackqueue();
  void push(int);
  void pop();
  int front();
  int back();
  int size();
  bool isEmpty();
  friend class StackIt;
  
};

class StackIt{
 private:
  int count;
  stackqueue *aq;

 public:
  StackIt(stackqueue *q);
  bool hasNext();
  int nextInt();
  void reset();
};
