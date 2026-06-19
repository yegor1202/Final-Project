#include "Project.h"

Project::Project()
{
    id = 0;
    name = "";
    description = "";
};
Project::Project(
    int id,
    const string& name,
    const string& description
)
{
    this->id = id;
    this->name = name;
    this->description = description;
};
int Project::getId() const
{
    return id;
};

string Project::getName() const
{
    return name;
};

string Project::getDescription() const
{
    return description;
};

void Project::setName(const string& name)
{
    this->name = name;
};

void Project::setDescription(const string& description)
{
    this->description = description;
};

void Project::addTask(const Task& task)
{
    tasks.push_back(task);
};

bool Project::removeTask(int taskId)
{
    for (auto it = tasks.begin(); it != tasks.end(); ++it)
    {
        if (it->getId() == taskId)
        {
            tasks.erase(it);
            return true;
        };
    };

    return false;
};

Task* Project::findTaskById(int taskId)
{
    for (auto& task : tasks)
    {
        if (task.getId() == taskId)
        {
            return &task;
        };
    };

    return nullptr;
};

vector<Task>& Project::getTasks()
{
    return tasks;
};
const vector<Task>& Project::getTasks() const
{
    return tasks;
};
int Project::getTaskCount() const
{
    return tasks.size();
};

void Project::display() const
{
    cout << "ID: " << id << endl;
    cout << "Название: " << name << endl;
    cout << "Описание: " << description << endl;
    cout << "Количество задач: " << tasks.size() << endl;
};


