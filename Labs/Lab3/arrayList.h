#include "ListADT.h"

class arrayList: public List{

 public:
  arrayList();
  void push_back(int);
  int at(int);
  int size();

 private:
  int *start;
  int top;
  int max;

};
