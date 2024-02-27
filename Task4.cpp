#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Function prototypes
void showMenu();
void addTask();
void viewTasks();
void markCompleted();
void removeTask();

int main() {
    showMenu();
    return 0;
}

void showMenu() {
    char choice;
    do {
        cout << "\n===================== TO-DO LIST MANAGER =====================\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addTask();
                break;
            case '2':
                viewTasks();
                break;
            case '3':
                markCompleted();
                break;
            case '4':
                removeTask();
                break;
            case '5':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '5');
}

void addTask() {
    cin.ignore(); 
    string task;  
    cout << "Enter the task: ";
    getline(cin, task);

    ofstream outFile("tasks.txt", ios::app);
    if (outFile.is_open()) {
        outFile << task << "\n";
        cout << "Task added successfully!\n";
        outFile.close();
    } else {
        cout << "Error opening file.\n";
    }
}

void viewTasks() {
    ifstream inFile("tasks.txt");
    if (inFile.is_open()) {
        cout << "\n===================== TASKS =====================\n";
        string task;
        int count = 1;
        while (getline(inFile, task)) {
            cout << count << ". " << task << "\n";
            count++;
        }
        inFile.close();
    } else {
        cout << "No tasks found.\n";
    }
}

void markCompleted() {
    viewTasks();
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    ifstream inFile("tasks.txt");
    ofstream tempFile("temp.txt");
    if (inFile.is_open() && tempFile.is_open()) {
        string task;
        int count = 1;
        while (getline(inFile, task)) {
            if (count == taskNumber) {
                tempFile << "[Completed] " << task << "\n";
                cout << "Task marked as completed!\n";
            } else {
                tempFile << task << "\n";
            }
            count++;
        }
        inFile.close();
        tempFile.close();
        remove("tasks.txt");
        rename("temp.txt", "tasks.txt");
    } else {
        cout << "Error opening files.\n";
    }
}

void removeTask() {
    viewTasks();
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    ifstream inFile("tasks.txt");
    ofstream tempFile("temp.txt");
    if (inFile.is_open() && tempFile.is_open()) {
        string task;
        int count = 1;
        while (getline(inFile, task)) {
            if (count != taskNumber) {
                tempFile << task << "\n";
            } else {
                cout << "Task removed successfully!\n";
            }
            count++;
        }
        inFile.close();
        tempFile.close();
        remove("tasks.txt");
        rename("temp.txt", "tasks.txt");
    } else {
        cout << "Error opening files.\n";
    }
}
