#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4,5,6};
    int n = 3;
    int size = 6;

    for (int i = 0; i < n; i++) {
        int last = arr[size - 1];  

        for (int j = size - 1; j > 0; j--) {
            arr[j] = arr[j - 1];  
        }

        arr[0] = last;  
    }

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}
