#include <iostream>
#include <string>
#include "polyapp.h"
#pragma once

using namespace std;
/* DOCUMENTATION
* Name: Layne Woodruff
* Due Date: April 23rd, 2023
* Description of polyapp.cpp:
* This file defines the classes and their functions of Appliance, TV, and VCR
*/

//=====================Aplliance class member functions======================
//-----------------------Appliance Constructor-----------------------------
Appliance::Appliance(string ccustName, string cmanuFact) {
	custName = ccustName;
	manuFact = cmanuFact;
	//Feels wrong to not initialize estCost here.
}

//Setter and getter functons for the appliance class
void Appliance::setcustName(string inName){
	custName = inName;
}
string Appliance::getcustName(){
	return custName;
}
void Appliance::setmanuFact(string inFact){
	manuFact = inFact;
}

string Appliance::getmanuFact(){
	return manuFact;
}




//-----------------------Appliance EstimateService-----------------------------
//Sets estCost to 0 to be changed later by the other classes.
void Appliance::EstimateService() {
	estCost = 0.0;
}



//-----------------------Appliance printObject-----------------------------
void Appliance::printObject(){
	cout << "Customer Name	:" << custName << endl;
	cout << "Manufacture	:" << manuFact << endl;
	cout << "Estimated Cost	:" << estCost << endl;
}




//=========================TV class member functions=========================
//-----------------------TV Constructor-----------------------------

//Takes input into the TV class, which then passes to be part of the base class.
TV::TV(string ccustName, string cmanuFact, int cmodelAge) : Appliance(ccustName, cmanuFact) {
	custName = ccustName;
	manuFact = cmanuFact;
	modelAge = cmodelAge;
}

//Getter and setter for ModelAge.
void TV::setmodelAge(int inAge) {
	modelAge = inAge;
}
int TV::getmodelAge() {
	return modelAge;
}




//-----------------------TV EstimateService-----------------------------
// Calc based on model age, if 6+ years = $150, if less then $50.
void TV::EstimateService() {
	if (modelAge >= 6) {
		Appliance::estCost = 150;
	}
	else {
		Appliance::estCost = 50;
	}
}



//-----------------------TV printObject-----------------------------

void TV::printObject() {
 //cout << "------------------------------------" << endl;	//Thought I needed to create the break lines
 cout << "-----TV------" << endl;
 Appliance::printObject();

 //Cout doesn't exactly match the sample, but has the model age line line up better with the other output
 cout << "Model Age	:" << modelAge << endl;
 }



//====================VCR class member functions=========================
//-----------------------VCR Constructor-----------------------------

//Takes input into the TV class, which then passes to be part of the base class.
VCR::VCR(string ccustName, string cmanuFact, int cnumTapes) : Appliance(ccustName,cmanuFact){

	numTapes = cnumTapes;
}

//numTapes getter and setter
void VCR::setnumTapes(int inTapes) {
	numTapes = inTapes;
}
int VCR::getnumTapes() {
	return numTapes;
}

//-----------------------VCR EstimateService-----------------------------
// Calc based on numTapes. More than 1 = $100, if 1 or 0 = $40
void VCR::EstimateService(){
	if (numTapes > 1) {
		//not 100% sure on the syntax for estCost here. 
		Appliance::estCost = 100;
	}
	else {
		Appliance::estCost = 40;
	}
}



//-----------------------VCR printObject-----------------------------
void VCR::printObject() {
	//cout << "------------------------------------" << endl; //Thought I needed to create the break lines
	cout << "-----VCR------" << endl;
	Appliance::printObject();
	cout << "Number of Tape Drives	:" << numTapes << endl;
}