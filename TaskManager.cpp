#ifndef TASKMANAGER_H
#define TASKMANAGER_H

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

    vector<Project>& getProjects();
    vector<Worker>& getWorkers();

    void showProjects() const;
    void showWorkers() const;
    void showExpiredTasks() const;
};

#endif
