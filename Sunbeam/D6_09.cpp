#include <iostream>
using namespace std;

int sum_ar(int arr[], int n) {
    // Base case
    if (n == 0)
        return 0;

    return arr[n - 1] + sum_ar(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Sum = " << sum_ar(arr, n) << endl;
    return 0;
}
