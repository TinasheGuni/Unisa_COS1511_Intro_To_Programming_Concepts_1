#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const float FIRSTCLASSFEE = 1920.00;
const float ECONOMYCLASSFEE = 1600.00;
const string TRAVELFROM = "Johannesburg";
const string TRAVELTO = "Cape Town";

int displayTravelTimes()
{
    int optionP;

    cout << "\nThe Available travel times for FLIGHTS are as follows." << endl;
    cout << "\tDepart\t\tArrive" << endl;
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

void displaySeats(string firstClassSeatsP[4][6],
                  string economyClassSeatsP[5][6],
                  string& selectedSeatP,
                  string& selectedClassP,
                  int optionP){
    string departure;
    bool alreadyBooked = false;
    char selClass;
    // use switch statements
    switch(optionP){
    case 1:
        departure = "07:00";
        break;
    case 2:
        departure = "09:00";
        break;
    case 3:
        departure = "11:00";
        break;
    case 4:
        departure = "13:00";
        break;
    case 5:
        departure = "15:00";
        break;
    default:
        cout << "System Error!!!";
        break;
    }

    cout << "Available seats for " << departure << " are as follows..." << endl;
    cout << "\nFirst Class (R"<<FIRSTCLASSFEE<<")" << endl;

    //First Class
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++) {
            if (j == 3){
                cout << "|----|" << firstClassSeatsP[i][j];
            } else {
                cout << "|" << firstClassSeatsP[i][j];
            }
        }
        cout << "|" << endl;
    }

    // Economy Class
    cout << "\nEconomy Class (R"<< ECONOMYCLASSFEE<<")" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (j == 3) {
                cout << "|----|" << economyClassSeatsP[i][j];
            }else {
                cout << "|" << economyClassSeatsP[i][j];
            }
        }
        cout << "|" << endl;
    }
    cout << "Choose your Class (E - Economy, F - First Class)\n";
    cin >> selectedClassP;

    if (selectedClassP == "E" || selectedClassP == "e") {
        cout << "Choose your seat number (e.g: E2)" << endl;
        cin >> selectedSeatP;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                if (economyClassSeatsP[i][j] == selectedSeatP) {
                    if (economyClassSeatsP[i][j] == "**") {
                        alreadyBooked = true;
                    }else {
                        economyClassSeatsP[i][j] = "**";
                        selectedClassP = "Economy Class";
                    }
                }
            }
        }
    }
    else if (selectedClassP == "F" || selectedClassP == "f") {
        cout << "Choose your seat number (e.g: F3)" << endl;
        cin >> selectedSeatP;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 6; j++) {
                if (firstClassSeatsP[i][j] == selectedSeatP) {
                    if (firstClassSeatsP[i][j] == "**") {
                        alreadyBooked = true;
                    }else {
                        firstClassSeatsP[i][j] = "**";
                        selectedClassP = "First Class";
                    }
                }
            }
        }
    }

    if (!(selectedClassP == "Economy Class" || selectedClassP == "First Class")) {
        if (alreadyBooked == true) {
            cout << "Selected seat is already booked" << endl;
        }else {
            cout << "Seat does not exist!!!" << endl;
        }
    }
}

void displayTicket(string passangerNameP,
                   string selectedClassP,
                   string selectedSeatP,
                   string departureTimeP,
                   string arrivalTimeP)
{
    cout << "*******************************************************************************************************\n";
    cout << "\t\t\tTravel Ticket for FLIGHT\n";
    cout << "*******************************************************************************************************\n";
    cout << "\tName\t\t:\t" << passangerNameP << "\tTravel Ticket class \t:" << selectedClassP << endl;
    cout << "\t\t\t\t\t\tSeat No\t\t:" << selectedSeatP<< endl;
    cout << "Departure\t:\t" << TRAVELFROM << "\tDeparture Time \t\t:" << departureTimeP << endl;
    cout << "\t\t\t\t\t\tSeat No\t\t:" << selectedSeatP<< endl;
}

int main()
{
    string passangerName;
    int option;
    char answer;
    string selectedSeat, selectedClass, departureTime, arrivalTime;

    string firstClassSeats[4][6] =
    {
        {"A1", "A2", "A3", "A4","A5",},
        {"B1", "B2", "B3", "B4","B5",},
        {"C1", "C2", "C3", "C4","C5",},
        {"D1", "D2", "D3", "D4","D5",}
    };

    string economyClassSeats[5][6] =
    {
        {"E1", "E2", "E3", "E4","E5",},
        {"F1", "F2", "F3", "F4","F5",},
        {"G1", "G2", "G3", "G4","G5",},
        {"H1", "H2", "H3", "H4","H5",},
        {"I1", "I2", "I3", "I4","I5",}
    };

    // Totals
    int tot700 = 0, tot900 = 0, tot1100 = 0,tot1300 = 0,tot1500 = 0;

    cout << "Welcome to COS1511 Flight Booking System, " << endl;
    cout << "\nEnter your Full Name: ";
    getline(cin, passangerName);

    do {
        option = displayTravelTimes();
        displaySeats(firstClassSeats, economyClassSeats, selectedSeat, selectedClass, option);

        if (selectedClass == "Economy Class" || selectedClass == "First Class") {
            switch(option) {
            case 1:
                departureTime = "07:00";
                arrivalTime = "09:30";
                tot700++;
                break;
            case 2:
                departureTime = "07:00";
                arrivalTime = "09:30";
                tot900++;
                break;
            case 3:
                departureTime = "07:00";
                arrivalTime = "09:30";
                tot1100++;
                break;
            case 4:
                departureTime = "07:00";
                arrivalTime = "09:30";
                tot1300++;
                break;
            case 5:
                departureTime = "07:00";
                arrivalTime = "09:30";
                tot1500++;
                break;
            default:
                cout << "System Error!!!";
                break;
            }
            // Non receiving function call
            displayTicket(passangerName, selectedClass, selectedSeat, departureTime, arrivalTime);
        }

        cout << "\nWould you like to make another Booking? (Y/N)" << endl;
        cin >> answer;
    } while (toupper(answer) == 'Y');

    return 0;
}
