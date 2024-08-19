#include <iostream>
#include <string>

using namespace std;

int displayTravelTimes()
{
    int optionP;

    cout << "\nThe Available travel times for FLIGHTS are as follows." << endl;
    cout << "\tDepart\tArrive" << endl;
    cout << "1.\t07:00\t\t09:30" << endl;
    cout << "2.\t09:00\t\t11:30" << endl;
    cout << "3.\t11:00\t\t13:30" << endl;
    cout << "4.\t13:00\t\t15:30" << endl;
    cout << "5.\t15:00\t\t17:30" << endl;

    cout << "Choose the time by entering the option from the displayed list: " << endl;
    cin >> optionP;
    while (optionP < 1 || optionP > 5) {
        cout << "Please choose from option 1 - 5!!!" << endl;
        cin >> optionP;
    }
    return optionP;
}

int main()
{
    string passangerName;
    int option;
    char answer;
    string selectedSeat, selectedClass, departureTime, arrivalTime;

    cout << "Welcome to COS1511 Flight Booking System, " << endl;
    cout << "\nEnter your Full Name: ";
    getline(cin, passangerName);

    do {
        option = displayTravelTimes();

        cout << "\nWould you like to make another Booking? (Y/N)" << endl;
        cin >> answer;
    } while (answer == 'Y' || answer == 'y');

    return 0;
}
