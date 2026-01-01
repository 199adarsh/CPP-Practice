#include <iostream>
using namespace std;


int gcd_recursive(int a, int b) {
    if (b == 0)
        return a;
    return gcd_recursive(b, a % b);
}

int main() {
    int a = 1071, b = 462;
    cout << "GCD : "<< gcd_recursive(a, b) << endl;
    return 0;
}
