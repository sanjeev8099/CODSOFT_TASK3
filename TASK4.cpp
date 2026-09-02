#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Task {
    string title;
    bool completed;
};

void showTasks(const vector<Task>& tasks) {
    cout << "\n=== TO-DO LIST ===\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". [" << (tasks[i].completed ? 'X' : ' ') << "] "
             << tasks[i].title << '\n';
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n=== TO-DO LIST MANAGER ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string title;
            cout << "Enter task: ";
            getline(cin, title);

            if (!title.empty()) {
                tasks.push_back({title, false});
                cout << "Task added successfully.\n";
            } else {
                cout << "Task cannot be empty.\n";
            }
        }
        else if (choice == 2) {
            showTasks(tasks);
        }
        else if (choice == 3) {
            showTasks(tasks);
            if (!tasks.empty()) {
                size_t index;
                cout << "Enter task number to mark completed: ";
                cin >> index;

                if (index >= 1 && index <= tasks.size()) {
                    tasks[index - 1].completed = true;
                    cout << "Task marked as completed.\n";
                } else {
                    cout << "Invalid task number.\n";
                }
            }
        }
        else if (choice == 4) {
            showTasks(tasks);
            if (!tasks.empty()) {
                size_t index;
                cout << "Enter task number to remove: ";
                cin >> index;

                if (index >= 1 && index <= tasks.size()) {
                    tasks.erase(tasks.begin() + index - 1);
                    cout << "Task removed successfully.\n";
                } else {
                    cout << "Invalid task number.\n";
                }
            }
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}