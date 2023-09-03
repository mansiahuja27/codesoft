#include <iostream>
#include <vector>
#include <string>


struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};


void AddTask(std::vector<Task>& tasks, const std::string& description) {
    tasks.push_back(Task(description));
    std::cout << "Task added: " << description << std::endl;
}


void ViewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks found." << std::endl;
        return;
    }

    std::cout << "Task List:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (tasks[i].completed) {
            std::cout << "[X] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << tasks[i].description << std::endl;
    }
}


void MarkTaskCompleted(std::vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        tasks[taskIndex - 1].completed = true;
        std::cout << "Task marked as completed: " << tasks[taskIndex - 1].description << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

void RemoveTask(std::vector<Task>& tasks, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
        std::cout << "Task removed: " << tasks[taskIndex - 1].description << std::endl;
        tasks.erase(tasks.begin() + taskIndex - 1);
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    while (true) {
        std::cout << "To-Do List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();  
                std::string description;
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                AddTask(tasks, description);
                break;
            }
            case 2:
                ViewTasks(tasks);
                break;
            case 3: {
                int taskIndex;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> taskIndex;
                MarkTaskCompleted(tasks, taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                std::cout << "Enter task index to remove: ";
                std::cin >> taskIndex;
                RemoveTask(tasks, taskIndex);
                break;
            }
            case 5:
                std::cout << "bye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice Please try again." << std::endl;
        }
    }

    return 0;
}
