#include<iostream>
#include <string>

using namespace std ;

int main () {

   int tea;
   
   cout <<"Tea Menue" << endl;
   cout <<"1. Normal Tea" << endl;
   cout <<"2. Lemon Tea " << endl;
   cout <<"3. Black Tea " << endl;
   cout <<"Which Tea do you want (Enter number) : " << endl;
   cin >> tea ;

   switch (tea)
   {
    case 1: cout << "Normal Tea : 20rs" << endl; 
        break;
   
    case 2: cout << "Lemon Tea : 25rs" << endl;
        break;

    case 3: cout << "Black Tea : 15rs" << endl;
        break;

    default: cout << "Invalid option, Try again " << endl;
    break;
   }
   
    
   

    return 0 ;
 

}
 