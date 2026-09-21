// Assignment3_Woodruff.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "LinkedStack.h"
#include "Node.h"
#include "StackInterface.h"
using namespace std;
bool isOperator(const string& input);
void evaluate(LinkedStack<string>& x);

int main() {
    //cout << "Hello World!\n";
    LinkedStack<string> mainStack, printStack;
    bool userDone = false;
    int numberOfNumbers = 0; //used to increment to make sure the number of ints and operands are proportional.
    int numberOfOperators = 0;
    string inputVal;
    string curValue;
    vector<string> printVector;

    cout << "Enter the postfix expression, 1 token per line. Enter -1 to terminate." << endl;

    while (!userDone) {
        getline(cin, inputVal);
        //Checks for exit function, allows if the Operators can be used. Not as necessary now as a previous itteration had the 
        //  stack created in it's entirety before passing instead of what is is now which is putting into the stack until operands are passed in.
        if (inputVal == "-1" && (numberOfNumbers == numberOfOperators + 1 || (numberOfNumbers == 0 && numberOfOperators == 0))) {
            userDone = true;
            break;
        }
        else if (inputVal == "-1") {
            cout << "One more number needs to be added!"<< endl;
            continue;
        }
        

        stringstream ss(inputVal);
        int value; //Not set to a val. Just as a type for later checking


        //Syntax is a bit weird here. Essentially, if it's the end of the string stream (ee.eof()) and stringstream gets an int via value.
        if (ss >> value && ss.eof()) {
            mainStack.push(to_string(value));
            printStack.push(to_string(value));
            cout << "Pushed " << value << " onto the stack." << endl; // Used for testing. Originally commented out to match up with the Assignment 3 doc. But kept because it shows stack use in the Terminal.
            //printVector.push_back(to_string(value));
            numberOfNumbers++;
        }
        else if (isOperator(inputVal)){
            if (mainStack.isEmpty()) {
                cout << "Error: No vals in the stack, need to add a number first!" << endl;
                continue;
            }
            else if(numberOfOperators >= numberOfNumbers - 1 || numberOfNumbers == 1){
                cout << "Not enough numbers to add an operator! You need to add 1 more number first." << endl;
            }
            else {
                mainStack.push(inputVal);
                cout << "Pushed " << inputVal << " onto the stack." << endl; // Used for testing. Similar story to the one with the number push.
                printStack.push(inputVal);
                evaluate(mainStack); 
                //cout << "Pushed " << inputVal << " onto the Stack" << endl;
                //numberOfOperators++;
                numberOfNumbers--;
            }
        }
        else {
            cout << "Input is not a number or operator!" << endl;
        }
    }

    //If nothing was on the stack ending Main()
    if (numberOfNumbers == 0 && numberOfOperators == 0) {
        return 0;
    }

    cout << endl << endl;
    cout << "Final expression:" << endl;
    //Printing out the print Stack
    while (!printStack.isEmpty()) {
        printVector.push_back(printStack.peek());
        printStack.pop();
    }
    
    for (int i = printVector.size() - 1; i >= 0; --i) {
        cout << printVector[i] << " ";
    }
    cout << "= " << mainStack.peek();
        
}

void evaluate(LinkedStack<string>& x) {
    int result = 0;
    string operatorVar;
    //Setting operator first since it will always be on the top of the stack when the stack is passed in. THen right, then left.
    operatorVar = x.peek();
    x.pop();

    int rightOperator = stoi(x.peek());
    x.pop();
    int leftOperator = stoi(x.peek());
    x.pop();

    if (operatorVar == "+") {
        result = leftOperator + rightOperator;
    }
    else if (operatorVar == "-") {
        result = leftOperator - rightOperator;
    }
    else if (operatorVar == "*") {
        result = leftOperator * rightOperator;
    }
    else if (operatorVar == "/") {
        if (rightOperator == 0) {
            cout << "Error: Division by zero! Returning numbers back to stack." << endl;
            x.push(to_string(leftOperator));
            x.push(to_string(rightOperator));
            return;
        }
        else {
        result = leftOperator / rightOperator;
        }
    }

    x.push(to_string(result));
    cout << "Operaton: " << leftOperator << " " <<  operatorVar << " " << rightOperator << " = " << result << endl;
    //return x; //Orignially returned an int
}


bool isOperator(const string& input){
    return input == "+" || input == "-" || input == "*" || input == "/";
}