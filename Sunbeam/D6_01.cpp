#include<iostream>

using namespace std;

int gcd( int a , int b ){

while (b != 0){
    int temp = a % b; 
    a = b ;
    b = temp;
    }
    cout << "The GCD is :" << a << endl;
    return 0;

}

int main (){

    int a , b ;

    cout << "Enter the frist number :"<< endl;
    cin >> a;
    cout << "Enter the second number :"<< endl;
    cin >> b;

    gcd(a,b);
}