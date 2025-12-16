#include <iostream>

using namespace std ;

int main (){

    int total;
    float cup;
    float price ; 

    cout << "Hello,\t How meny cup of tea you want ?? "<< endl ; 
    cin >> cup;
    cout << "Enter the price of tea :" << endl;
    cin >> price ;
    
    total = price*cup ; 
    if (total >= 250)
            total = (total*0.95);

    cout <<"Your total is : " << total << " for " << cup <<" of tea" << endl;  
    

    return 0;
}