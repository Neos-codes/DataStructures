#include "pQueueADT.h"
#include <iostream>
#include <vector>

using namespace std;

class priorityQueueUnsorted: public pQueue{

 private:
  vector<int> q;
  int aux;

 public:
  priorityQueueUnsorted();
  int top();
  void pop();
  void push(int);
  int size();
  bool empty();

};
