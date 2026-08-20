#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "Task.h"
#include <vector>
#include <fstream>
#include <sstream>

class TaskManager
{
private:
    std::vector<Task> tasks;
     bool isTaskExists(int id);
     Task* findTaskById(int id);
     bool isValidDeadline(const std::string& deadline);
     std::string trim(const std::string& text);
     std::string toLower(const std::string& text);

public:
    void addTask();
    void displayTasks() const;
    void updateTask();
    void markTaskCompleted();
    void searchTask();
    void deleteTask();
    void saveToFile();
    void loadFromFile();
    void sortTask();
    void displayStatistics();
};

#endif