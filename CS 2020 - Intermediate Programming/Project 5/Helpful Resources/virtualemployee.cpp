#include <iostream>
using namespace std;

class SalesPerson {
	public:
			SalesPerson(int i, double s) {Id = i; Sales = s;}
			virtual double GetBonus();
	protected:
			int Id;
			double Sales;
};
class Intern : public SalesPerson {
	public:
		Intern(int i, double s) : SalesPerson(i,s) {Rate = 0.1;}
		virtual double GetBonus();
	protected:
		double Rate;

};
class Entry : public SalesPerson {
	public:
		Entry(int i, double s) : SalesPerson(i,s) {Rate = 0.2;}
		virtual double GetBonus();
	protected:
		double Rate;

};
class Manager : public SalesPerson {
	public:
		Manager(int i, double s) : SalesPerson(i,s) {Rate = 0.3;}
		virtual double GetBonus();
	protected:
		double Rate;

};
//-----------------------SalesPerson.cpp---------------------
double SalesPerson::GetBonus()
{ return 0;
}
double Intern::GetBonus()
{
	return (Sales * Rate + 100);
}
double Entry::GetBonus()
{
	return (Sales * Rate + 200);
}
double Manager::GetBonus()
{
	return (Sales * Rate + 300);
}
//--------------------------SalesPersonclient.cpp---------------
int main()
{	SalesPerson *Bptr;
	Intern Ivan(123, 100);
	Entry Emily(456, 100);
	Manager Micky(789, 100);

	Bptr = & Ivan;
	cout << "Ivan's bonus is " << Bptr->GetBonus() << endl;
	Bptr = & Emily;
	cout << "Emily's bonus is " << Bptr->GetBonus() << endl;
	Bptr = & Micky;
	cout << "Micky's bonus is " << Bptr->GetBonus() << endl;
	
	return 0;
}

