#ifndef WORKER_H
#define WORKER_H

#include <string>

using namespace std;

class Worker
{
private:
    int id;
    string name;
    string position;

public:
    Worker();

    Worker(
        int id,
        const string& name,
        const string& position
    );

    int getId() const;
    string getName() const;
    string getPosition() const;

    void setName(const string& name);
    void setPosition(const string& position);

    void display() const;
};

#endif

