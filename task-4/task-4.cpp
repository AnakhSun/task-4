#include <math.h>
#include <conio.h>
#include <locale>
#include <iostream>

using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int main()
{
    setlocale(LC_ALL, "rus");
    int t = 1;
    while (t) {
        cout << "Вычисление значений функции \n\n";
        int x; // Значение аргумента
        double func; // Точное значение функции
        double sum; // Значение частичной суммы
        int n; // Число слагаемых в частичной сумме

        cout << "Задание 1" << endl;
        cout << "Введите значение аргумента > ";
        cin >> x;
        cout << "Задайте число слагаемых > ";
        cin >> n;
        func = log(x + sqrt(x * x + 1));// Вычисление "точного" значения
        double last;
        sum = sumN(x, n, last);
        cout << "Точное значение функции равно " << func << endl;
        cout << "Частичная сумма ряда равна " << sum << endl;
        cout << "Абсолютная погрешность равна " << fabs(func - sum) << endl;
        cout << "Последнее слагаемое равно " << last << endl;

        cout << "\nЗадание 2" << endl;
        double E;
        cout << "Введите значение аргумента > ";
        cin >> x;
        cout << "Задайте точность вычислений > ";
        cin >> E;
        func = log(x + sqrt(x * x + 1));// Вычисление "точного" значения
        sum = sumE(x, E, n);
        cout << "Точное значение функции равно " << func << endl;
        cout << "Частичная сумма ряда c заданной точностью равна " << sum << endl;
        cout << "Учтено " << n << " членов ряда" << endl;
        sum = sumE(x, E / 10, n);
        cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum << endl;
        cout << "Учтено " << n << " членов ряда" << endl;
        //_getch();
        cout << endl << "do u wanna continue? 1 - yes; 0 - no:   ";
        cin >> t;
    }
    return 0;
}


double sumN(double x, int n, double& last)
{
    // Инициализация переменной last
    last = x;
    double sum = last;
    for (int i = 1; i < n; ++i)
    {
        double r; // Отношение i-го слагаемлого к (i - 1)-му
       // Вычисление значения r 
        r = -x * x * (i * 2 - 1) / (2 * i) / (2 * i + 1);
        last *= r;
        sum += last;
    }
    return sum;
}

double sumE(double x, double E, int& n)
{
    double last;
    // Инициализация переменной last
    last = x;
    double sum = last;
    for (n = 1; fabs(last) > E; ++n)
    {
        double r; // Отношение n-го слагаемлого к (n - 1)-му
      // Вычисление значения r
        r = -x * x * (n * 2 - 1) / (2 * n) / (2 * n + 1);
        last *= r;
        sum += last;
    }
    return sum;
}