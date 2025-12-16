#include<iostream>
#include <string>

using namespace std ;

int main () {

    int time ; 

    cout << "What's the time now (in 24hr format):" << endl ;
    cin >> time ;

    cout <<( (time >= 8 && time <= 12) ? "The shop is open Now " : (time >= 13 && time <= 24) ? "The shop is closed " : "Error !")<<  endl;
    
    return 0 ;
 

}
 