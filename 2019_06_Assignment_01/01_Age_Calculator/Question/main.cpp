#include <iostream>

using namespace std;

int main()
{
    int age;
    cout << "Enter your age: " << endl;
    cin >> age;

    if (age < 13 || age >= 20)
        cout << "Sorry, you're not a teenager." << endl;
    else
        cout << "Yip Yip, you're a teenager!!!" << endl;
    return 0;
}
