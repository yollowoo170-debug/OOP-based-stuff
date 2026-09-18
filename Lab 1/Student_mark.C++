#include <bits/stdc++.h>
using namespace std;
using st = string;
using db = double;

class Student_mark
{
private:
    int roll_number;
    st name;
    db marks;

public:
    Student_mark() : roll_number(0), name(""), marks(0.0) {}

    bool setData(int r, st &n, db m)
    {
        if (m > 100 || m < 0)
        {
            cout << "Invalid" << endl;

            return false;
        }
        roll_number = r;
        name = n;
        marks = m;

        return true;
    }

    void addBonus(db b)
    {
        if (b > 0)
        {
            marks += b;

            if (marks > 100)
            {
                marks = 100;
            }
        }
    }

    char getGrade()
    {
        if (marks >= 90)
        {
            return 'A';
        }
        if (marks >= 85)
        {
            return 'B';
        }
        if (marks >= 70)
        {
            return 'C';
        }
        if (marks >= 41)
        {
            return 'D';
        }
        else
        {
            return 'F';
        }
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll_number << endl;
        cout << "Total Marks: " << marks << endl;
        cout << "Grade: " << getGrade() << endl;
    }
};

int main(void)
{
    Student_mark sm;
    int rl;
    st nm;
    db mk, bns;

    cout << "Name: ";
    getline(cin, nm);
    cout << "Roll: ";
    cin >> rl;
    cout << "Marks: ";
    cin >> mk;
    cout << "Bonus: ";
    cin >> bns;
    cout << "\n";

    if (sm.setData(rl, nm, mk))
    {
        sm.addBonus(bns);
        sm.display();
    }
    return 0;
}
