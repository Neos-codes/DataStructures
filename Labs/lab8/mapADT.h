#ifndef MAPADT_H
#define MAPADT_H
#include <iostream>
#include <utility>

using namespace std;

class map{
 public:
  virtual void insert(pair<string,int>) = 0;
  virtual void erase(string) = 0;
  virtual int at(string) = 0;
  virtual int size() = 0;
  virtual bool empty() = 0;

  
};

#endif
