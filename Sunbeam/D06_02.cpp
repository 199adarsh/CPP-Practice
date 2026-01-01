#include<iostream>

using namespace std;

int gcd( int a , int b ){

while (b != 0){
    int temp = a % b; 
    a = b ;
    b = temp;
    }
    cout << "The GCD is :" << a << endl;
    return a;

}

int lcm(int a, int b , int Gcd){

    cout << "The LCM is :" << ((a*b)/Gcd) << endl;
}

int main (){

    int a , b ;

    cout << "Enter the frist number :"<< endl;
    cin >> a;
    cout << "Enter the second number :"<< endl;
    cin >> b;

    int Gcd = gcd(a,b);
    lcm(a,b , Gcd);

}