#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Represents a single student record.
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Computes the average of a student's scores. Assumes scores is non-empty.
double calculateAverage(const Student& s) {
    double sum = 0;
    for (int i = 0; i < s.scores.size(); i++) {
        sum += s.scores[i];
    }
    return sum / s.scores.size();
}

// Prompts the user for a new student's details and adds them to the list.
void addStudent(vector<Student>& students) {
    Student s;

    cin.ignore(); // Clear leftover newline before reading the name with getline
    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;

    int numScores;
    cout << "How many scores? ";
    cin >> numScores;

    if (numScores <= 0) {
        cout << "Error: Number of scores must be positive. Student not added." << endl;
        return;
    }

    for (int i = 0; i < numScores; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

// Displays a formatted table of all students, their scores, and averages.
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < students.size(); i++) {
        const Student& s = students[i];
        cout << endl;
        cout << "Name:    " << s.name << endl;
        cout << "ID:      " << s.id << endl;
        cout << "Scores:  ";
        for (int j = 0; j < s.scores.size(); j++) {
            cout << s.scores[j];
            if (j != s.scores.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "Average: " << calculateAverage(s) << endl;
    }
}

// Looks up a student by ID and prints their average score.
void showAverageForId(const vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            cout << fixed << setprecision(2);
            cout << students[i].name << "'s average score: "
                 << calculateAverage(students[i]) << endl;
            return;
        }
    }

    cout << "Error: No student found with ID " << id << "." << endl;
}

// Displays the menu options.
void printMenu() {
    cout << endl;
    cout << "================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    vector<Student> students;
    int choice;

    do {
        printMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addStudent(students);
        }
        else if (choice == 2) {
            displayAllStudents(students);
        }
        else if (choice == 3) {
            showAverageForId(students);
        }
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Error: Please enter a number between 1 and 4." << endl;
        }

    } while (choice != 4);

    return 0;
}