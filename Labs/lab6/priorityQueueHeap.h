#include "pQueueADT.h"
#include <iostream>
#include <vector>

using namespace std;

class priorityQueueHeap: public pQueue{

 private:
  vector<int> q;
  int aux;

 public:
  priorityQueueHeap();
  int top();
  void pop();
  void push(int);
  int size();
  bool empty();

};
