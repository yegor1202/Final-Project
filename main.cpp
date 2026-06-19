#include <iostream>
#include <string>
#include "Task.h"
#include "TaskManager.h"
using namespace std;

int main()
{   TaskManager manager;
    int choice;

    do
    {
        cout << "\n=================================\n";
        cout << "          Менеджер задач\n";


        cout << "\nГлавное меню:\n";
        cout << "1. Проекты\n";
        cout << "2. Работники\n";
        cout << "3. Задачи\n";
        cout << "4. Назначить задачу\n";
        cout << "5. Завершить задачу\n";
        cout << "6. Просроченные задачи\n";
        cout << "7. Статистика\n";
        cout << "8. Сохранить данные\n";
        cout << "9. Выход\n";

        cout << "\nВыберите пункт: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            break;

        case 2:
            break;

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
        };

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            break;

        case 9:
            break;

        default:
            cout << "\nВведите число от 1 до 9.\n";
        };

    } while (choice != 9);

    return 0;
};

