#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int main() {
    Item a[] = {{60,10},{100,20},{120,30}};
    int n = 3, W = 50;

    sort(a, a + n, cmp);

    double total = 0;

    for (int i = 0; i < n; i++) {
        if (W >= a[i].weight) {
            total += a[i].value;
            W -= a[i].weight;
        } else {
            total += (double)a[i].value / a[i].weight * W;
            break;
        }
    }

    cout << "Max value: " << total;
}