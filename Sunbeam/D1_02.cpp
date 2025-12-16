#include <iostream>

using namespace std ;

double e_length(double length, double Tm, double Bm){


    length = length - (Tm + Bm )  ; 

return length ;
}

int main (){

double length , width , Point, Tm , Bm , Lm , Rm , Elength, Ewidth , LineW , LineL ;

cout << "Enter the length of paper :"<< endl;
cin >>  length ;

cout << "Enter width length of paper :"<< endl;
cin >> width ;

cout << "Enter the Top Margin of paper :"<< endl;
cin >> Tm;

cout << "Enter the Bottom Margin of paper :"<< endl;
cin >> Bm ;

cout << "Enter the Right Margin of paper :"<< endl;
cin >> Rm ;

cout << "Enter the Left Margin of paper :"<< endl;
cin >> Lm ;

cout << "Enter the Point size :"<< endl;
cin >> Point ;

Elength = e_length(length, Tm, Bm);  
cout << "The ELength is :" << Elength << endl;


Ewidth = width - (Rm + Lm ) ; 
cout << "The Ewidth is :" << Ewidth << endl;

LineL = ((Elength * 72) / Point) ; 
cout << "The line length is :" << LineL << endl;

LineL = (Elength * 72) / (Point * 2); 
cout << "The number of lines is :" << LineL << endl;


LineW = (Ewidth * 72) / Point; 
cout << "The points width is :" << LineW << endl;


return 0;


}