#include <iostream>
#include <cmath>
using namespace std;



int isPrime(int n ){
     if (n <= 1) {
        cout << "The number is not Prime";
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << "The number is not Prime";
            return 0;
        }
    }

    cout << "The number is Prime";
}
int main() {
    int n;
    cout << "Enter a number to check it it is prime or not :"<< endl;
    cin >> n;

   isPrime(n);
    return 0;
}
