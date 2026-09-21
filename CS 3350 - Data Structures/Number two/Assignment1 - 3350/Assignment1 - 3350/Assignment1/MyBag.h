//implement MyBag. h here
#include <vector>

#ifndef MY_BAG_
#define MY_BAG_
#include <string>
#include "ArrayBag.h"
template<class ItemType>
class MyBag : public ArrayBag<ItemType> {
public:
	MyBag();
	//void removeAll(string& removedItem);
	void removeAll(ItemType& removedItem);
};
#include "MyBag.cpp"
#endif