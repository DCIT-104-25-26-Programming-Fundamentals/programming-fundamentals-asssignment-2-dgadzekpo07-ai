#include <iostream>
using namespace std;

// PART A: Prints the first n terms of the Fibonacci sequence on one line.
void printFibonacci(int n) {
    if (n <= 0) {
        cout << "Error: Number of terms must be a positive integer." << endl;
        return;
    }

    cout << "Fibonacci sequence: ";

    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        cout << a << " ";

        // Advance the sequence: next term is the sum of the last two.
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

// PART B: Checks whether a given number appears in the Fibonacci sequence.
bool isFibonacci(int num) {
    if (num < 0) {
        return false;
    }

    int a = 0, b = 1;

    // Generate terms up to and including num, checking for a match.
    while (a <= num) {
        if (a == num) {
            return true;
        }
        int next = a + b;
        a = b;
        b = next;
    }

    return false;
}

int main() {
    int n;
    int number;

    // ----- Part A -----
    cout << "How many terms? ";
    cin >> n;
    printFibonacci(n);

    cout << endl;

    // ----- Part B -----
    cout << "Enter a number to check: ";
    cin >> number;

    if (isFibonacci(number)) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}