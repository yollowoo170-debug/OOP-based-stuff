#include <bits/stdc++.h>
using namespace std;

class Counter
{
    int value;

public:
    Counter &setValue(int value)
    {
        this->value = value;
        return *this;
    }
    Counter &increment()
    {
        this->value++;
        return *this;
    }
    Counter &show()
    {
        cout << "incrimented value: " << value << "\n";
        return *this;
    }
};
int main(void)
{
    Counter c;
    c.setValue(100).increment().show().increment().show().setValue(200).increment().show().increment().show();
    /*  c.setValue(90).show();
     c.increment().show();
     c.increment().show(); */

    return 0;
}