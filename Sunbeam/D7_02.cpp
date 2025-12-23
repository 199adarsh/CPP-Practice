#include <iostream>
using namespace std;

class date {
private:
    int day, month, year;

public:
    date() {
        day = 01;
        month = 01;
        year = 2001;
        cout << "Parameterless constructor is called\n";
    }


    int initdate() {
        day = 01;
        month = 10;
        year = 2001;
        cout << "\n\nDate initialized\n\n";
        return 0;
    }

    int acceptdate() {
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
        return 0;
    }

    int displaydate() {
        cout << "Day: " << day << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
        if ((year%4==0 && year % 100!=0) || (year % 400 == 0)) {
        cout <<"The year is leap year"<< endl;
        }
        else{
            cout << "Year is not leap year"<< endl;
        }
        return 0;
    }

    int getyear() {
        return year;
    }

    int getmonth() {
        return month;
    }

    int getday() {
        return day;
    }

    void setyear(int hrs) {
        year = hrs;
    }

    void setmonth(int month1) {
        month = month1;
    }

    void setday(int day1) {
        day = day1;
    }

    ~date() {
        cout << "Destructor called\n";
    }
};

int main() {
    date date;

    int choise ;
    while (choise !=4)
    {
        
    
    
    cout <<  "Enter your choise \n1. Init \n2. Accept \n3.Display \n4. End " << endl;
    cout << "\n" ;
    cin >> choise;

    switch (choise)
    {
    case 1:
        date.initdate();
        break;
    case 2: date.acceptdate();
        break;
    case 3:date.displaydate();
        break;
        
    case 4 : break;
    default:
        cout << "Invalid Option";
    }

    }
    return 0;
}
