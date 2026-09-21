#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Product {
	private:
		string name;    // Name
		int qty;        // quantity is the number of items in stock
		double price;  // price to purchase one item

	public:
		Product(string sname = "empty", int quantity = 0, double sPrice = 0.0);
		void setname(string sName);
		string getname() const;

		void setqty(int quantity);
		int getqty() const;

		void setprice(double sPrice);
		double getprice() const;

		void print() const;

};
