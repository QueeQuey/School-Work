#include <iostream>
#include <climits>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int MatrixChainRecursiveWithSplit(int p[], int i, int j, vector<vector<int>>& s);
int MatrixChainMemoizedUtil(int p[], int i, int j, vector<vector<int>>& mem, vector<vector<int>>& s);
int MatrixChainMemoized(int p[], int n, vector<vector<int>>& s);
int MatrixChainBottomUp(int p[], int n, vector<vector<int>>& s);
void printOptimalParenthesis(int i, int j, vector<vector<int>>& s, char& name);

int main() {
    int arr[] = { 10, 20, 30, 40, 30, 20, 10, 60, 70, 80, 90, 20, 50, 10, 40, 30 };
    //int arr[] = { 6, 30, 35, 15, 5, 10, 20, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);

    ///////////// RECURSIVE /////////////
    vector<vector<int>> sRec(n, vector<int>(n, 0));
    auto start1 = high_resolution_clock::now();
    int recCost = MatrixChainRecursiveWithSplit(arr, 1, n - 1, sRec);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);

    cout << "1. Recursive: Minimum multiplications = " << recCost << endl;
    cout << "   Optimal Parenthesization: ";
    char name1 = 'A';
    printOptimalParenthesis(1, n - 1, sRec, name1);
    cout << endl << "   Time Taken: " << duration1.count() << " ms" << endl << endl;

    ///////////// TOP-DOWN MEMOIZED /////////////
    vector<vector<int>> sMemo(n, vector<int>(n, 0));
    auto start2 = high_resolution_clock::now();
    int memoCost = MatrixChainMemoized(arr, n, sMemo);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);

    cout << "2. Top-Down Memoized: Minimum multiplications = " << memoCost << endl;
    cout << "   Optimal Parenthesization: ";
    char name2 = 'A';
    printOptimalParenthesis(1, n - 1, sMemo, name2);
    cout << endl <<"   Time Taken: " << duration2.count() << " ms" << endl << endl;

    ///////////// BOTTOM-UP /////////////
    vector<vector<int>> sBottom;
    auto start3 = high_resolution_clock::now();
    int bottomCost = MatrixChainBottomUp(arr, n, sBottom);
    auto end3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(end3 - start3);

    cout << "3. Bottom-Up: Minimum multiplications = " << bottomCost << endl;
    cout << "   Optimal Parenthesization: ";
    char name3 = 'A';
    printOptimalParenthesis(1, n - 1, sBottom, name3);
    cout << endl <<  "   Time Taken: " << duration3.count() << " ms" << endl;

    return 0;
}

///////////////////BOTTOM-UP//////////////////
int MatrixChainBottomUp(int p[], int n, vector<vector<int>>& s) {
    //A bit messy but what it actually means is
    //storage - Stores the min cost to multiply the matricies
    //S is the index for splitting, just like before.
    vector<vector<int>> mem(n, vector<int>(n, 0));
    s.assign(n, vector<int>(n, 0));

    //One given in the book and class but with vector. It'll be the same in the other functions.
    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            mem[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = mem[i][k] + mem[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < mem[i][j]) {
                    mem[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    return mem[1][n - 1];
}

/////////////////RECURSIVE//////////////////
int MatrixChainRecursiveWithSplit(int p[], int i, int j, vector<vector<int>>& s) {
    if (i == j) return 0;

    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
        int left = MatrixChainRecursiveWithSplit(p, i, k, s);
        int right = MatrixChainRecursiveWithSplit(p, k + 1, j, s);
        int cost = left + right + p[i - 1] * p[k] * p[j];
        if (cost < minCost) {
            minCost = cost;
            s[i][j] = k;
        }
    }
    return minCost;
}

/////////////////TOP-DOWN//////////////////
int MatrixChainMemoizedUtil(int p[], int i, int j, vector<vector<int>>& mem, vector<vector<int>>& s) {
    if (i == j) { return 0; }
    if (mem[i][j] != -1) { return mem[i][j]; }

    int minCost = INT_MAX;
    for (int k = i; k < j; k++) {
        int left = MatrixChainMemoizedUtil(p, i, k, mem, s);
        int right = MatrixChainMemoizedUtil(p, k + 1, j, mem, s);
        int cost = left + right + p[i - 1] * p[k] * p[j];
        if (cost < minCost) {
            minCost = cost;
            s[i][j] = k;
        }
    }
    return mem[i][j] = minCost;
}

int MatrixChainMemoized(int p[], int n, vector<vector<int>>& s) {
    vector<vector<int>> mem(n, vector<int>(n, -1));
    return MatrixChainMemoizedUtil(p, 1, n - 1, mem, s);
}

/////////////////PRINTING//////////////////
void printOptimalParenthesis(int i, int j, vector<vector<int>>& s, char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printOptimalParenthesis(i, s[i][j], s, name);
    printOptimalParenthesis(s[i][j] + 1, j, s, name);
    cout << ")";
}