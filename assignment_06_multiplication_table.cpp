#include <iostream>
#include <iomanip>
using namespace std;

void printTable(int num) {
    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << setw(2) << i << "  =  " << (num * i) << endl;
    }
}

void printTablesUpTo(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    for (int num = 1; num <= n; num++) {
        printTable(num);
        if (num != n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int choice;

    cout << "1. Single Table" << endl;
    cout << "2. Tables from 1 to N" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int number;
        cout << "Enter a number: ";
        cin >> number;

        if (number <= 0) {
            cout << "Error: Number must be a positive integer." << endl;
        } else {
            printTable(number);
        }
    }
    else if (choice == 2) {
        int n;
        cout << "Enter a number: ";
        cin >> n;
        printTablesUpTo(n);
    }
    else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}