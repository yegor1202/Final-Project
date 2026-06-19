#include <iostream>
#include <string>

#include "Task.h"
#include "TaskManager.h"
#include "FileManager.h"

using namespace std;

int main()
{   setlocale(LC_ALL, ".UTF-8");
    TaskManager manager;

    FileManager::loadWorkers(
        manager.getWorkers()
    );

    FileManager::loadProjects(
        manager.getProjects()
    );

    FileManager::loadTasks(
        manager.getProjects()
    );

    int choice;

    do
    {
        cout << "\n========== Менеджер задач ==========\n";
        cout << "1. Проекты\n";
        cout << "2. Работники\n";
        cout << "3. Добавить задачу\n";
        cout << "4. Назначить задачу\n";
        cout << "5. Завершить задачу\n";
        cout << "6. Просроченные задачи\n";
        cout << "7. Статистика\n";
        cout << "8. Сохранить\n";
        cout << "9. Выход\n";

        cout << "\nВыберите пункт: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int subChoice;

            cout << "\n1. Добавить проект\n";
            cout << "2. Показать проекты\n";
            cout << "Выберите пункт: ";
            cin >> subChoice;

            if (subChoice == 1)
            {
                int id;
                string name;
                string description;

                cout << "ID: ";
                cin >> id;

                cin.ignore();

                cout << "Название: ";
                getline(cin, name);

                cout << "Описание: ";
                getline(cin, description);

                manager.addProject(
                    Project(
                        id,
                        name,
                        description
                    )
                );

                cout << "Проект добавлен.\n";
            }
            else if (subChoice == 2)
            {
                manager.showProjects();
            }

            break;
        }

        case 2:
        {
            int subChoice;

            cout << "\n1. Добавить работника\n";
            cout << "2. Показать работников\n";
            cout << "Выберите пункт: ";
            cin >> subChoice;

            if (subChoice == 1)
            {
                int id;
                string name;
                string position;

                cout << "ID: ";
                cin >> id;

                cin.ignore();

                cout << "Имя: ";
                getline(cin, name);

                cout << "Должность: ";
                getline(cin, position);

                manager.addWorker(
                    Worker(
                        id,
                        name,
                        position
                    )
                );

                cout << "Работник добавлен.\n";
            }
            else if (subChoice == 2)
            {
                manager.showWorkers();
            }

            break;
        }

        case 3:
        {
            int projectId;
            int taskId;
            int priority;

            string title;
            string description;
            string deadlineText;

            cout << "ID проекта: ";
            cin >> projectId;

            cout << "ID задачи: ";
            cin >> taskId;

            cin.ignore();

            cout << "Название: ";
            getline(cin, title);

            cout << "Описание: ";
            getline(cin, description);

            cout << "Приоритет: ";
            cin >> priority;

            cout << "Дедлайн (дд.мм.гггг): ";
            cin >> deadlineText;

            Task task(
                taskId,
                title,
                description,
                priority,
                Date::fromString(deadlineText)
            );

            if (
                manager.addTask(
                    projectId,
                    task
                )
            )
            {
                cout << "Задача добавлена.\n";
            }
            else
            {
                cout << "Проект не найден.\n";
            }

            break;
        }

        case 4:
        {
            int projectId;
            int taskId;
            int workerId;

            cout << "ID проекта: ";
            cin >> projectId;

            cout << "ID задачи: ";
            cin >> taskId;

            cout << "ID работника: ";
            cin >> workerId;

            if (
                manager.assignTask(
                    projectId,
                    taskId,
                    workerId
                )
            )
            {
                cout << "Задача назначена.\n";
            }
            else
            {
                cout << "Ошибка назначения.\n";
            }

            break;
        }

        case 5:
        {
            int projectId;
            int taskId;

            cout << "ID проекта: ";
            cin >> projectId;

            cout << "ID задачи: ";
            cin >> taskId;

            if (
                manager.completeTask(
                    projectId,
                    taskId
                )
            )
            {
                cout << "Задача завершена.\n";
            }
            else
            {
                cout << "Задача не найдена.\n";
            }

            break;
        }

        case 6:
        {
            manager.showExpiredTasks();
            break;
        }

        case 7:
        {
            cout << "\nВсего задач: "
                 << manager.getTotalTaskCount()
                 << endl;

            cout << "Выполнено задач: "
                 << manager.getCompletedTaskCount()
                 << endl;

            cout << "Просрочено задач: "
                 << manager.getExpiredTaskCount()
                 << endl;

            break;
        };

        case 8:
        {
            FileManager::saveWorkers(
                manager.getWorkers()
            );

            FileManager::saveProjects(
                manager.getProjects()
            );

            FileManager::saveTasks(
                manager.getProjects()
            );

            cout << "Данные сохранены.\n";

            break;
        };

        case 9:
        {
            FileManager::saveWorkers(
                manager.getWorkers()
            );

            FileManager::saveProjects(
                manager.getProjects()
            );

            FileManager::saveTasks(
                manager.getProjects()
            );

            cout << "Выход из программы.\n";

            break;
        };

        default:
        {
            cout << "Неверный пункт меню.\n";
        }
        };

    } while (choice != 9);

    return 0;
};
