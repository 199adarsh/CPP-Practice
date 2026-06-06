#include <iostream>
using namespace std;

int main() {
    int a[] = {1,3,20,4,1,0};
    int n = 6;

    int l = 0, r = n - 1;

    while (l < r) { // search until left is less than right 
        int mid = (l + r) / 2;  // divide the search space 

        if (a[mid] < a[mid + 1])
            l = mid + 1;            // if mid is less than mid+1 then left will mid+1
        else
            r = mid;        // else assign mid as right 
    }

    cout << "Peak index: " << l;
}