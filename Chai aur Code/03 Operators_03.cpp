#include <iostream>
#include <string>

using namespace std ;

int main (){

    int cups ; 
    string student ;


    cout << "Enter the no of Tea cups you want : " << endl ;
    cin >> cups ;
    cout << " Are you a student ??" << endl;
    cin >> student ;

    cout << (
        ( student == "yes") ||( cups >06= 15) ? "You are eligible for discount " : "Sorry,You are not eligible for discount " 
    ) << endl; 


    return 0;
}