#include <iostream>
using namespace std;

void merge(int a[], int left, int mid, int right) {
    int temp[100], i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {

        if (a[i] <= a[j]) { temp[k] = a[i]; k++,i++; }
        
            else {temp[k] = a[j];   k++,j++;}
    }

    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];

    for (int x = left; x <= right; x++) a[x] = temp[x];
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        
        merge(a, left, mid, right);
    }
}

int main() {
    int a[] = {38,27,43,3,9,82,10};
    int n = 7;

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}