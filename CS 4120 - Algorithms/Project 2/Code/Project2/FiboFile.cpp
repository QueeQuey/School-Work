#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
//Had to switch to long longs from ints since I was getting integer overflow.
long long  fibonacci(int n);
long long  fibonacciMemo(int n, vector<long long >& memo);
long long  fibonacciBottomUp(int n);

int main() {
    //vector<int> sampleInputs = { 2,7,30,10,0,8,40}; //FOR TESTING
    vector<int> sampleInputs = { 2,7,30,10,0,8,50};
    int lessPracticalFibRec = 57;
    int lessPracticalFibTD = 3000;
    int lessPracticalFibBU = 10000;

    ///////Memoized Top Down Fibonacci ////
    cout << "Top-Down Fibonacci" << endl;
    for (int n : sampleInputs) {
        auto start = chrono::high_resolution_clock::now();
        //-1 for initialization, so can be used for comparisons later (if it's already been computed or not).
        vector<long long> memo(n + 1, -1);
        cout << "fib(" << n << ") = " << fibonacciMemo(n, memo) << " - ";
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> durationMemo = end - start;
        cout << "Time taken: " << durationMemo.count() << " ms" << endl << endl;
    }
    
    ////// Bottom-Up Fibonacci ////
    cout << "------------------" << endl;
    cout << endl << "Bottom - Up Fibonacci" << endl;
    for (int n : sampleInputs) {
        auto start = chrono::high_resolution_clock::now();
        cout << "fib(" << n << ") = " << fibonacciBottomUp(n) << " - ";
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> durationBottomUp = end - start;
        cout << "Time taken: " << durationBottomUp.count() << " ms" << endl << endl;
    }
    

    ///////Recursive Fibonacci////
    cout << "------------------" << endl;
    cout << endl << "Recursive Fibonacci" << endl;
    for (int n : sampleInputs) {
        auto start = chrono::high_resolution_clock::now();
        cout << "fib(" << n << ") = " << fibonacci(n) << " - ";
        auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> durationOptimized = end - start;
    cout << "Time taken: " << durationOptimized.count() << " ms" << endl << endl;
    }
    
    //"Practical" options
    cout << "------------------" << endl;
    cout << "What I feel are the most \"practical\" options " << endl;
    //ADD OR REMOVE COMMENT BLOCK TO CHECK EACH AS NEEDED.
    
    //Top Down
    cout << "Top down " << lessPracticalFibTD << " elements" << endl;
    auto start = chrono::high_resolution_clock::now();
    vector<long long> memo(lessPracticalFibTD + 1, -1);
    cout << "fib(" << lessPracticalFibTD << ") = " << fibonacciMemo(lessPracticalFibTD, memo) << " - ";
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> durationMemo = end - start;
    cout << "Time taken: " << durationMemo.count() << " ms" << endl << endl;
    

    
    
    //Bottom Up
    cout << "Bottom Up " << lessPracticalFibBU << " elements" << endl;
    auto startB = chrono::high_resolution_clock::now();
    cout << "fib(" << lessPracticalFibBU << ") = " << fibonacciBottomUp(lessPracticalFibBU) << " - ";
    auto endB = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> durationBottomUp = endB - startB;
    cout << "Time taken: " << durationBottomUp.count() << " ms" << endl << endl;
    

    /*
    //Recursive
    cout << "Recursive Fibonacci:" << lessPracticalFibRec << endl;
    auto startR = chrono::high_resolution_clock::now();
    cout << "fib(" << lessPracticalFibRec << ") = " << fibonacci(lessPracticalFibRec) << " - ";
    auto endR = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> durationOptimized = endR - startR;
    cout << "Time taken: " << durationOptimized.count() << " ms" << endl << endl;
    */

    
    return 0;
}




long long fibonacci(int n) {
    //covers 0 and 1
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

//Memoized Version, top down
long long fibonacciMemo(int n, vector<long long>& memo) {
    //Covers 0 and 1
    if (n <= 1) {
        return n;
    }
    //If the element isn't -1 (what all elements are initalized to) then return since it's already been computed.
    if (memo[n] != -1) {
        return memo[n];
    }
    //Memo at the current location is the sum of the memo at -1 and -2 values. Memo is passed by reference.
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    return memo[n];
}

//Bottom up version
long long fibonacciBottomUp(int n) {
    //Covers 0 and 1
    if (n <= 1) {
        return n;
    }
    //Table is always n + 1
    vector<long long> storeTable(n + 1);
    //Creates a 0 and 1 to reference
    storeTable[0] = 0;
    storeTable[1] = 1;

    //Starts at 2 since 0 and 1 are already stored. Goes through the rest of the values.
    for (int i = 2; i <= n; ++i) {
        storeTable[i] = storeTable[i - 1] + storeTable[i - 2];
    }
    return storeTable[n];
}