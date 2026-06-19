#include "Worker.h"

#include <iostream>

Worker::Worker()
{
    id = 0;
    name = "";
    position = "";
};

Worker::Worker(
    int id,
    const string& name,
    const string& position
)
{
    this->id = id;
    this->name = name;
    this->position = position;
};

int Worker::getId() const
{
    return id;
};

string Worker::getName() const
{
    return name;
};

string Worker::getPosition() const
{
    return position;
};

void Worker::setName(const string& name)
{
    this->name = name;
};

void Worker::setPosition(const string& position)
{
    this->position = position;
};

void Worker::display() const
{
    cout << "ID: " << id << endl;
    cout << "Имя: " << name << endl;
    cout << "Должность: " << position << endl;
};

