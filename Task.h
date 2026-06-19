#ifndef TASK_H
#define TASK_H

#include <string>
#include "Date.h"

using namespace std;

class Worker;

class Task
{
private:
    int id;
    string title;
    string description;
    int priority;
    bool completed;

    Date deadline;
    Worker* assignedWorker;

public:
    Task();

    Task(
        int id,
        const string& title,
        const string& description,
        int priority,
        const Date& deadline
    );

    int getId() const;
    string getTitle() const;
    string getDescription() const;
    int getPriority() const;
    bool isCompleted() const;

    Date getDeadline() const;
    Worker* getAssignedWorker() const;

    void setTitle(const string& title);
    void setDescription(const string& description);
    void setPriority(int priority);

    void assignWorker(Worker* worker);
    void complete();

    bool isExpired() const;
    void display() const;
};

#endif
