#include <bits/stdc++.h>
using namespace std;
using db = double;

class Complex
{
    db real_total;
    db img_total;

    db real_sub;
    db img_sub;

public:
    Complex() : real_total(0), real_sub(0), img_total(0), img_sub(0) {}

    Complex &add(db r1, db i1, db r2, db i2)
    {
        this->real_total = r1 + r2;
        this->img_total = i1 + i2;

        return *this;
    }
    Complex &substract(db r1, db i1, db r2, db i2)
    {
        this->real_sub = r1 - r2;
        this->img_sub = i1 - i2;

        return *this;
    }
    int display(int t)
    {
        if (t == 1)
        {
            cout << "Addition: " << real_total << " + " << img_total << "i" << endl;
        }
        if (t == 2)
        {
            cout << "Substraction: " << real_sub << " - " << img_sub << "i" << endl;
        }
        return 0;
    }

    ~Complex()
    {
        cout << "Done" << "\n";
    }
};

int main(void)
{
    int number = 0, choice;
    db real_num1, real_num2, img_num1, img_num2;
    db add_ans, sub_ans;

    cout << "Number of instances: ";
    cin >> number;

    Complex *a = new Complex[number];
    cout << "Enter objects: ";

    for (int i = 0; i < number; i++)
    {
        cout << "For first one-" << "\n";
        cout << "Enter real number: ";
        cin >> real_num1;
        cout << "Enter imaginary number: ";
        cin >> img_num1;

        cout << "For secound one-" << "\n";
        cout << "Enter real number: ";
        cin >> real_num2;
        cout << "Enter imaginary number: ";
        cin >> img_num2;

        while (choice != 3)
        {
            while (choice != 3)
            {
                cout << endl; // The Menu.
                cout << "Select operation: " << endl;
                cout << "1. Add." << endl;
                cout << "2. Substract." << endl;
                cout << "3. Exit." << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cout << endl;

                switch (choice)
                {
                case 1: // Add

                    a[i].add(real_num1, img_num1, real_num2, img_num2).display(1);
                    break;

                case 2: // Sub

                    a[i].substract(real_num1, img_num1, real_num2, img_num2).display(2);
                    break;

                case 3: // Exit
                    cout << "Exiting..." << endl;
                    break;

                default: // Validation
                    cout << "Invalid input" << endl;
                    break;
                }
            }
        }
    }
    delete[] a;
    return 0;
}