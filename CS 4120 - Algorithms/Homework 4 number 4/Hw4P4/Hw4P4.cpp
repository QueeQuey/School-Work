#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void matrixChainOrder(const vector<int>& p, int n, vector<vector<int>>& m, vector<vector<int>>& s) {
    // Initialize tables
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;  // Zero cost for a single matrix
    }

    cout << "\nCell Calculations:\n";
    cout << " Seq | Level |  i  |  j  |   Product    |  m[i,j] (Min)  |  s[i,j]  |  Matrix Size \n";
    cout << "----------------------------------------------------------------------------------\n";

    int sequence = 1; // Sequence number for each calculation

    // l = chain length
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = numeric_limits<int>::max();

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }

            // Compute the resulting matrix size
            int result_rows = p[i - 1];
            int result_cols = p[j];

            // Print cell calculations
            printf(" %3d |   %2d   | %2d  | %2d  | A%d to A%d  |      %5d     |    %2d    |  %dx%d  \n",
                sequence++, l, i, j, i, j, m[i][j], s[i][j], result_rows, result_cols);
        }
    }
}

// Function to print the optimal parenthesization
void printOptimalParens(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    }
    else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    // Given matrix dimensions: A1 (2x3), A2 (3x10), A3 (10x5), A4 (5x4), A5 (4x20)
    vector<int> p = { 2, 3, 10, 5, 4, 20 };
    int n = p.size();

    // Tables for storing results
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    // Compute matrix chain multiplication order
    matrixChainOrder(p, n, m, s);

    // Output results
    cout << "\nMinimum number of multiplications: " << m[1][n - 1] << endl;
    cout << "Optimal parenthesization: ";
    printOptimalParens(s, 1, n - 1);
    cout << endl;

    return 0;
}
