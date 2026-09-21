// Program #1 – Product Inventory Program
// Programmer:  Layne Woodruff
// Class:  CS 2020 1001, Spring 2023
// Due Date: Feb 19, 2023
// Purpose of program:  
//  The purpose of the program is to create a mock inventory system that
//  allows users to add or alter existing entries

#include "Product.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int menu();
void addprod(vector <Product>& inventory);
void showinventory(vector<Product>& inventory);
void showoutofstock(vector<Product>& inventory);
void showavgprice(vector<Product>& inventory);
void showhiprice(vector<Product>& inventory);

int main() {
	int inputInt = 0;
	vector<Product> bginventory;
	
	do{
		inputInt = menu();
		if(inputInt == 1){
			addprod(bginventory);
		}
		else if(inputInt == 2){
			showavgprice(bginventory);
		}
		else if(inputInt == 3){
			showhiprice(bginventory);
		}
		else if(inputInt == 4){
			showoutofstock(bginventory);
		}
		else if(inputInt == 5){
			showinventory(bginventory);
		}
		else if (inputInt == 6) {
			return 0;
		}
	} while (inputInt != 6);

}


int menu(){
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


void addprod(vector<Product>& inventory){
	string inputString;
	int inputInt;
	double inputDouble;
	//Temp product to add to the end of the vector of products
	Product tempProduct;
	
	//Input for each item, followed by adding it to tempProduct
	cout << "Product Name: ";
	cin >> inputString;
	tempProduct.setname(inputString);
	cout << endl;
	
	cout << "Product Quantity: ";
	cin >> inputInt;
	tempProduct.setqty(inputInt);
	cout << endl;
	
	cout << "Product Price: ";
	cin >> inputDouble;
	tempProduct.setprice(inputDouble);
	cout << endl;

	inventory.push_back(tempProduct);

}



void showavgprice(vector<Product>& inventory) {
	int vectorLength = inventory.size() - 1;
	int i;
	double totalPrice = 0;
	double avgPrice;
	for (i = 0; i < vectorLength; i++) {
		totalPrice = totalPrice + inventory.at(i).getprice();
	}
	avgPrice = totalPrice / i;
	//return avgPrice;
}


void showhiprice(vector<Product>& inventory){
	int vectorLength = inventory.size() - 1;
	int i;
	double hiPrice = 0;
	for (i = 0; i < vectorLength; i++) {
		if (inventory.at(i).getprice() > hiPrice) {
			hiPrice = inventory.at(i).getprice();
		}
	}
	//return hiPrice
}

void showoutofstock(vector<Product>& inventory){
	int vectorLength = inventory.size() - 1;
	int i;
	for (i = 0; i < vectorLength; i++) {
		if (inventory.at(i).getqty() == 0) {
			cout << inventory.at(i).getname() << endl;
		}
	}
}

void showinventory(vector<Product>& inventory){
	int vectorLength = inventory.size() - 1;
	int i;
	for (i = 0; i < vectorLength; i++) {
		inventory.at(i).print();
		cout << endl;
	}
}
