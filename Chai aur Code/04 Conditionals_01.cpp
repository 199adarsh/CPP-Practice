#include<iostream>
#include <string>

using namespace std ;

int main () {

    string chai ; 

    cout << "Enter your preffered chai :" << endl ;
    getline(cin, chai);

    cout <<( (chai == "Leamon Tea" ) ? "Your order was: Leamon tea" : "Your order was ")<<  endl;
    
    return 0 ;
 

}
 