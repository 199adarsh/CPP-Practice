#include <iostream>
using namespace std;

int main() {
    int a[] = {1,3,20,4,1,0};
    int n = 6;

    int l = 0, r = n - 1;

    while (l < r) {
        int mid = (l + r) / 2;

        if (a[mid] < a[mid + 1])
            l = mid + 1;
        else
            r = mid;
    }

    cout << "Peak index: " << l;
}