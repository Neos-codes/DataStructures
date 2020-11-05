#include "ListADT.h"

class linkedList: public List{

 public:
  linkedList();
  void push_back(int);
  int at(int);
  int size();

 private:
  nodo *head;
  int top;
  int max;
  int tail;

}
