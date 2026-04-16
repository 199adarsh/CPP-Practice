#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int temp[100], i = l, j = m + 1, k = l;

    while (i <= m && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }

    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (int x = l; x <= r; x++) a[x] = temp[x];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[] = {38,27,43,3,9,82,10};
    int n = 7;

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}