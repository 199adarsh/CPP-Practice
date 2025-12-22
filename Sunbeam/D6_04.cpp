#include <iostream>

using namespace std ;

int main (){

    int arr[] = {1,2,3,4,5};
    int n ;
    cout << "Enter n"<< endl;
    cin >> n;
    for (int i=0 ; i<=4 ; i++){

        for (int j = 4; j>n; j--){

        int temp = arr[i]; 
        arr[i] = arr[j] ;
        arr[j] = temp;


        }
    }

    for(int i=0 ; i<=4; i++){

        cout <<arr[i];
    }

}

