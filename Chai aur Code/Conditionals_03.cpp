#include<iostream>
#include <string>

using namespace std ;

int main () {

   int cups ;  

   cout << "How much tea cups do you want :" << endl; 
   cin >> cups ;

   if (cups <= 9) cout << "You are not eligible for discount !"  << endl ;

   else if (cups >=10 && cups <= 19 ) cout << "You are eligible for 10 \% discount !" << endl;

   else if (cups >=20) cout << "You are eligible for 20 \% discount !" << endl;

    return 0 ;
 

}
 