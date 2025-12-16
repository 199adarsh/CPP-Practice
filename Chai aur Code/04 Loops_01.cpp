#include<iostream>
#include <string>

using namespace std ;

int main () {

   int tea ;

   cout << "How meny cups of tea do you want :" << endl;
   cin >> tea;
   cout << "____________________________________________ "<<endl;

   while (tea >= 1){
        tea--;
        cout << "| 1 Cup Tea is made |\t "<< tea<<": Cups Remaining |"<< endl;
   }

    cout << "____________________________________________ "<<endl;
    cout << "Tea's are over"<< endl;
   
   

    return 0 ;
 

}
 