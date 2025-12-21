#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int num = 1;

    for (int i = 1; i <= n; i++) {


        for (int j = 0; j < n - i; j++)
            cout << " ";

        for (int k = 1; k <= i; k++) {
            cout << num<< " ";
            num++;
            if (num == 10) num = 0; 
        }

        cout << endl;
    }
    return 0;
}
