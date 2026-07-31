#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Prompts the user for a task description and adds it to the list.
void addTask(vector<string>& tasks) {
    cin.ignore(); // Clear leftover newline from the previous cin >> choice
    string task;

    cout << "Enter task: ";
    getline(cin, task);

    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

// Displays all tasks in the list, numbered from 1.
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty. Add a task to get started!" << endl;
        return;
    }

    cout << "Your Tasks:" << endl;
    for (int i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

// Shows the list, asks which task number to remove, and deletes it.
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty. Nothing to delete." << endl;
        return;
    }

    viewTasks(tasks);

    int taskNum;
    cout << "Enter task number to delete: ";
    cin >> taskNum;

    // Validate the task number is within range.
    if (taskNum < 1 || taskNum > tasks.size()) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string removed = tasks[taskNum - 1];
    tasks.erase(tasks.begin() + (taskNum - 1));

    cout << "Task \"" << removed << "\" has been removed." << endl;
}

// Displays the menu options.
void printMenu() {
    cout << endl;
    cout << "============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        printMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addTask(tasks);
        }
        else if (choice == 2) {
            viewTasks(tasks);
        }
        else if (choice == 3) {
            deleteTask(tasks);
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