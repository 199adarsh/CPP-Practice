#include <iostream>
using namespace std;



class time {
private:
    int sec, min, hour; 


public:

    time() {
        sec = 0;
        min = 0;
        hour = 0;
        cout << "Parameterless constructor is called\n";
    }

    time(int sec1) {
        sec = sec1;
        min = 0;
        hour = 0;
        cout << "1 Parameter const is called\nSec: " << sec << endl;
    }

    time(int sec1, int min1) {
        sec = sec1;
        min = min1;
        hour = 0;
        cout << "2 Parameter const is called\nSec: " << sec << " Min: " << min << endl;
    }

    time(int sec1, int min1, int hrs1) {
        sec = sec1;
        min = min1;
        hour = hrs1;
        cout << "3 Parameter const is called\nSec: " << sec << "\nMin: " << min << "\nHour: " << hour << endl;
    }

    int initTime() {
        sec = 1;
        min = 10;
        hour = 10;
        cout << "\n\nDate initialized\n\n";
        return 0;
    }

    int acceptTime() {
        cout << "Enter Seconds: ";
        cin >> sec;
        cout << "Enter Minutes: ";
        cin >> min;
        cout << "Enter Hours: ";
        cin >> hour;
        return 0;
    }

    int displayTime() {
        cout << "Seconds: " << sec << endl;
        cout << "Minutes: " << min << endl;
        cout << "Hours: " << hour << endl;
        return 0;
    }

    int getHour() {
        return hour;
    }

    int getMin() {
        return min;
    }

    int getSec() {
        return sec;
    }

    void setHour(int hrs) {
        hour = hrs;
    }

    void setMin(int min1) {
        min = min1;
    }

    void setSec(int sec1) {
        sec = sec1;
    }

    ~time() {
        cout << "Destructor called\n";
    }
};

int main() {
    time date;
    date.initTime();
    date.acceptTime();
    date.displayTime();


    cout << "Get min :" << endl;
    cout << date.getMin() <<endl;
    date.setSec(15);
    return 0;
}
