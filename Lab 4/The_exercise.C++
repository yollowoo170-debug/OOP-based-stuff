#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using st = string;
using db = double;

class Student
{
private:
    ll roll;
    st name;
    db marks;

public:
    Student() : roll(0), name(""), marks(0.0) {}

    void setData()
    {
        cout << "Roll: ";
        cin >> roll;

        cout << "Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Marks: ";
        cin >> marks;
        cout << "\n";

        db m = marks;

        if (m > 100 || m < 0)
        {
            cout << "Invalid" << endl;
        }
    }

    void display()
    {
        cout << "Name: " << name << endl
             << "Roll: " << roll << endl
             << "Marks: " << marks << endl
             << endl;
    }

    db bring_marks()
    {
        return marks;
    }
};

void processed_result(Student Arr[], int num)
{
    db total_marks = 0.0;
    int top_score = 0;

    for (int i = 0; i < num; i++)
    {
        Arr[i].display();

        total_marks += Arr[i].bring_marks();

        if (Arr[i].bring_marks() > Arr[top_score].bring_marks())
        {
            top_score = i;
        }
    }

    cout << "Avg: " << total_marks / num << endl;
    cout << "Highest marks: " << Arr[top_score].bring_marks() << endl
         << endl;
}

int main(void)
{
    Student list[5];

    for (int i = 0; i < 5; i++)
    {
        list[i].setData();
    }
    processed_result(list, 5);

    ll index;
    cout << "Index: ";
    cin >> index;
    cin.ignore();

    Student *pupil = new Student[index];
    for (int i = 0; i < index; i++)
    {
        pupil[i].setData();
    }

    processed_result(pupil, index);

    delete[] pupil;

    return 0;
}