#include <bits/stdc++.h>
using namespace std;
struct user_info
{
    string acc_name = "Salazar Slytherin";
    int acc_num = 1474;
};

class atm
{
private:
    long long balance;

public:
    atm(long long initial_balance)
    {
        balance = initial_balance;
    }

    void diposit(long long amount)
    {
        if (amount <= 10000)
        {
            cout << "Amount has to be greater than 10000. Get a job." << endl;
        }
        else
        {
            balance += amount;
            cout << "Done." << endl;
        }
    }
    void withdraw(long long amount)
    {
        if (amount <= 1000)
        {
            cout << "Minimum 1001" << endl;
        }
        else if (amount > balance)
        {
            cout << "Don't overestimate your pockets mate." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Enjoy" << endl;
        }
    }
    void display_balance()
    {
        cout << "Current balance: " << balance << endl;
    }
};

int main(void)
{
    user_info user;
    atm acc(1000);
    int choice = 0;
    long long stash, grab;

    while (choice != 3)
    {
        acc.display_balance();
        cout << "\n";
        cout << "1.Diposit." << endl;
        cout << "2.Withdraw." << endl;
        cout << "3.Exit." << endl;
        cout << "Choose(1-3)." << endl;
        cin >> choice;

        if (choice == 1)
        {
            cout << "How much: " << endl;
            cin >> stash;
            acc.diposit(stash);
        }
        else if (choice == 2)
        {
            cout << "How much: " << endl;
            cin >> grab;
            acc.withdraw(grab);
        }
        else if (choice == 3)
        {
            cout << "Why did ya waste me time mate?" << endl;
        }
        else
        {
            cout << "Invalid input" << "\n";
        }
    }
    return 0;
}