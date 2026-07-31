#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Reads an M x N matrix from the user, element by element.
void readMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// Displays a matrix in a neat, aligned grid.
void printMatrix(int mat[10][10], int rows, int cols, const string& label) {
    cout << endl << label << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// PART A: Computes the transpose of an M x N matrix into an N x M result.
void transposeMatrix(int mat[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

// PART B: Adds two M x N matrices element-wise into result.
void addMatrices(int a[10][10], int b[10][10], int rows, int cols, int result[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// PART C: Multiplies an M x N matrix A by an N x P matrix B into an M x P result.
void multiplyMatrices(int a[10][10], int b[10][10], int rowsA, int colsA, int colsB, int result[10][10]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int choice;

    do {
        cout << endl << "===== Matrix Operations Menu =====" << endl;
        cout << "1. Transpose a Matrix" << endl;
        cout << "2. Add Two Matrices" << endl;
        cout << "3. Multiply Two Matrices" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int mat[10][10], result[10][10];
            int rows, cols;

            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;

            readMatrix(mat, rows, cols);
            transposeMatrix(mat, rows, cols, result);

            printMatrix(mat, rows, cols, "Original Matrix:");
            printMatrix(result, cols, rows, "Transposed Matrix:");
        }
        else if (choice == 2) {
            int a[10][10], b[10][10], result[10][10];
            int rows, cols;

            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;

            cout << endl << "-- Matrix A --" << endl;
            readMatrix(a, rows, cols);
            cout << endl << "-- Matrix B --" << endl;
            readMatrix(b, rows, cols);

            addMatrices(a, b, rows, cols, result);

            printMatrix(a, rows, cols, "Matrix A:");
            printMatrix(b, rows, cols, "Matrix B:");
            printMatrix(result, rows, cols, "Sum (A + B):");
        }
        else if (choice == 3) {
            int a[10][10], b[10][10], result[10][10];
            int rowsA, colsA, rowsB, colsB;

            cout << "Enter rows for Matrix A: ";
            cin >> rowsA;
            cout << "Enter columns for Matrix A: ";
            cin >> colsA;

            cout << "Enter rows for Matrix B: ";
            cin >> rowsB;
            cout << "Enter columns for Matrix B: ";
            cin >> colsB;

            // Columns of A must equal rows of B.
            if (colsA != rowsB) {
                cout << "Error: Number of columns in A must equal number of rows in B." << endl;
            } else {
                cout << endl << "-- Matrix A --" << endl;
                readMatrix(a, rowsA, colsA);
                cout << endl << "-- Matrix B --" << endl;
                readMatrix(b, rowsB, colsB);

                multiplyMatrices(a, b, rowsA, colsA, colsB, result);

                printMatrix(a, rowsA, colsA, "Matrix A:");
                printMatrix(b, rowsB, colsB, "Matrix B:");
                printMatrix(result, rowsA, colsB, "Product (A x B):");
            }
        }
        else if (choice != 4) {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}