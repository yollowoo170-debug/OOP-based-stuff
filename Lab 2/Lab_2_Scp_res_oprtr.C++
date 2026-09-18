#include <iostream>
#include <string>

using namespace std;
using st = string;
using ll = long long;
using db = double;

class student
{
private:
    ll roll;
    st name;
    db marks;

public:
    student() : roll(0), name(""), marks(0.0) {}

    bool set_data(int r, st n, db m)
    {
        if (m > 100 || m < 0)
        {
            cout << "Invalid" << "\n";

            return false;
        }
        roll = r;
        name = n;
        marks = m;

        return true;
    }
    char getGrade();
    void display();
};

char student ::getGrade()
{
    if (marks >= 90)
    {
        return 'A';
    }
    if (marks >= 80)
    {
        return 'B';
    }
    if (marks >= 70)
    {
        return 'C';
    }
    if (marks >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

void student::display()
{
    cout << "Name: " << name << endl;
    cout << "Roll: " << roll << endl;
    cout << "Marks: " << marks << endl;
    cout << "Grade: " << getGrade() << endl;
    cout << "\n";
}

int main(void)
{
    student s;

    ll rl;
    st nm;
    db mk;
    int choice = 0;

    while (choice != 2)
    {
        cout << "\n";
        cout << "1.Input." << endl;
        cout << "2.Exit." << endl;
        cout << "Choose(1/2)." << endl;
        cin >> choice;
        cout << "\n";

        if (choice == 1)
        {
            cout << "Roll: ";
            cin >> rl;
            cout << "Name: ";
            cin >> nm;
            cout << "Marks: ";
            cin >> mk;
            cout << "\n";

            s.set_data(rl, nm, mk);

            s.display();
        }
        else if (choice == 2)
        {
            break;
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }
    return 0;
}
