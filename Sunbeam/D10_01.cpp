#include <iostream>
#include <string>
using namespace std;

class Array {
    int n;
    double* arr = new double[n];
public: 

    Array (){
        cout << "Class Array : Constructor called \n" << endl;
    }

    void acceptRecord(){
        cout << "Enter the size of Array \n" << endl;
        cin >> n ;
        for (int i = 0; i < n ; i++){
            cout << "Enter the " << i << " Element of Array : ";
            cin >> arr[i];

        } 

    }


    void displayRecord(){
        cout << "Printing the Array : " << endl;
        for (int i = 0 ; i < n ; i++){

            cout << i << " Element of array : " << arr[i] << endl;

        }

    }

    void linerSearch(){
        int target;
        cout << "Enter the element you want to search : " ;
        cin >> target ;
        for (int i = 0; i < n ; i++){
            if (arr[i] == target) {
                cout << target << " Found at index " << i << endl; 
            }
        }
    }
     
    ~Array(){
        cout << "Class Array : Destructor called \n" << endl;
    }


};


int main(){

    Array a1;
    cout << "\nAccepting user input : " << endl;
    a1.acceptRecord();
    cout << "\nDisplaying user input : " << endl;
    a1.displayRecord();
    cout << "\nLinear Search: " << endl;
    a1.linerSearch();

    cout << "Calling Copy Constructor :" << endl;
    Array a4 = a1;
    a4.displayRecord();
    return 0;
}