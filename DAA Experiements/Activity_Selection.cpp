#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    pair<int,int> a[] = {{3,1},{5,2},{6,4},{8,6}};
    int n = 4;

    sort(begin(a), end(a));  

    int count = 1;
    int lastEnd = a[0].first;

    for (int i = 1; i < n; i++) {
        if (a[i].second >= lastEnd) {
            count++;
            lastEnd = a[i].first;
        }
    }

    cout << count;
}