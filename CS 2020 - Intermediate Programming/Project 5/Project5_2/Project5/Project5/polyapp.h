#include <iostream>
#include <string>

using namespace std;
/* DOCUMENTATION
* Name: Layne Woodruff
* Due Date: April 23rd, 2023
* Description of polyapp.h:
* This header files creates the outline of the classes Appliance (base class), TV, and VCR (derived classes)
*/

//=========================Appliance class definition=========================
//-----------------------------------------------------------------------

class Appliance {
	public:
	Appliance(string ccustName, string cmanuFact);

	void setcustName(string inName);
	string getcustName();
	void setmanuFact(string inFact);
	string getmanuFact();

	virtual void EstimateService();	//Sets estCost to 0
	virtual void printObject();		//Should print all data members above

	protected:
	string custName; //Customer's Name
	string manuFact; //the manufacturer
	double estCost; //estimated cost of repairs
};




//-----------------------------------------------------------------------
//=========================TV class definition=========================
//-----------------------------------------------------------------------
class TV: public Appliance{
public:
	TV(string ccustName, string cmanuFact, int cmodelAge); //TV Constructor
	
	//Settter and getter for variable modelAge
	void setmodelAge(int inAge);
	int getmodelAge();
 
	virtual void EstimateService(); // Calc based on model age, if 6+ years = $150, if less then $50.
	virtual void printObject(); //Adds just the TV part of the PrintObject and cals the base Appliance PrintObect function.
 
 private:
	int modelAge;
 
};




//-----------------------------------------------------------------------
//=========================VCR class definition=========================
//-----------------------------------------------------------------------

 class VCR: public Appliance{
 public: 
	 VCR(string ccustName, string cmanuFact, int cnumTapes); //VCR Constructor
	
	 //Getter and setter for numTapes
	void setnumTapes(int inTapes);
	int getnumTapes();
 
	virtual void EstimateService(); // Calc based on numTapes. More than 1 = $100, if 1 or 0 = $40
	virtual void printObject();	//Adds just the VCR part of the PrintObject and cals the base Appliance PrintObect function.
 
 private:
	int numTapes;
};




//-----------------------------------------------------------------------
