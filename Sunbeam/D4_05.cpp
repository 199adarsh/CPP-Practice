#include <iostream>
using namespace std;

int add(int a , int b , int c , int d){
    return (a+b+c+d);
}

int main (){
    int a, b,c,d;
    cout << "Enter 1st number :" << endl;
    cin >> a; 
    cout << "Enter 2nd number :" << endl;
    cin >> b;
    cout << "Enter 3rd number :" << endl;
    cin >> c;
    cout << "Enter 4th number :" << endl;
    cin >> d;
    
    int total = add(a , b , c , d);
    cout << "Your total is :"<<total << endl;
    return 0;
}