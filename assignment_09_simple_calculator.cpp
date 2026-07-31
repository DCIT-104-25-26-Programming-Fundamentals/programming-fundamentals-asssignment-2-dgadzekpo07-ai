#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

// Returns true if the division succeeded, false if b is zero.
bool divide(double a, double b, double& result) {
    if (b == 0) {
        return false;
    }
    result = a / b;
    return true;
}

// Returns true if the modulus succeeded, false if b is zero.
bool modulus(double a, double b, double& result) {
    if (b == 0) {
        return false;
    }
    result = fmod(a, b);
    return true;
}

double exponent(double base, double exp) {
    return pow(base, exp);
}

// Displays the menu options.
void printMenu() {
    cout << endl;
    cout << "============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
}

int main() {
    int choice;

    cout << fixed << setprecision(2);

    do {
        printMenu();
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            double num1, num2, result;

            cout << "Enter first number : ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            if (choice == 1) {
                result = add(num1, num2);
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            }
            else if (choice == 2) {
                result = subtract(num1, num2);
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            }
            else if (choice == 3) {
                result = multiply(num1, num2);
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            }
            else if (choice == 4) {
                if (divide(num1, num2, result)) {
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                }
            }
            else if (choice == 5) {
                if (modulus(num1, num2, result)) {
                    cout << "Result: " << num1 << " % " << num2 << " = " << result << endl;
                } else {
                    cout << "Error: Cannot divide by zero." << endl;
                }
            }
            else if (choice == 6) {
                result = exponent(num1, num2);
                cout << "Result: " << num1 << " ^ " << num2 << " = " << result << endl;
            }
        }
        else if (choice == 7) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Error: Please enter a number between 1 and 7." << endl;
        }

    } while (choice != 7);

    return 0;
}