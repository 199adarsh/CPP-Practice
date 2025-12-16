#include <iostream>

using namespace std ;

int main (){

    int bags;
    
    cout << "Enter no of Tea Bags you have : " << endl;
    cin >> bags;
    
    if (bags < 10 ) 
        bags += 5 ;

    cout << "Total bags will get is : " << bags << endl;

    
    return 0;
}