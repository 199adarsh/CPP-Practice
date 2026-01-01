#include<iostream>
#include <string>

using namespace std;
struct ddmm {
   
    int dd;
    int mm;
    int yy;
    
    ddmm(int d, int m, int y) {
        dd = d;
        mm = m;
        yy = y;
    }
    
    void accept() {
        cout << "Accept Date" << endl;
        cout << "Date :" << endl;
        cin >> dd;
        cout << "Month :" << endl;
        cin >> mm;
        cout << "Year :" << endl;
        cin >> yy;
    }
    
    void print() {
        cout << "Date :" << dd << endl;
        cout << "Month :" << mm << endl;
        cout << "Year :" << yy << endl;
    }
    void init() {
        dd = 01;
        mm = 01;
        yy = 2001;
    }
};

int main() {
    ddmm date(10, 8, 2008);

    int choise ;
    cout <<  "Enter your choise \n1. Print \n2. Accept \n3.Init" << endl;
    cin >> choise;
    switch (choise)
    {
    case 1:
         date.print();
        break;
    case 2: date.accept();
        break;
    case 3:date.init();
        break;
        
    
    default:
        break;
    }
   
   

    return 0;
}
