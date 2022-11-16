#include <iostream>
#include <stdio.h>

using namespace std;

class Fraction
{
    private:
        double *list;
        double fract, numerator, denominator;
        bool sign;
        char yn;
        int *p; // указатель на участок памяти
    public:
        Fraction() // Конструктор по умолчанию
        {
            cout << "Введите числитель вашей дроби: "; cin >> numerator;
            cout << "Введите знаменатель вашей дроби: "; cin >> denominator;
            fract = numerator / denominator;
            cout << "Сделать дробь отрацательной?(y/n) "; cin >> yn;
            if (yn == 'y')
                fract = fract * -1;
            cout << "Конструктор сработал!" << endl;
            cout << "<<-------------->>  " << endl;
       }
        Fraction(const Fraction &) // Конструктор копирования
        {
            cout << "Конструктор копирования сработал!" << endl;
            cout << "<<-------------->>  " << endl;
        }
        ~Fraction() // Деструктор
        {
            cout << "Деструктор сработал для переменной: " << this << endl;
        }
        double GetFraction() // Функция для забора значения переменной fract
        {
            return fract;
        }
};

void Summation(Fraction list[], int n) // Функция сложения
{   
    double value;
    cout << "Введите число: "; cin >> value;
    for (int i = 0; i<n; i++)
    {
        double counter = 0.00;
        counter = list[i].GetFraction() + value;
        cout << "Значение после сложения " << i+1 << " дроби = " << counter << endl; //, i+1, "дроби = ", counter;
    }
    cout << "<<-------------->>  " << endl;
}

void Subtraction(Fraction list[], int n) // Функция вычитания
{
    double value;
    cout << "Введите число: "; cin >> value;
    for (int i = 0; i<n; i++)
    {
        double counter = 0.00;
        counter = list[i].GetFraction() - value;
        cout << "Значение после вычитания " << i+1 << " дроби = " << counter << endl;
    }
    cout << "<<-------------->>  " << endl;
}

void Multiplication(Fraction list[], int n) // Функция умножения
{
    double value;
    cout << "Введите число: "; cin >> value;
    for (int i = 0; i<n; i++)
    {
        double bb = 0;
        double counter = 0.00;
        counter = list[i].GetFraction() * value;
        cout << "Значение после умножения " << i+1 << " дроби = " << counter << endl;
    }
    cout << "<<-------------->>  " << endl;
}

void Division(Fraction list[], int n) // Функция деления
{
    double value;
    cout << "Введите число: "; cin >> value;
    for (int i = 0; i<n; i++)
    {
        double counter = 0.00;
        counter = list[i].GetFraction() / value;
        cout << "Значение после деления " << i+1 << " дроби = " << counter << endl;
    }
    cout << "<<-------------->>  " << endl;
}

void SwitchInstructions() // Пункты меню
{
    cout << "1 - Сложить дроби\n";
    cout << "2 - Вычесть дроби\n";
    cout << "3 - Умножить дроби\n";
    cout << "4 - Разделить дроби\n";
    cout << "0 - Выход\n";
    cout << "<<-------------->>  " << endl;
}

int main()
{
    int choice, n;
    Fraction *list;
    cout << "Введите число нужных вам дробей: "; cin >> n;
    list = new Fraction[n];
    Fraction CList(*list);
    SwitchInstructions();
    do 
    {
        cout << "Выберите пункт меню: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                Summation(list, n);
                break;
            case 2:
                Subtraction(list, n);
                break;
            case 3:
                Multiplication(list, n);
                break;
            case 4:
                Division(list, n);
                break;
        }
    }
    while(choice != 0);
    delete[]list;
    return 0;
}