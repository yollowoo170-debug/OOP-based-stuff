#include <iostream>
#include <string>

using namespace std;
using st = string;
using ll = long long;
using db = double;

class book
{
    static ll book_count;
    ll book_ID;
    st book_name;

public:
    void set_data(st bn, ll n)
    {
        book_name = bn;
        book_ID = n;
        book_count++;
    }

    void ini_cnt()
    {
        cout << "Initial Count: " << book_count << "\n";
    }

    void display()
    {
        cout << "Name: " << book_name << endl;
        cout << "Book ID: " << book_ID << endl;
        cout << "Total Books: " << book_count << endl;
        cout << "\n";
    }
};
ll book::book_count = 0;

int main(void)
{
    {
        book l;

        ll n;
        st bn;

        int choice = 0;

        while (choice != 2)
        {
            cout << "\n";
            l.ini_cnt();
            cout << "1.Input." << endl;
            cout << "2.Exit." << endl;
            cout << "Choose(1/2)." << endl;
            cin >> choice;
            cout << "\n";

            if (choice == 1)
            {
                cin.ignore();
                cout << "Name: ";
                getline(cin, bn);
                cout << "ID: ";
                cin >> n;
                cout << "\n";

                l.set_data(bn, n);

                l.display();
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
}