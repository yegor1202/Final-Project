#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>

#include "Project.h"
#include "Worker.h"

using namespace std;

class FileManager
{
public:
    static void saveWorkers(
        const vector<Worker>& workers
    );

    static void loadWorkers(
        vector<Worker>& workers
    );

    static void saveProjects(
        const vector<Project>& projects
    );

    static void loadProjects(
        vector<Project>& projects
    );

    static void saveTasks(
        const vector<Project>& projects
    );

    static void loadTasks(
        vector<Project>& projects
    );
};

#endif
