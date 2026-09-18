#include <bits/stdc++.h>
using namespace std;

class Message
{
    char *body;

public:
    Message(const char *text)
    {
        body = new char[strlen(text) + 1];
        strcpy(body, text);
    }

    Message(const Message &other)
    {
        body = new char[strlen(other.body) + 1];
        strcpy(body, other.body);
    }

    Message &operator=(const Message &other)
    {
        if (this != &other)
        {
            delete[] body;
            body = new char[strlen(other.body) + 1];
            strcpy(body, other.body);
        }
        return *this;
    }

    void edit(const char *newText)
    {
        delete[] body;
        body = new char[strlen(newText) + 1];
        strcpy(body, newText);
    }

    void display()
    {
        cout << "Text: " << body << " | Address: " << (void *)body << endl;
    }

    ~Message()
    {
        delete[] body;
    }
};

int main(void)
{
    Message m1("Original Message");
    Message m2(m1);

    Message m3("Temporary Message");
    m3 = m1;

    m2.edit("This is a much longer replacement text for m2");

    cout << "m1 state (unchanged): ";
    m1.display();

    cout << "m2 state (edited):    ";
    m2.display();

    cout << "m3 state (assigned):  ";
    m3.display();

    return 0;
}