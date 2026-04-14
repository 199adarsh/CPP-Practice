#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int temp[high];   // simple fixed array
    int i = low, j = mid + 1, tempL = low;



    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])    // compare both strings frist element and copy the lesser one 
            temp[tempL++] = arr[i++];
        else
            temp[tempL++] = arr[j++];
    }



    while (i <= mid)    // if some elements remaning copy them 
        temp[tempL++] = arr[i++];

    while (j <= high)  // if some elements remaning copy them 
        temp[tempL++] = arr[j++];



    for (int x = low; x <= high; x++)   // copy the temp array back to the main array 
        arr[x] = temp[x];
}







void mergeSort(int arr[], int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}