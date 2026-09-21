// Program #1 – Product Inventory Program
// Programmer:  Layne Woodruff
// Class:  CS 2020 1001, Spring 2023
// Due Date: Feb 19, 2023
// Purpose of program:  
//  The purpose of the program is to create a mock inventory system that
//  allows users to add or alter existing entries

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int menu();


struct Product{
	string name;    // Name
	int qty;        // quantity is the number of items in stock
	double price;  // price to purchase one item
};

void addprod(vector <Product>& inventory);
void showinventory(vector<Product>& inventory);
void showoutofstock(vector<Product>& inventory);
void showavgprice(vector<Product>& inventory);
void showhiprice(vector<Product>& inventory);

int main() {
	int inputInt = 0;
	vector<Product> bginventory;

	do {
		inputInt = menu();
		if (inputInt == 1) {
			addprod(bginventory);
		}
		else if (inputInt == 2) {
			showavgprice(bginventory);
		}
		else if (inputInt == 3) {
			showhiprice(bginventory);
		}
		else if (inputInt == 4) {
			showoutofstock(bginventory);
		}
		else if (inputInt == 5) {
			showinventory(bginventory);
		}
		else if (inputInt == 6) {
			return 0;
		}
	} while (inputInt != 6);

}


int menu() {
	int choice = 0;
	cout << "1. Add new product\n";
	cout << "2. Average Price\n";
	cout << "3. Highest Price\n";
	cout << "4. Display out of stock\n";
	cout << "5. Display all products in inventory\n";
	cout << "6. Exit the program\n\n";
	cout << "Enter your choice: ";
	while (choice > 6 || choice < 1) {
		cin >> choice;
		if (choice > 6 || choice < 1) {
			cout << "invalid input" << endl;
			cout << "Enter your choice: ";
		}
	}

	return choice;
}


void addprod(vector<Product>& inventory) {
	string inputString;
	int inputInt;
	double inputDouble;
	//Temp product to add to the end of the vector of products
	Product tempProduct;

	//Input for each item, followed by adding it to tempProduct
	cout << "Product Name: ";
	cin >> inputString;
	tempProduct.name = inputString;
	cout << endl;

	cout << "Product Quantity: ";
	cin >> inputInt;
	tempProduct.qty = inputInt;
	cout << endl;

	cout << "Product Price: ";
	cin >> inputDouble;
	tempProduct.price = inputDouble;
	cout << endl;

	inventory.push_back(tempProduct);

}


void showavgprice(vector<Product>& inventory) {
	int vectorLength = inventory.size();
	int i;
	double totalPrice = 0;
	double avgPrice;
	for (i = 0; i < vectorLength; i++) {
		totalPrice = totalPrice + inventory.at(i).price;
	}
	avgPrice = totalPrice / i;
	//return avgPrice;
	cout << endl;
	cout << "The average price is: " << avgPrice << endl;
}


void showhiprice(vector<Product>& inventory) {
	int vectorLength = inventory.size();
	int i;
	double hiPrice = 0;
	int hiIndex = 0;
	for (i = 0; i < vectorLength; i++) {
		if (inventory.at(i).price > hiPrice) {
			hiPrice = inventory.at(i).price;
			hiIndex = i;
		}
	}
	//return hiPrice
	cout << endl;
	cout << "The highest price is: " << inventory.at(hiIndex).name << " for $" << hiPrice << endl;
}

void showoutofstock(vector<Product>& inventory) {
	int vectorLength = inventory.size();
	int i;
	for (i = 0; i < vectorLength; i++) {
		if (inventory.at(i).qty == 0) {
			cout << inventory.at(i).name << endl;
		}
	}
}

/*
* Need to do fancy formatting for output.
*/

void showinventory(vector<Product>& inventory){
	int vectorLength = inventory.size();
	int i;
	for (i = 0; i < vectorLength; i++) {
		cout << "Name:" << inventory.at(i).name << endl;
		cout << "Quantity:" << inventory.at(i).qty << endl;
		cout << "Price:" << inventory.at(i).price << endl;
		cout << endl;
	}
}