#include <iostream>
using namespace std;

// Computes the sum of all elements in the array.
int calculateSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Computes the average of all elements in the array.
double calculateAverage(int arr[], int n) {
    return static_cast<double>(calculateSum(arr, n)) / n;
}

// Finds the maximum value in the array.
int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Finds the minimum value in the array.
int findMin(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    int n;

    cout << "How many numbers? ";
    cin >> n;

    // N must be positive.
    if (n <= 0) {
        cout << "Error: Please enter a positive integer." << endl;
        return 0;
    }

    // Dynamically allocate an array of size n.
    int* numbers = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << endl << "Results:" << endl;
    cout << "Sum:     " << calculateSum(numbers, n) << endl;
    cout << "Average: " << calculateAverage(numbers, n) << endl;
    cout << "Maximum: " << findMax(numbers, n) << endl;
    cout << "Minimum: " << findMin(numbers, n) << endl;

    // Free the dynamically allocated memory.
    delete[] numbers;

    return 0;
}