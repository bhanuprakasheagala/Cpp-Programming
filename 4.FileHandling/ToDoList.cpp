/*
Todo List Manager:
Create a simple command-line-based to-do list manager. The program should allow users to add tasks, mark them as complete,
and save the to-do list to a file. You can load the list from the file when the program starts.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

struct Task{
    std::string name;
    bool completed;
};

class TaskManager {
    private:
        std::vector<Task> tasks;
        std::string fileName;

    public:
        TaskManager(const std::string& file);
        void addTask(const std::string& taskName);
        void markTaskComplete(int index);
        void displayTasks();
        void saveToFile();
        void loadFromFile();
};

TaskManager::TaskManager(const std::string& file) : fileName(file) {
    loadFromFile();
}

void TaskManager::addTask(const std::string& taskName){
    Task newTask{taskName, false};
    tasks.push_back(newTask);
    saveToFile();
}

void TaskManager::markTaskComplete(int index) {
    if(index >=0 && index < tasks.size()) {
        tasks[index].completed = true;
        saveToFile();
    }
}

void TaskManager::displayTasks(){
    std::cout << "To-Do List:\n";
    for(size_t i = 0; i<tasks.size(); ++i) {
        std::cout << i+1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].name << '\n';
    }
}

void TaskManager::saveToFile() {
    std::ofstream outFile(fileName);
    if(outFile.is_open()) {
        for(const Task& task : tasks) {
            outFile << task.name << ',' << task.completed << '\n'; 
        }
        outFile.close();
    }
}

void TaskManager::loadFromFile() {
    tasks.clear();
    std::ifstream inFile(fileName);
    if(inFile.is_open()) {
        std::string line;
        while(std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string taskName;
            bool completed;
            if(std::getline(iss, taskName, ',') && iss >> std::boolalpha >> completed) {
                tasks.push_back({taskName, completed});
            }
        }

        inFile.close();
    }
}

int main() {

    TaskManager taskManager("todo_list.txt");
    while(true) {
        std::cout << "\n1. Add Task\n2. Mark Task as completed\n3. Display Tasks\n4. Exit\n";
        
        int choice;
        std::cin>>choice;

        switch(choice) {
            case 1: {
                std::cin.ignore(); // Clear the new line character from the buffer
                std::cout<<"Enter task name: ";
                std::string taskName;
                std::getline(std::cin, taskName);
                taskManager.addTask(taskName);
                break;
            }
            case 2: {
                int index;
                std::cout << "\nEnter task index to mark as complete: ";
                std::cin>>index;
                taskManager.markTaskComplete(index-1);
                break;
            }
            case 3: {
                taskManager.displayTasks();
                break;
            }
            case 4: {
                exit(0);
            }
            default:
                std::cout<<"Invalid choice. Please try again.\n";
        }

    }
    return 0;
}