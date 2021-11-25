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
        cout << "���������� �������� ������� \n\n";
        int x; // �������� ���������
        double func; // ������ �������� �������
        double sum; // �������� ��������� �����
        int n; // ����� ��������� � ��������� �����

        cout << "������� 1" << endl;
        cout << "������� �������� ��������� > ";
        cin >> x;
        cout << "������� ����� ��������� > ";
        cin >> n;
        func = log(x + sqrt(x * x + 1));// ���������� "�������" ��������
        double last;
        sum = sumN(x, n, last);
        cout << "������ �������� ������� ����� " << func << endl;
        cout << "��������� ����� ���� ����� " << sum << endl;
        cout << "���������� ����������� ����� " << fabs(func - sum) << endl;
        cout << "��������� ��������� ����� " << last << endl;

        cout << "\n������� 2" << endl;
        double E;
        cout << "������� �������� ��������� > ";
        cin >> x;
        cout << "������� �������� ���������� > ";
        cin >> E;
        func = log(x + sqrt(x * x + 1));// ���������� "�������" ��������
        sum = sumE(x, E, n);
        cout << "������ �������� ������� ����� " << func << endl;
        cout << "��������� ����� ���� c �������� ��������� ����� " << sum << endl;
        cout << "������ " << n << " ������ ����" << endl;
        sum = sumE(x, E / 10, n);
        cout << "��������� ����� ���� c ���������, ������� � 10 ���, ����� " << sum << endl;
        cout << "������ " << n << " ������ ����" << endl;
        //_getch();
        cout << endl << "do u wanna continue? 1 - yes; 0 - no:   ";
        cin >> t;
    }
    return 0;
}


double sumN(double x, int n, double& last)
{
    // ������������� ���������� last
    last = x;
    double sum = last;
    for (int i = 1; i < n; ++i)
    {
        double r; // ��������� i-�� ����������� � (i - 1)-��
       // ���������� �������� r 
        r = -x * x * (i * 2 - 1) / (2 * i) / (2 * i + 1);
        last *= r;
        sum += last;
    }
    return sum;
}

double sumE(double x, double E, int& n)
{
    double last;
    // ������������� ���������� last
    last = x;
    double sum = last;
    for (n = 1; fabs(last) > E; ++n)
    {
        double r; // ��������� n-�� ����������� � (n - 1)-��
      // ���������� �������� r
        r = -x * x * (n * 2 - 1) / (2 * n) / (2 * n + 1);
        last *= r;
        sum += last;
    }
    return sum;
}