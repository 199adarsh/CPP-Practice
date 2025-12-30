#ifndef DATE_H  
#define DATE_H

#include <string>
using namespace std;

class Date {
    private:
        int date;
        int month;
        int year;

    public:
        Date(int d , int m , int y );
        void initDate();
        void acceptDate();
        void displayDate();
        bool isLeap(int year);

};

#endif 