#include <iostream>
using namespace std;

int main()
{
    int num, temp, digit, sum;

    cout << "Armstrong numbers from 1 to 500 are:" << endl;

    for (num = 1; num <= 500; num++) {
        temp = num;
        sum = 0;

        
        while (temp > 0) {
            digit = temp % 10;          
            sum = sum + (digit * digit * digit);
            temp = temp / 10;           
        }

        
        if (sum == num) {
            cout << num << endl;
        }
    }

    return 0;
}
