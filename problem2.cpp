#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

float *add(float *a, float *b, int size_a, int size_b)
{
    float *c = new float[max(size_a, size_b)];
    for (int i = 0; i < max(size_a, size_b); i++)
    {
        c[i] = 0;
        if (i < size_a)
        {
            c[i] += a[i];
        }
        if (i < size_b)
        {
            c[i] += b[i];
        }
    }
    return c;
}
void print(float *a, int size_a, float consta)
{
    bool all_zero = true;
    for (int i = size_a - 1; i >= 0; i--)
    {
        if (a[i] != 0)
        {
            all_zero = false;
            if (i != size_a - 1)
            {
                if (a[i] < 0)
                {
                    cout << " - ";
                }
                else
                {
                    cout << " + ";
                }
            }
            else
            {
                if (a[i] < 0)
                {
                    cout << "-";
                }
            }
            if (i == 0)
            {
                cout << abs(a[i]);
                break;
            }

            cout << abs(a[i]) << "x^" << i;
        }
    }
    if (all_zero)
    {
        cout << "0";
    }
    cout << " = " << consta;
    cout << endl;
}
float *multiply(float *a, float *b, int size_a, int size_b)
{
    float *c = new float[size_a + size_b - 1];
    for (int i = 0; i < size_a + size_b - 1; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < size_a; i++)
    {
        for (int j = 0; j < size_b; j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }
    return c;
}
float *subtract(float *a, float *b, int size_a, int size_b)
{
    float *c = new float[max(size_a, size_b)];
    for (int i = 0; i < max(size_a, size_b); i++)
    {
        c[i] = 0;
        if (i < size_a)
        {
            c[i] += a[i];
        }
        if (i < size_b)
        {
            c[i] -= b[i];
        }
    }
    return c;
}
int main()
{
    while (1)
    {
        cout << "1 - EXIT\n2 - start a program\n";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            break;
        }
        cout << "enter order of first polynomial : ";
        int n;
        cin >> n;
        float consta = 0;
        float *a = new float[n + 1];
        cout << "enter coefficients of first polynomial : ";
        cin >> consta;
        for (int i = 0; i < n + 1; i++)
        {
            cin >> a[i];
        }
        cout << "enter order of second polynomial : ";
        int m;
        cin >> m;
        float constb = 0;
        float *b = new float[m + 1];
        cout << "enter coefficients of second polynomial : ";
        cin >> constb;
        for (int i = 0; i < m + 1; i++)
        {
            cin >> b[i];
        }
        while (1)
        {
            cout << "1 - EXIT\n2 - sum of two polynomial\n3 - difference of two polynomial\n4 - product of two polynomial\n5 - all\n";
            cin >> choice;
            if (choice == 1)
            {
                break;
            }
            float constc = 0;
            float *c;
            if (choice == 2 || choice == 5)
            {
                cout << "sum of two polynomials : ";
                c = add(a, b, n + 1, m + 1);
                constc = consta + constb;
                print(c, max(n + 1, m + 1), constc);
            }
            if (choice == 3 || choice == 5)
            {
                cout << "difference of two polynomials : ";
                constc = constb - consta;
                c = subtract(b, a, m + 1, n + 1);
                print(c, max(n + 1, m + 1), constc);
            }
            if (choice == 4 || choice == 5)
            {
                cout << "product of two polynomials : ";
                constc = consta * constb;
                c = multiply(a, b, n + 1, m + 1);
                print(c, n + 1 + m, constc);
            }
        }
        delete[] a;
        delete[] b;
    }
}