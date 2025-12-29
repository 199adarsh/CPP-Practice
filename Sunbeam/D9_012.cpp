#include "D9_011.h"
#include <iostream>
using namespace std;

Date::Date(int d, int m, int y) {
    date = d;
    month = m;
    year = y;
}

void Date::initDate() {
    date = 1;
    month = 1;
    year = 2001;
}

void Date::acceptDate() {
    cout << "Enter date: ";
    cin >> date;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
}

void Date::displayDate() {
    cout << "Date: " << date << endl;
    cout << "Month: " << month << endl;
    cout << "Year: " << year << endl;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << "Leap year" << endl;
    } else {
        cout << "Not a leap year" << endl;
    }
}

int main() {
    Date d1(1, 1, 2001);
    d1.displayDate();

    Date d2(01,02,2001);
    d2.acceptDate();
    d2.displayDate();

    return 0;
}