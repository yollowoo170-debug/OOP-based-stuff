#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Matrix
{
private:
    ll mat[99][99];
    ll row, column, value;

    static ll count;

public:
    Matrix() : row(0), column(0), value(0) {}

    ll setValue(ll r, ll c, ll v);
    ll s_antiDiag(ll a[][99], ll r, ll c, ll v);
    ll s_diag(ll a[][99], ll r, ll c, ll v);
    friend void display(const Matrix &sum);
};
ll Matrix::count = 0;

ll Matrix::setValue(ll r, ll c, ll v)
{
    row = r;
    column = c;
    value = v;
}

ll Matrix::s_antiDiag(ll a[][99], ll r, ll c, ll v)
{
    ll i, j, s_ad = 0;

    for (i = 0; i < r; i++)
    {
        j = r - 1 - i;
        s_ad += a[i][j];
    }

    return s_ad;
}
ll Matrix::s_diag(ll a[][99], ll r, ll c, ll v)
{
    ll i, j, s_d = 0;

    for (int i = 0; i < r; i++)
    {
        s_d += a[i][i];
    }
    return s_d;
}
display(const Matrix &sum)
{
    cout << sum.s_ad << "\n";
    cout << sum.s_d << "\n";
}

int main(void)
{
    ll mat[99][99], anti_diag_sum, diag_sum, row, col, i, j;

    cout << "Enter dimension of Mat R(A) = ";
    cin >> row;
    cout << "Enter dimension of Mat C(A) = ";
    cin >> col;
    cout << "Give matA elements: ";

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cin >> mat[i][j];
        }
    }

    diag_sum = s_diag(mat, row, col);
    anti_diag_sum = s_antiDiag(mat, row, col);

    cout << "Sum of Diagonal: ";
    cout << diag_sum;

    cout << "Sum of Anti Diagonal: ";
    cout << anti_diag_sum;

    return 0;
}