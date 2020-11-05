#include "pQueueADT.h"
#include <iostream>
#include <vector>

using namespace std;

class priorityQueueSorted: public pQueue{

 private:
  vector<int> q;

 public:
  priorityQueueSorted();
  int top();
  void pop();
  void push(int);
  int size();
  bool empty();

};
