#include "Product.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


Product::Product(string sname, int quantity = 0, double sPrice) {
	name = sname;
	qty = quantity;
	price = sPrice;
}
void Product::setname(string sName) {
	name = sName;
}
string Product::getname() const {
	return name;
}

void Product::setqty(int quantity) {
	qty = quantity;
}

int Product::getqty() const {
	return qty;
}

void Product::setprice(double sPrice) {
	price = sPrice;
}

double Product::getprice() const {
	return price;
}

void Product::print() const {
	cout << "Name:" << name << endl;
	cout << "Quantity:" << qty << endl;
	cout << "Price:" << price << endl;
}