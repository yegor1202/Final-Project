#include "TaskManager.h"

void TaskManager::addProject(const Project& project)
{
    projects.push_back(project);
}

void TaskManager::addWorker(const Worker& worker)
{
    workers.push_back(worker);
}

Project* TaskManager::findProjectById(int projectId)
{
    for (auto& project : projects)
    {
        if (project.getId() == projectId)
        {
            return &project;
        }
    }

    return nullptr;
};
Worker* TaskManager::findWorkerById(int workerId)
{
    for (auto& worker : workers)
    {
        if (worker.getId() == workerId)
        {
            return &worker;
        }
    }

    return nullptr;
};

bool TaskManager::assignTask(
    int projectId,
    int taskId,
    int workerId
)
{
    Project* project =
        findProjectById(projectId);

    if (project == nullptr)
    {
        return false;
    }

    Worker* worker =
        findWorkerById(workerId);

    if (worker == nullptr)
    {
        return false;
    }

    Task* task =
        project->findTaskById(taskId);

    if (task == nullptr)
    {
        return false;
    }

    task->assignWorker(workerId);

    return true;
};

bool TaskManager::completeTask(
    int projectId,
    int taskId
)
{
    Project* project =
        findProjectById(projectId);

    if (project == nullptr)
    {
        return false;
    }

    Task* task =
        project->findTaskById(taskId);

    if (task == nullptr)
    {
        return false;
    }

    task->complete();

    return true;
};

vector<Project>& TaskManager::getProjects()
{
    return projects;
};

vector<Worker>& TaskManager::getWorkers()
{
    return workers;
};

int TaskManager::getTotalTaskCount() const
{
    int count = 0;

    for (const auto& project : projects)
    {
        count += project.getTaskCount();
    }

    return count;
};
int TaskManager::getCompletedTaskCount() const
{
    int count = 0;

    for (const auto& project : projects)
    {
        for (const auto& task : project.getTasks())
        {
            if (task.isCompleted())
            {
                count++;
            }
        }
    }

    return count;
};
int TaskManager::getExpiredTaskCount() const
{
    int count = 0;

    for (const auto& project : projects)
    {
        for (const auto& task : project.getTasks())
        {
            if (task.isExpired())
            {
                count++;
            };
        };
    };

    return count;
};
void TaskManager::showProjects() const
{
    if (projects.empty())
    {
        cout << "Проекты отсутствуют." << endl;
        return;
    };

    for (const auto& project : projects)
    {
        project.display();
        cout << endl;
    };
};
void TaskManager::showWorkers() const
{
    if (workers.empty())
    {
        cout << "Сотрудники отсутствуют." << endl;
        return;
    }

    for (const auto& worker : workers)
    {
        worker.display();
        cout << endl;
    }
};
void TaskManager::showExpiredTasks() const
{
    bool found = false;

    for (const auto& project : projects)
    {
        for (const auto& task : project.getTasks())
        {
            if (task.isExpired())
            {
                if (!found)
                {
                    cout << "Просроченные задачи:" << endl;
                    found = true;
                };

                cout << endl;
                cout << "Проект: "
                     << project.getName()
                     << endl;

                task.display();
            };
        };
    };

    if (!found)
    {
        cout << "Просроченных задач нет." << endl;
    };
};

