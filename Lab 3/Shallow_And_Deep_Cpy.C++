#include <iostream>
#include <cstring>
using namespace std;

class Name
{
    char *text;

public:
    // Parameterized Constructor
    Name(const char *n)
    {
        text = new char[strlen(n) + 1];
        strcpy(text, n); // Copy the string into allocated memory
        cout << "constructor : " << text << " at address " << (void *)text << "\n";
    }

    // Deep Copy Constructor (Fixes the crash)
    Name(const Name &other)
    {
        text = new char[strlen(other.text) + 1]; // Allocate NEW memory block
        strcpy(text, other.text);                // Copy string contents
        cout << "copy constr : " << text << " at address " << (void *)text << "\n";
    }

    void change(const char *n)
    {
        // Safe reallocation in case the new string is longer
        delete[] text;
        text = new char[strlen(n) + 1];
        strcpy(text, n);
    }

    void display()
    {
        cout << " " << text << " at address " << (void *)text << "\n";
    }

    ~Name()
    {
        cout << "destructor  : freeing " << (void *)text << "\n";
        delete[] text;
    }
};

int main(void)
{
    Name a("Karim");
    Name b(a); // Now calls the deep copy constructor

    cout << "\n after copying:\n";
    a.display();
    b.display();

    b.change("Rahim");

    cout << "\n after changing only b:\n";
    a.display();
    b.display();

    cout << "\n now both objects are destroyed:\n";

    return 0;
}