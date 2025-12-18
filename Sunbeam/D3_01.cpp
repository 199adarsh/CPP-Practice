#include <iostream>

using namespace std;

int main() {

    int number;

    cout << "Enter a five digit number : ";

    cin >> number;

    

    int digits[5];

    int temp = number;

    

    for (int i = 4; i >= 0; i--) {

        digits[i] = temp % 10;

        temp /= 10;

    }

    

    cout << "Added number is: ";

    for (int i = 0; i < 5; i++) {

        digits[i] = (digits[i] + 1) % 10;

        cout << digits[i];

    }

    cout << endl;

    

    return 0;

}


