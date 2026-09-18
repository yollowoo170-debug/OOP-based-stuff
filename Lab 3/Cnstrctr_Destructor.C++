#include <bits/stdc++.h>
using namespace std;

class Marker
{
    char x;

public:
    Marker(char x)
    {
        char y;

        y = x;

        cout << "Char: " << y << endl;
    }
    ~Marker()
    {
        cout << "Destroy" << endl;
    }
    /* void set_data()
    {
        int y = x;
    } */
};

int main(void)
{
    Marker a('F');
    Marker b('G');
    {
        Marker c('H'); // To showcase life-time
    }
    cout << "Inside the main function." << "\n";

    /*  Marker a("a");
     Marker b("b");
     {
         Marker c("c")
     }
     insidefn(); */
    // Marker p;

    // p.setdata(2452436567)

    return 0;
}