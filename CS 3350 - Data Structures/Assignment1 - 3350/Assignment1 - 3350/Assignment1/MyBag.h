//implement MyBag. h here

#include <vector>

#ifndef MY_BAG_
#define MY_BAG_
#include "ArrayBag.h"
class MyBag : public ArrayBag<std::string> {
public: 
	MyBag();
	//MyBag();
	void removeAll(string removedItem);
};
#include "MyBag.cpp"
#endif