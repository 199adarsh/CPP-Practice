#include <iostream>

using namespace std;
inline double CtoF( double c){
cout << "Celsius to Fahrenheit :" << (c*9/5)+32 << endl;
}

inline double FtoC( double f){
cout << "Fahrenheit to Celsius  :" << (f-32)/1.8 << endl;
}

inline double myMIn (int a , int b){
 cout <<( (a>b) ? "A is grater than B " : (b>a) ? "B is grater than A " : (a==b)?" Both values are same!" : "/n")<<  endl;
}

inline double simpleIntrest (double p , double r , double t ){
cout << "The simple intrest is :" << (p*r*t)/100<< endl;
}


int main() {
    int choice;
    double value1, value2, value3;
    
    cout << "1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Find Minimum\n4. Simple Interest\n";
    cin >> choice;
    
    switch(choice) {
        case 1:
            cout << "Enter Celsius: ";
            cin >> value1;
            CtoF(value1);
            break;
        case 2:
            cout << "Enter Fahrenheit: ";
            cin >> value1;
            FtoC(value1);
            break;
        case 3:
            cout << "Enter 1st number: ";
            cin >> value1 ;
            cout << "Enter 2nd number: ";
            cin>>value2;
            myMIn(value1, value2);
            break;
        case 4:
            cout << "Enter Principle: ";
            cin >> value1 ;
            cout << "Enter Rate: ";
            cin>>value2;
            cout << "Enter Time: ";
            cin>>value2;
            simpleIntrest(value1, value2, value3);
            break;
        default:
            cout << "Invalid choice\n";
    }
    
    return 0;
}

