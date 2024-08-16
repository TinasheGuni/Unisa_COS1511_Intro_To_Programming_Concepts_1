#include <iostream>

using namespace std;

int main()
{
    int x = 21;
    int y = 50;

    if (x > y)
    {
        cout << "**" << endl;
        cout << "****" << endl;
    }
    else if (x < y)
    {
        cout << "**" << endl;
        cout << "**" << endl;
    }
    else
        cout << "*" << endl;
    return 0;
}
