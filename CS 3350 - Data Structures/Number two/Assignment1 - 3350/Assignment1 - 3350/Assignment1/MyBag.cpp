#include "MyBag.h"
#include <vector>
#include <iostream>
#include <string>
template<class ItemType>
MyBag<ItemType>::MyBag() : ArrayBag<ItemType>() {};

template<class ItemType>
void MyBag<ItemType>::removeAll(ItemType& removedItem) {
	//Checks to see if the bag is empty
	if (this->isEmpty()) {
		cout << "Bag is empty! Can't remove anything. \n";
	}
	//Checks to see if the item that is requesting to be cleared is actually there
	else if (!this->contains(removedItem)) {
		cout << "Bag doesn't contain that item! Can't remove. \n";
	}
	else {
		int amount = this->getFrequencyOf(removedItem);
		for (int i = 0; i < amount; i++) {
			this->remove(removedItem);
		}
	}
	/*Made a mistake reading the documentation, thinking that the items[] was public.
	* but here is what I had.
	//Finally goes through the Array and uses the remove command to delete the entries.
	else if (this->isEmpty()) {
		for (int i = 0; i < this->getCurrentSize(); i++) {
			if (this->items[i] == removedItem) {
				this->remove(items[i]);
			}
		}
	}*/
}