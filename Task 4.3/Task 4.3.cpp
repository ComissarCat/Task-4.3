#include <iostream>
#include <math.h>
using namespace std;

void task_1();
void task_2();
void task_3();
void task_4();
void task_5();
void task_6();
void task_7();
void menu();

int main()
{
    setlocale(LC_ALL, "Russian");

    menu();

    return 0;
}

void task_1()
{
    int a = 0, b = 0, c = 0, j = 0;
    for (int i = 100; i < 1000; i++)
    {
        a = i % 10;
        b = i / 10 % 10;
        c = i / 100;
        if (a == b or a == c or b == c) j++;
    }
    cout << "В промежутке от 100 до 999 " << j << " чисел, у которых есть две одинаковые цифры\n\n";
}

void task_2()
{
    int a = 0, b = 0, c = 0, j = 0;
    for (int i = 100; i < 1000; i++)
    {
        a = i % 10;
        b = i / 10 % 10;
        c = i / 100;
        if (a != b and a != c and b != c) j++;
    }
    cout << "В промежутке от 100 до 999 " << j << " чисел, у которых все цифры разные\n\n";
}

void task_3()
{
    int number = 0, length = 0, temporary_number = 0;
    cout << "Введите число: ";
    cin >> number;
    temporary_number = number;
    for (int i = 0; ; i++)
    {
        temporary_number /= 10;        
        length++;
        if (not temporary_number) break;
    }
    int* array = new int[length];
    temporary_number = number;
    for (int i = 0; i < length; i++)
    {
        array[i] = temporary_number % 10;
        temporary_number /= 10;        
    }
    number = 0;
    for (int i = 0, j = 1; i < length; i++)
    {
        if (array[i] != 3 and array[i] != 6) number += array[i] * j, j *= 10;
    }
    cout << "Число без троек и шестерок: " << number << endl << endl;
    delete[] array;
}

void task_4()
{
    int number = 0, counter = 0;
    cout << "Введите число: ";
    cin >> number;
    for (int i = 1; i < number; i++)
    {
        if (not(number % (int)pow(i, 2)) and (number % (int)pow(i, 3)))
        {
            cout << i << ": " << number << " % " << pow(i, 2) << " = " << number % (int)pow(i, 2) << ", "
                << number << " % " << pow(i, 3) << " = " << number % (int)pow(i, 3) << endl << endl;
            counter++;
        }
    }
    if (not counter) cout << "Чисел, на квадрат которых бы без остатка делилось " << number << ", а на куб которых бы оно без остатка не делилось, нет\n\n";
}

void task_5()
{
    int number = 0, sum_of_digits = 0, temporary_number = 0;
    cout << "Введите число: ";
    cin >> number;
    temporary_number = number;
    for (int i = 0; ; i++)
    {
        sum_of_digits += temporary_number % 10;
        temporary_number /= 10;
        if (not temporary_number) break;
    }
    cout << sum_of_digits << " ^ 3 = " << pow(sum_of_digits, 3) << ", " << number << " ^ 2 = " << pow(number, 2);
    if (pow(sum_of_digits, 3) == pow(number, 2)) cout << ", куб суммы цифр равен квадрату числа\n\n";
    else cout << ", куб суммы цифр НЕ равен квадрату числа\n\n";
}

void task_6()
{
    int number = 0;
    cout << "Введите число: ";
    cin >> number;
    cout << "Числа, на которые " << number << " делится без остатка:\n";
    for (int i = 1; i < number; i++)
    {
        if (not(number % i)) cout << i << endl;
    }
    cout << "\n\n";
}

void task_7()
{
    int number_1 = 0, number_2 = 0;
    cout << "Введите первое число: ";
    cin >> number_1;
    cout << "Введите второе число: ";
    cin >> number_2;
    cout << "Числа, на которые " << number_1 << " и " << number_2 << " делится без остатка:\n";
    if (number_1 > number_2) swap(number_1, number_2);
    for (int i = 1; i < number_1; i++)
    {
        if (not(number_1 % i) and not(number_2 % i)) cout << i << endl;
    }
    cout << "\n\n";
}

void menu()
{
    int task = 0;
    void(*list_of_menu[7])() = { task_1, task_2, task_3, task_4, task_5, task_6, task_7 };
    do
    {
        do
        {
            cout << "Введите номер задачи, 0 - выход: ";
            cin >> task;
        } while (task < 0 or task > 7);
        if (task) list_of_menu[task - 1]();
    } while (task);
}