
#include "FileManager.h"

#include <fstream>
#include <sstream>

void FileManager::saveWorkers(
    const vector<Worker>& workers
)
{
    ofstream file("workers.txt");

    for (const auto& worker : workers)
    {
        file << worker.getId() << ";"
             << worker.getName() << ";"
             << worker.getPosition()
             << endl;
    }
}

void FileManager::loadWorkers(
    vector<Worker>& workers
)
{
    workers.clear();

    ifstream file("workers.txt");

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id;
        string name;
        string position;

        getline(ss, id, ';');
        getline(ss, name, ';');
        getline(ss, position, ';');

        workers.push_back(
            Worker(
                stoi(id),
                name,
                position
            )
        );
    }
}

void FileManager::saveProjects(
    const vector<Project>& projects
)
{
    ofstream file("projects.txt");

    for (const auto& project : projects)
    {
        file << project.getId() << ";"
             << project.getName() << ";"
             << project.getDescription()
             << endl;
    }
}

void FileManager::loadProjects(
    vector<Project>& projects
)
{
    projects.clear();

    ifstream file("projects.txt");

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id;
        string name;
        string description;

        getline(ss, id, ';');
        getline(ss, name, ';');
        getline(ss, description, ';');

        projects.push_back(
            Project(
                stoi(id),
                name,
                description
            )
        );
    }
}

void FileManager::saveTasks(
    const vector<Project>& projects
)
{
    ofstream file("tasks.txt");

    for (const auto& project : projects)
    {
        for (const auto& task : project.getTasks())
        {
            file << task.getId() << ";"
                 << project.getId() << ";"
                 << task.getTitle() << ";"
                 << task.getDescription() << ";"
                 << task.getPriority() << ";"
                 << task.getDeadline().toString() << ";"
                 << task.isCompleted() << ";"
                 << task.getWorkerId()
                 << endl;
        }
    }
}

void FileManager::loadTasks(
    vector<Project>& projects
)
{
    ifstream file("tasks.txt");

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string taskId;
        string projectId;
        string title;
        string description;
        string priority;
        string deadline;
        string completed;
        string workerId;

        getline(ss, taskId, ';');
        getline(ss, projectId, ';');
        getline(ss, title, ';');
        getline(ss, description, ';');
        getline(ss, priority, ';');
        getline(ss, deadline, ';');
        getline(ss, completed, ';');
        getline(ss, workerId, ';');

        Task task(
            stoi(taskId),
            title,
            description,
            stoi(priority),
            Date::fromString(deadline)
        );

        task.setCompleted(
            stoi(completed)
        );

        task.setWorkerId(
            stoi(workerId)
        );

        for (auto& project : projects)
        {
            if (project.getId() ==
                stoi(projectId))
            {
                project.addTask(task);
                break;
            }
        }
    }
}

