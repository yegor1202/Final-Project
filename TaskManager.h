#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <iostream>
#include <vector>

#include "Project.h"
#include "Worker.h"

using namespace std;

class TaskManager
{
private:
    vector<Project> projects;
    vector<Worker> workers;

public:
    void addProject(const Project& project);
    void addWorker(const Worker& worker);

    Project* findProjectById(int projectId);
    Worker* findWorkerById(int workerId);

    bool assignTask(
        int projectId,
        int taskId,
        int workerId
    );
    bool completeTask(
        int projectId,
        int taskId
    );

    vector<Project>& getProjects();
    vector<Worker>& getWorkers();
    int getTotalTaskCount() const;
    int getCompletedTaskCount() const;
    int getExpiredTaskCount() const;

    void showProjects() const;
    void showWorkers() const;
    void showExpiredTasks() const;
};

#endif


