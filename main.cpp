#include <iostream>

using namespace std;

int main()
{
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
            break;

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
        }

    } while (choice != 9);

    return 0;
}

