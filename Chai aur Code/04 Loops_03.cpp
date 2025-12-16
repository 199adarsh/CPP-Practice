#include<iostream>
#include <string>

using namespace std ;

int main () {

   string tea ;

   while(true){

    cout<<"Do you want more tea ? (Type \"Stop \" to exit )" << endl;
    cin >>tea;

    if(tea == "stop") break;

    cout<<"1 Cup of tea is served \n"<<endl;

   }

   cout << "Exited the loop"<<endl;

    return 0 ;
 

}
 