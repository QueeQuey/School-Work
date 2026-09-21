// Program #1 – Product Inventory Program
// Programmer:  Layne Woodruff
// Class:  CS 2020 1001, Spring 2023
// Due Date: Feb 19, 2023
// Purpose of program:  
//  The purpose of the program is to create a mock inventory system that
//  allows users to add entries and check all items, the average price of items, what's out of stock, and what the most expensive item is.

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Product{
	string name;    // Name
	int qty;        // quantity is the number of items in stock
	double price;  // price to purchase one item
};

//Functions
int menu();
void addprod(vector <Product>& inventory);
void showinventory(vector<Product>& inventory);
void showoutofstock(vector<Product>& inventory);
void showavgprice(vector<Product>& inventory);
void showhiprice(vector<Product>& inventory);


//Main, it connects the menu to the other funtions within the program.
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


//Prints out a screen of choices. If the input isn't within the int range it re-prompts the user.
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
			cout << "Invalid input. ";
			cout << "Enter your choice: ";
		}
	}

	return choice;
}


//Adds elements to the Product vector by getting each part of a Product object then using popback.
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


//Goes through the vector of elements and creates the average price by adding all of the prices together then divides it by the amount of entries.
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
	cout << "The average price is: $" << fixed << setprecision(2) << avgPrice << endl << endl;
	//Set precision to make sure the average price is set to only 2 decimal places.
}


//Goes through the vector of elements and checks to see which one has the highest price associated with it.
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
	cout << "The highest price is: " << inventory.at(hiIndex).name << " for $" << hiPrice << endl << endl;
}


//Goes through all of the elements in the Product vector to see which ones have a qty of 0. Prints out all the ones that are, or that there are no out of stock items.
void showoutofstock(vector<Product>& inventory) {
	int vectorLength = inventory.size();
	int i;
	int j = 0;
	//Table header
	cout << "Out of stock items:" << endl;
	cout << setw(5) << left << "##" << setw(15) << "Name" << setw(10) << "Qty" << setw(8) << "Price";
	cout << endl;
	cout << setw(5) << left << "--" << setw(15) << "----" << setw(10) << "---" << setw(8) << "-----";
	cout << endl;
	for (i = 0; i < vectorLength; i++) {
		if (inventory.at(i).qty == 0) {
			//Debated on whether to only have i increment the output when one is output (ex if the first out of stock is in the 4th slot, it'd be #1 rather than #4. But decided to leave
			//it since it would look better if there was a "Show out of stock" and a "show inventory" call and it'd be easier to cross-reference.
			cout << setw(5) << left << i + 1 << setw(15) << inventory.at(i).name << setw(10) << inventory.at(i).qty << setw(8) << inventory.at(i).price;
			cout << endl;
			j++;
		}
	}
	if (j == 0) {
		cout << "There are no out of stock items" << endl << endl;
	}
	cout << endl;

}


//Goes through the product vector and prints out all of the inputted items.
void showinventory(vector<Product>& inventory){
	int vectorLength = inventory.size();
	int i;
	//"Table" header.Set lengths to what I assume would be appropriate
	cout << setw(5) << left << "##" << setw(15) << "Name" << setw(10) << "Qty" << setw(8) << "Price";
	cout << endl;
	cout << setw(5) << left << "--" << setw(15) << "----" << setw(10) << "---" << setw(8) << "-----"; 
	cout << endl;

	for (i = 0; i < vectorLength; i++) {
		cout << setw(5) << left << i+1 << setw(15) << inventory.at(i).name << setw(10) << inventory.at(i).qty << setw(8) << inventory.at(i).price;
		cout << endl;
	}
	cout << endl;
}