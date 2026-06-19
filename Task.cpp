#include "Task.h"

Task::Task()
{
    id = 0;
    title = "";
    description = "";
    priority = 1;
    completed = false;
    workerId = -1;
}

Task::Task(
    int id,
    const string& title,
    const string& description,
    int priority,
    const Date& deadline
)
{
    this->id = id;
    this->title = title;
    this->description = description;
    this->priority = priority;
    this->deadline = deadline;

    completed = false;
    workerId = -1;
};

int Task::getId() const
{
    return id;
};

string Task::getTitle() const
{
    return title;
};

string Task::getDescription() const
{
    return description;
};

int Task::getPriority() const
{
    return priority;
};

bool Task::isCompleted() const
{
    return completed;
};

Date Task::getDeadline() const
{
    return deadline;
};

int Task::getWorkerId() const
{
    return workerId;
};

void Task::setTitle(const string& title)
{
    this->title = title;
};

void Task::setDescription(const string& description)
{
    this->description = description;
};

void Task::setPriority(int priority)
{
    this->priority = priority;
};

void Task::assignWorker(int workerId)
{
    this->workerId = workerId;
};

void Task::complete()
{
    completed = true;
};

bool Task::isExpired() const
{
    return !completed &&
           deadline < Date::today();
};

void Task::display() const
{
    cout << "ID: " << id << endl;
    cout << "Название: " << title << endl;
    cout << "Описание: " << description << endl;
    cout << "Приоритет: " << priority << endl;
    cout << "Дедлайн: " << deadline.toString() << endl;

    cout << "Статус: ";

    if (completed)
        cout << "Выполнена";
    else
        cout << "Не выполнена";

    cout << endl;

    if (workerId == -1)
        cout << "Работник не назначен" << endl;
    else
        cout << "ID работника: " << workerId << endl;
};
