#include<iostream>
#include <string>

using namespace std;
struct ddmm {
   
    int dd;
    int mm;
    int yy;
    

      void accept() {
       cout << "\nAccept Date\n" << endl;
        cout << "Date :" << endl;
        cin >> dd;
        cout << "Month :" << endl;
        cin >> mm;
        cout << "Year :" << endl;
        cin >> yy;
        if ((dd < 1 || dd > 31) || (mm < 1 || mm > 12) || (yy < 1900)) {
            cout << "Invalid date input" << endl;
        } else {
            cout << "Date accepted" << endl;
        }
    }
    
    void print() {
        cout << "Date :" << dd ;
        cout << "Month :" << mm ;
        cout << "Year :" << yy ;
        cout << "\n" << endl;
        isLeap();
    
    }
    void init() {
        dd = 01;
        mm = 01;
        yy = 2001;
    }

    bool isLeap(){

        if ((yy%4==0 && yy % 100!=0) || (yy % 400 == 0)) {
        cout <<"The year is leap year"<< endl;
        return true;
        }
        else {
        cout <<"The year is not a leap year"<< endl;
        return false;
        }
    }
};

int main() {
  ddmm date;

    int choise ;
        cout <<  "Enter your choise \n1. Print \n2. Accept \n3.Init \n4.End \n\n" << endl;
    cin >> choise;
    
    while (choise != 4){
    switch (choise)
    {
    case 1:
         date.print();
        break;
    case 2: date.accept();
        break;
    case 3:date.init();
        break;
    case 4: break;
    default:
        cout << "Enter valid option"<< endl;
    }
    cout <<  "Enter your choise \n1. Print \n2. Accept \n3.Init \n4.End" << endl;
    cin >> choise;
}
   
   

    return 0;
}
