#include <iostream>
using namespace std;

int main() {
	int myInt;
	int* myRestaurant;
	int myVar;
	int* myBill = nullptr;

	myInt = 10;
	myRestaurant = &myInt;
	myVar = *myBill;
	myVar = *myRestaurant + 10.5;

	cout << "The output:" << endl;
	cout << myVar << endl;
	return 0;
}