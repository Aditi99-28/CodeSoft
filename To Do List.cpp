#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    Task(string name) : name(name), completed(false) {}

    string getName() const {
        return name;
    }

    bool isCompleted() const {
        return completed;
    }

    void markCompleted() {
        completed = true;
    }

    void markPending() {
        completed = false;
    }

private:
    string name;
    bool completed;
};

class ToDoList {
public:
    void addTask(const string& taskName) {
        tasks.push_back(Task(taskName));
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list.\n";
            return;
        }

        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName() << " ["
                 << (tasks[i].isCompleted() ? "Completed" : "Pending") << "]\n";
        }
    }

    void markTaskCompleted(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task index.\n";
            return;
        }
        tasks[taskIndex - 1].markCompleted();
        cout << "Task marked as completed.\n";
    }

    void markTaskPending(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task index.\n";
            return;
        }
        tasks[taskIndex - 1].markPending();
        cout << "Task marked as pending.\n";
    }

    void removeTask(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task index.\n";
            return;
        }
        tasks.erase(tasks.begin() + taskIndex - 1);
        cout << "Task removed.\n";
    }

private:
    vector<Task> tasks;
};

int main() {
    ToDoList toDoList;
    int choice;
    int taskIndex;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Mark Task as Pending\n";
        cout << "5. Remove Task\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore any leftover newline characters

        switch (choice) {
            case 1: {
                string taskName;
                cout << "Enter task name: ";
                getline(cin, taskName);
                toDoList.addTask(taskName);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                toDoList.markTaskCompleted(taskIndex);
                break;
            case 4:
                cout << "Enter task number to mark as pending: ";
                cin >> taskIndex;
                toDoList.markTaskPending(taskIndex);
                break;
            case 5:
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                toDoList.removeTask(taskIndex);
                break;
            case 6:
                cout << "Exiting To-Do List Manager.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

