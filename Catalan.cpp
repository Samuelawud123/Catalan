/*
*Catalan number method which takes in one argument and calls a recursive function to compute Nth catalan number
*Author: Samuel Awud
*/
#include <iostream>
#include <cstdlib> // Include for using the atoi function
using namespace std;

/**
 * Function to compute the Nth Catalan number recursively.
 *
 * Precondition:
 * - N must be a non-negative integer.
 * - N should not be so large as to cause a stack overflow due to deep recursion; typically, N <= 15.
 *
 * Postcondition:
 * - Returns the Nth Catalan number computed according to the defined recursive formula.
 * - If N is 0, returns 1 as C0 = 1.
 * - Returns -1 if N is negative, indicating invalid input.
 *
 * @param N The index of the Catalan number to compute.
 * @return The Nth Catalan number.
 */
int nthCatalanNumber(int N) {
    if (N < 0) {
        return -1; // N cannot be negative
    }
    if (N == 0) {
        return 1; // Base case: C0 is defined as 1
    }
    int result = 0;
    for (int i = 0; i < N; i++) {
        result += nthCatalanNumber(i) * nthCatalanNumber(N - i - 1);
    }
    return result; // Resulting Catalan number
}

/**
 * Main program to drive the Catalan number computation.
 *
 * Precondition:
 * - Requires exactly one command-line argument (N).
 * - The argument should be an Integer.
 *
 * Postcondition:
 * - Outputs the Nth Catalan number if the input is valid.
 * - Prints an error message and returns -1 if the input is invalid or insufficient.
 *
 * @return Returns 0 on successful execution, -1 on error.
 */
int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "-1" << endl; // Invalid number of arguments
        return -1;
    }

    int N = atoi(argv[1]); // Convert the first command-line argument to an integer

    if (N < 0 || N > 15) { // N should be positive and limited to 15 to avoid deep recursion issues
        cout << "-1" << endl; // Print -1 for inputs that are negative or too large
        return -1;
    }

    cout << nthCatalanNumber(N) << endl; // Calculate and output the Nth Catalan number
    return 0;
}
