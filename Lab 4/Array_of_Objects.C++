#include <bits/stdc++.h>
using namespace std;
using st = string;

class Avengers // Class creation
{
private:
    st g;

public:
    void set_data(st nm)
    {
        g = nm;
    }
    void display()
    {
        cout << g << endl;
    }
};

int main(void)
{
    Avengers group[3]; // An array of objects

    cout << "Teams who will fight against DOOM:" << "\n\n";

    group[0].set_data("The Avengers");
    group[0].display();

    group[1].set_data("Fantastic Four");
    group[1].display();

    group[2].set_data("The X-Men");
    group[2].display();

    cout << endl;
}
