#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using st = string;

class BankAccount // Lines 9 - 16: All variables here are private.
{
private:
    ll accNo;
    st holderName;
    db balance;

    static ll totalAccounts; // these 3 static members are shared across all
    static db interestRate;
    static db totalBankMoney;

public:
    db Interest;

    static void showTotal()
    {
        cout << "Number of accounts registered: " << totalAccounts << endl;
    }
    static void showtotalBankMoney()
    {
        cout << "Total stored currency in the bank: " << fixed << totalBankMoney << endl;
        // fixed is used here to keep the output in decimal.
    }
    static void setRate(db r)
    {
        interestRate = r;

        cout << "The rate of Interest: " << interestRate << endl
             << endl;
    }

    void openAccount(st name, db ini_dep)
    {
        holderName = name;
        balance = ini_dep;
        accNo = 1001 + totalAccounts;

        totalAccounts++;
        totalBankMoney += ini_dep; // Learned from Fahad's mistake.

        cout << "Account created SUCCESSFULLY!!! " << endl
             << "Your account number is: " << accNo << endl
             << endl;
    }
    void addInterest()
    {
        Interest = balance + (interestRate * 100.00);
        balance += Interest;
        totalBankMoney += balance;

        cout << "Added interest of: " << Interest << " to Account no. " << accNo << endl;
    }
    void display()
    {
        cout << "Account no. " << accNo << endl;
        cout << "Name: " << holderName << endl;
        cout << "Balance: " << fixed << balance << endl
             << endl;
    }
    void deposit(ll amount);
    void withdraw(ll amount);
};

ll BankAccount::totalAccounts = 0;
db BankAccount::interestRate = 0.0;
db BankAccount::totalBankMoney = 0.0;

// Defined deposit() and withdraw() OUTSIDE the class using ::
void BankAccount ::deposit(ll amount)
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
void BankAccount ::withdraw(ll amount)
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

// distributes and gets all the infos for objests or accounts.
BankAccount *fetch_acc(ll acn, BankAccount &acc1, BankAccount &acc2, BankAccount &acc3)
{
    if (acn == 1001)
    {
        return &acc1;
    }
    if (acn == 1002)
    {
        return &acc2;
    }
    return nullptr;
}

int main(void)
{
    ios::sync_with_stdio(false);

    BankAccount acc1, acc2, acc3, a; // Objects.

    /*     If,

        a.balance = 99999; is written.

        Then,

        Lab_2_All_mods.C++: In function 'int main()':
    Lab_2_All_mods.C++:124:7: error: 'db BankAccount::balance' is private within this context
      124 |     a.balance = 99999;
          |       ^~~~~~~
    Lab_2_All_mods.C++:12:8: note: declared private here
       12 |     db balance;
          |        ^~~~~~~

          shows up.
    */

    BankAccount *user = nullptr; // Lines 110 - 114 are all needed variables in the main function.
    db stash, grab, ints, ini_dep1, ini_dep2, ini_dep3;
    ll acc_no;
    int choice;
    st name1, name2, name3;

    cout << "Apply Interest: "; // Took the interest rate.
    cin >> ints;
    BankAccount::setRate(ints);

    // Creating Account 1
    cin.ignore();
    cout << "Creating Account(1st)...." << "\n";
    cout << "User name: ";
    getline(cin, name1);
    cout << "Starting diposit: ";
    cin >> ini_dep1;
    acc1.openAccount(name1, ini_dep1);

    // Creating Account 2
    cin.ignore();
    cout << "Creating Account(2nd)...." << "\n";
    cout << "User name: ";
    getline(cin, name2);
    cout << "Starting diposit: ";
    cin >> ini_dep2;
    acc2.openAccount(name2, ini_dep2);

    // Creating Account 3
    cin.ignore();
    cout << "Creating Account(3rd)...." << "\n";
    cout << "User name: ";
    getline(cin, name3);
    cout << "Starting diposit: ";
    cin >> ini_dep3;
    acc3.openAccount(name3, ini_dep3);

    // User interface
    while (choice != 6)
    {
        cout << endl; // Lines 162 - 170: The Menu.
        cout << "Select operation: " << endl;
        cout << "1. Deposit." << endl;
        cout << "2. Withdraw." << endl;
        cout << "3. Check Interest." << endl;
        cout << "4. Account Information." << endl;
        cout << "5. Show Bank Totals(Balances)." << endl;
        cout << "6. Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) // Used switch-case instead of if-else for greater efficiency.
        {
        case 1: // Diposit
            cout << "Enter Account no." << endl;
            cin >> acc_no;
            user = fetch_acc(acc_no, acc1, acc2, acc3);
            if (user)
            {
                cout << "Amount to diposit: ";
                cin >> stash;

                user->deposit(stash);
            }
            else
            {
                cout << "Invalid Account Number" << endl;
            }

            break;

        case 2: // Withdraw
            cout << "Enter Account no." << endl;
            cin >> acc_no;
            user = fetch_acc(acc_no, acc1, acc2, acc3);
            if (user)
            {
                cout << "Withdraw Amount: ";
                cin >> grab;

                user->withdraw(grab);
            }
            else
            {
                cout << "Invalid Account Number" << endl;
            }

            break;

        case 3: // Interest
            cout << "Enter Account no." << endl;
            cin >> acc_no;
            user = fetch_acc(acc_no, acc1, acc2, acc3);
            if (user)
            {
                user->addInterest();
            }
            else
            {
                cout << "Invalid Account Number" << endl;
            }

            break;

        case 4: // To check your active accounts
            acc1.display();
            acc2.display();
            acc3.display();

            break;

        case 5: // To keep track of Balance
            BankAccount::showTotal();
            BankAccount::showtotalBankMoney();

            break;

        case 6: // Exit
            cout << "Exiting..." << endl;
            break;

        default: // Validation
            cout << "Invalid input" << endl;
            break;
        }
    }
    return 0;
}
