#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of Array: ";
    cin >> n;

    double* arr = new double[n];     

    for (int i = 0; i < n; i++){
        cout << "Enter the " <<i << " Element of Array :";
        cin >> *(arr + i);
    }


    for (int i = 0; i < n; i++){
        cout << *(arr + i)<< endl;}

        

    delete[] arr;     
    return 0;        
}