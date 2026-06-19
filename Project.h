#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include <string>
#include <vector>

#include "Task.h"

using namespace std;

class Project
{
private:
    int id;
    string name;
    string description;
    vector<Task> tasks;

public:
    Project();

    Project(
        int id,
        const string& name,
        const string& description
    );

    int getId() const;
    string getName() const;
    string getDescription() const;

    void setName(const string& name);
    void setDescription(const string& description);

    void addTask(const Task& task);

    bool removeTask(int taskId);

    Task* findTaskById(int taskId);

    vector<Task>& getTasks();
    const vector<Task>& getTasks() const;

    int getTaskCount() const;

    void display() const;
};

#endif

