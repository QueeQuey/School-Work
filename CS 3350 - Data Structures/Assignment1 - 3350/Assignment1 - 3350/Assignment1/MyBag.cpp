#include "MyBag.h"
#include <vector>

MyBag::MyBag() : ArrayBag<std::string>() {}

void MyBag::removeAll(string removedItem){
	//Checks to see if the bag is empty
	if (this->isEmpty() || this->getCurrentSize == 0) {
		cout << "Bag is empty! Can't remove all \n";
	}
	//Checks to see if the item that is requesting to be cleared is actually there
	else if (this->contains(removedItem)) {
		cout << "Bag doesn't contain that item! Can't remove. \n";
	}
	//Finally goes through the Array and uses the remove command to delete the entries.
	else if (this->isEmpty()) {
		for (int i = 0; i < this->getCurrentSize(); i++) {
			if(this->items[i] == removedItem) {
				this->remove(i);
			}	
		}
	}
	/*
	* 
	*/
}