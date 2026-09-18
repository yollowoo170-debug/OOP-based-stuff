#include <bits/stdc++.h>

using namespace std;

class XYZ;
class ABC
{
    int a;

public:
    ABC(int m) : a(m) {}
    friend int sum(const ABC &m, const XYZ &n);
};
class XYZ
{
    int x;

public:
    XYZ(int n) : x(n) {}
    friend int sum(const ABC &m, const XYZ &n);
};
int sum(const ABC &m, const XYZ &n)
{
    cout << "Sum: " << m.a + n.x << endl;

    return 0;
}

int main(void)
{
    int num1, num2;

    cout << "Enter two int values: ";
    cin >> num1 >> num2;

    ABC A(num1);
    XYZ X(num2);

    sum(A, X);

    return 0;
}