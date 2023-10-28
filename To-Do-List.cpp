#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

// Function to add a task to the list
void AddTask(std::vector<Task>& tasks, const std::string& description) {
    Task task;
    task.description = description;
    task.completed = false;
    tasks.push_back(task);
    std::cout << "Task added." << std::endl;
}

// Function to display the list of tasks
void ViewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to display." << std::endl;
    } else {
        std::cout << "Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            std::cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << std::endl;
        }
    }
}

// Function to mark a task as completed
void MarkTaskCompleted(std::vector<Task>& tasks, int taskNumber) {
    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed." << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

// Function to remove a task from the list
void RemoveTask(std::vector<Task>& tasks, int taskNumber) {
    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed." << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    std::string input;

    while (true) {
        std::cout << "TODO List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: // Add Task
                {
                    std::cout << "Enter task description: ";
                    std::cin.ignore(); // Clear input buffer
                    std::getline(std::cin, input);
                    AddTask(tasks, input);
                    break;
                }
            case 2: // View Tasks
                ViewTasks(tasks);
                break;
            case 3: // Mark Task as Completed
                {
                    ViewTasks(tasks);
                    if (!tasks.empty()) {
                        std::cout << "Enter the task number to mark as completed: ";
                        int taskNumber;
                        std::cin >> taskNumber;
                        MarkTaskCompleted(tasks, taskNumber);
                    }
                    break;
                }
            case 4: // Remove Task
                {
                    ViewTasks(tasks);
                    if (!tasks.empty()) {
                        std::cout << "Enter the task number to remove: ";
                        int taskNumber;
                        std::cin >> taskNumber;
                        RemoveTask(tasks, taskNumber);
                    }
                    break;
                }
            case 5: // Quit
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
