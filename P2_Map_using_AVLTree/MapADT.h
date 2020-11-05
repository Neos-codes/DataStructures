#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <iostream>
#include <ctime>
#ifndef MAP_H
#define MAP_H

using namespace std;



class MapADT{
	public:
		virtual void insert(pair<string,int> newPair) = 0;
		virtual void erase(string key) = 0;
		virtual int at(string key) = 0;
		virtual int size() = 0;
		virtual bool empty() = 0;
};

#endif


